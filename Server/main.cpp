#include "Network.h"
#include "mysqlConnector.h"

// 数据处理
// 并发分支
void dataProcess(NW_SOCKET client, mysqlConnector &mysql)
{
    while(1)
    {
        NW_Package data;
        if(!NW_Recv(client, data)) {
            std::cout << "接收数据失败" << std::endl;
            break;
        }
        
        // 打印
        std::cout << "发送备份组列表" << std::endl;

        // 处理数据
        if(data.pa_action == NW_AC_GET&&data.pa_context==std::string("getbackuplist"))
        {
            // 获取备份列表
            std::string sql = "select * from lib;";
            if(mysql.query(sql.c_str()))
            {
                std::vector<std::vector<std::string>> result = mysql.getResult();
                // 发送备份列表
                NW_Package data;
                data.pa_number = 1;
                data.pa_action = NW_AC_MSG;
                data.pa_type   = NW_DT_MSG;
                data.pa_status = NW_DS_ST;
                data.pa_size = result.size();
                for(int i = 0; i < result.size(); i++)
                {
                    data.pa_number = i + 1;
                    strcpy(data.pa_context, result[i][1].c_str());
                    if(i == result.size() - 1)data.pa_status = NW_DS_FH;
                    if(!NW_Send(client, data)) {
                        std::cout << "发送备份列表失败" << std::endl;
                        break;
                    }
                    data.pa_status = NW_DS_TT;
                }
            }
        }
        else{
            std::cout << "未知数据" << std::endl;
            break;
        }
    }
}

int main()
{
    // 创建一个TCP服务器
    NW_SOCKET server = NW_TcpServer("192.168.56.133", 8899);
    if(!server.status)
    {
        std::cout << "服务器启动失败!" << std::endl;
        return -1;
    }
    std::cout << "服务器启动成功!" << std::endl;
    // 创建数据库连接对象
    mysqlConnector &mysql = mysqlConnector::getInstance();

    // 连接数据库
    if(!mysql.connect("192.168.56.133", "winuser", "123456","BACKUPLIB"))
    {
        std::cout << "数据库连接失败!" << std::endl;
        NW_ShutDown(server);
        return -1;
    }
    std::cout << "数据库连接成功!" << std::endl;

    // 等待客户端连接
    NW_SOCKET client;
    while(1)
    {
        client = NW_Accept(server);
        if(client == NW_INVALID)continue;

        std::cout << "客户端连接成功!" << std::endl;

        // 接收客户端数据
        int retryCount = 0;
        const int maxRetries = 3;
        
        while(true)
        {
            // 接收客户端用户名和口令
            NW_Package data;
            if(!NW_Recv(client, data)) {
                std::cout << "接收用户名失败" << std::endl;
                break;
            }

            // 解析数据
            std::vector<std::string> result = NW_Parse(data.pa_context);

            std::string user_name = result[0];
            std::string user_pswd = result[1];

            std::cout << "用户名: " << user_name << " 密码: " << user_pswd << std::endl;

            // 获取数据库中的查询结果
            std::string sql = "select * from user where user_name = '" + user_name + "' and user_pswd = '" + user_pswd + "';";
            if(mysql.query(sql.c_str()))
            {
                std::vector<std::vector<std::string>> result = mysql.getResult();
                // 发送查询结果
                NW_Package data;
                data.pa_action = NW_AC_LOGIN;
                data.pa_type = NW_DT_MSG;
                data.pa_status = NW_DS_TT;
                if(result.size() == 1)
                {
                    data.pa_size = strlen("success");
                    strcpy(data.pa_context,"success");

                    // 回复客户端的查询结果
                    if(!NW_Send(client, data)) {
                        std::cout << "发送响应失败" << std::endl;
                        break;
                    }

                    // 数据处理
                    dataProcess(client, mysql);
                    break;
                }
                else
                {
                    data.pa_size = strlen("failed");;
                    strcpy(data.pa_context,"failed");

                    // 回复客户端的查询结果
                    if(!NW_Send(client, data)) {
                        std::cout << "发送响应失败" << std::endl;
                        break;
                    }
                    break;
                }       
            }
        }
        NW_ShutDown(client);
        std::cout << "客户端断开连接!" << std::endl;
    }
    
    NW_ShutDown(server);
    return 0;
}

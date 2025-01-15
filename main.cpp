#include "FileTransmission.h"
#include "mysqlConnector.h"
int main()
{
    // 创建一个TCP服务器
    FT_SOCKET server = FT_TcpServer("192.168.56.133", 8899);
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
        FT_ShutDown(server);
        return -1;
    }
    std::cout << "数据库连接成功!" << std::endl;

    // 等待客户端连接
    FT_SOCKET client;
    while(1)
    {
        client = FT_Accept(server);
        if(client.socketId != FT_INVALID)break;
    }
    std::cout << "客户端连接成功!" << std::endl;
    // 接收客户端数据
    while(1)
    {
//----------------------------验证用户开始--------------------------------------
        // 接收客户端用户名和口令
        FT_Package data;
        FT_Recv(client, data);
        std::string user_name = data.pa_context;
        std::cout << data.pa_context << std::endl;

        FT_Recv(client, data);
        std::string user_pswd = data.pa_context;
        std::cout << data.pa_context << std::endl;

        // 获取数据库中的查询结果
        std::string sql = "select * from user where user_name = '" + user_name + "' and user_pswd = '" + user_pswd + "';";
        if(mysql.query(sql.c_str()))
        {
            std::vector<std::vector<std::string>> result = mysql.getResult();
            // 发送查询结果
            FT_Package data;
            data.pa_action = FT_AC_MSG;
            data.pa_type = FT_DT_MSG;
            data.pa_status = FT_DS_TT;
            if(result.size() == 1)
            {
                data.pa_size = strlen("success");
                strcpy(data.pa_context,"success");
            }
            else
            {
                data.pa_size = strlen("failed");;
                strcpy(data.pa_context,"failed");
            }

            // 回复客户端的查询结果
            FT_Send(client, data);

//----------------------------验证用户结束--------------------------------------

//---------------------------获取数据库的记录开始--------------------------------------
    // 查询数据库中的记录
    sql = "select lib_name,lib_addr,lib_port from lib;";
    std::cout << sql << std::endl;
    // 执行sql语句
    if(mysql.query(sql.c_str()))
    {
        // 获取查询结果
        FT_Package data;
        data.pa_action = FT_AC_MSG;
        data.pa_type = FT_DT_MSG;
        data.pa_status = FT_DS_TT;
        std::vector<std::vector<std::string>> result = mysql.getResult();
        for(int i = 0; i < result.size(); i++)
        {
            data.pa_size = result.size();
            strcpy(data.pa_context,result[i][0].c_str());
            FT_Send(client, data);
            for(int j = 0; j < result[i].size(); j++)
                std::cout << result[i][j];
            std::cout << std::endl;
        }

        data.pa_size = strlen("end");
        strcpy(data.pa_context,"end");
        FT_Send(client, data);
    }
//---------------------------获取数据库的记录结束--------------------------------------


//----------------------------更新/插入新库的记录开始--------------------------------------
            // 获取客户端的操作
            data.clear();
            FT_Recv(client, data);

            // 备份库名字段数据
            std::string backUpLibName = data.pa_context;

            // 获取客户端的操作
            data.clear();
            FT_Recv(client, data);

            // 备份库地址字段数据
            std::string backUpLibAddr = data.pa_context;

            // 获取客户端的操作
            data.clear();
            FT_Recv(client, data);

            // 备份库端口字段数据
            std::string backUpLibPort = data.pa_context;

            // 执行数据库操作
            sql = "insert into lib(lib_name,lib_addr,lib_port) values('" + backUpLibName + "','" + backUpLibAddr + "'," + backUpLibPort + ");";
        
            std::cout << sql << std::endl;

            // 执行SQL语句
            if(mysql.query(sql.c_str()))
                std::cout << "插入成功!" << std::endl;
            else
                std::cout << "插入失败!" << std::endl;
//----------------------------更新/插入新库的记录结束--------------------------------------

            break;
        } 
    }
    FT_ShutDown(server);

    return 0;
}

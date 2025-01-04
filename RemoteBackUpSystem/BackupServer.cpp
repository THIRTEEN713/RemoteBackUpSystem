#include "FileTransmission.h"
#include "mysql.h"

int main()
{
    mysql_library_init(0,nullptr,nullptr);
    MYSQL *conn = mysql_init(nullptr);
    if(conn == nullptr)
    {
        std::cout << mysql_error(conn) << std::endl;
        return -1;
    }

    std::cout << "init success" << std::endl;
    if(mysql_real_connect(conn,"127.0.0.1","root","root",nullptr,3308,nullptr,0) == nullptr)
    {
        std::cout << mysql_error(conn) << std::endl;
        return -1;
    }

    std::cout << "connect success" << std::endl;
    // 创建一个TCP服务器
    FT_SOCKET sockid = FT_TcpServer();
    if(sockid.socketId == FT_INVALID)return -1;

    // 等待客户端连接
    FT_SOCKET clientSock;
    while(1)
    {
        clientSock = FT_Accept(sockid);
        if(clientSock.socketId == FT_INVALID)continue;
        break;
    }

    while(1)
    {
        // 从数据库中查询
        std::string sql = "SELECT id FROM user WHERE user_name=";


        // 接收
        FT_Package data;
        FT_Recv(clientSock,data);
        std::cout << data.pa_context << std::endl;

        sql += data.pa_context;

        FT_Recv(clientSock,data);
        std::cout << data.pa_context << std::endl;

        sql += "pswd="+std::string(data.pa_context);

        mysql_query(conn,sql.c_str());

        // 获取结果
        MYSQL_RES *result = mysql_store_result(conn);

        data.clear();
        data.pa_action = FT_AC_MSG;
        data.pa_type   = FT_DT_MSG;
        strcpy(data.pa_context,result->row_count?"success":"failed");
        FT_Send(clientSock,data);

        std::cout << "行号：" << __LINE__ << std::endl;

        mysql_free_result(result);

        mysql_close(conn);

        break;
    }

    FT_ShutDown(clientSock);
    FT_ShutDown(sockid);
    return 0;
}
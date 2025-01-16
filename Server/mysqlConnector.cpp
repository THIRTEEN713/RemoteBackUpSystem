#include "mysqlConnector.h"
#include <string.h>

mysqlConnector::mysqlConnector()
{
    // 初始化MySQL库
    mysql_library_init(0, NULL, NULL);

    // 初始化MySQL连接
    mysql = mysql_init(NULL);
}

mysqlConnector &mysqlConnector::getInstance()
{
    static mysqlConnector instance;

    // 返回静态实例
    return instance;
}

mysqlConnector::~mysqlConnector()
{
    // 关闭MySQL连接
    mysql_close(mysql);

    // 释放MySQL库
    mysql_library_end();
}

// 断开连接
bool mysqlConnector::connect(const char* host, const char* user, const char* password, const char* db)
{
    // 连接到MySQL数据库
    if (mysql_real_connect(mysql, host, user, password, db, 0, NULL, 0) == NULL)
        return false;
    return true;
}

// 执行SQL语句
bool mysqlConnector::query(const char* sql)
{
    // 执行SQL语句
    if (mysql_real_query(mysql, sql,strlen(sql)) != 0)
        return false;
    return true;
}

// 获取结果
std::vector<std::vector<std::string>> mysqlConnector::getResult()
{
    // 定义结果集
    std::vector<std::vector<std::string>> results;

    // 获取结果
    MYSQL_RES* res = mysql_store_result(mysql);

    // 拆分结果集
    while(MYSQL_ROW row = mysql_fetch_row(res))
    {
        // 获取列数
        unsigned int num_fields = mysql_num_fields(res);
        std::vector<std::string> row_results;
        for(unsigned int i = 0; i < num_fields; i++)
            row_results.push_back(row[i]);
        results.push_back(row_results);
    }
    return results;
}

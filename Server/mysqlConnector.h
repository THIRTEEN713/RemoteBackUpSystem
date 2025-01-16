#pragma once

#include "/usr/include/mysql/mysql.h"
#include <vector>
#include <string>

class mysqlConnector
{
private:
    mysqlConnector();
    mysqlConnector(const mysqlConnector&) = delete;
    mysqlConnector& operator=(const mysqlConnector&) = delete;

// 公开的API方法
public:
    // 获取mysqlConnector的实例
    static mysqlConnector &getInstance();

    ~mysqlConnector();

    // 连接到MySQL数据库 argc1:服务器地址 argc2:用户名 argc3:密码 argc4:数据库名
    bool connect(const char*, const char*, const char*, const char*);

    // 执行SQL语句 argc1:SQL语句
    bool query(const char*);

    // 获取查询结果 
    std::vector<std::vector<std::string>> getResult();

    // 断开连接 
    void close();

// 私有成员变量
private:
    MYSQL* mysql;
};

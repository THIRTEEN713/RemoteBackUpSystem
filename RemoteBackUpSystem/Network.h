#pragma once


// 这个文件传输的API组可以进行跨平台的开发

// 需要的头文件
#ifdef  __linux__ // 如果定义了LINUX宏
#ifndef _WIN32 // 没有定义WIN32宏,说明这个是在Linux平台使用
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define NW_INVALID -1
typedef int    NW_SOCK_ID;
#define NW_SOCKLEN socklen_t
#endif
#endif

#ifdef  _WIN32 // 如果定义了WIN32宏
#ifndef  __linux__ // 没有定义LINUX宏,说明这个是在Windows平台使用
#include <winsock2.h>
#include <windows.h>

#define NW_INVALID INVALID_SOCKET
typedef SOCKET NW_SOCK_ID;
#define NW_SOCKLEN int
#endif
#endif

#include <iostream>
#include <string.h>
#include <vector>
/*
文件传输的API组说明：
    包含数据封装：
        NW_SOCKET        套接字类型
        NW_INVALID       套接字错误
        NW_Action        网络数据的行为
        NW_DataType      网络数据的类型
        NW_DataStatus    网络数据包的状态
        NW_Package       网络数据包的封装
    包含函数封装：
        NW_TcpServer     获取一个Tcp的服务端套接字
        NW_TcpClient     获取一个Tcp的客户端套接字
        NW_UdpSocket     获取一个Udp的套接字
        NW_Accept        等待一个客户端连接
        NW_ShutDown      关闭一个网络通道
        NW_Send          通过指定的套接字发送一个网络数据包
        NW_Recv          通过指定的套接字获取一个网络数据包
*/

/*
网络通道的类型:
    NW_NIL (filetransmission_Invalid) 无效通道
        如果是无效通道，那么这个网络通道是一个不可用的网络通道
    NW_TCP (filetransmission_TCP) TCP通道
        如果是TCP通道，那么这个网络通道是一个采用流式数据的通道
    NW_UDP (filetransmission_UDP) UDP通道
        如果是UDP通道，那么这个网络通道是一个采用数据报的通道
*/
typedef enum{NW_NIL,NW_TCP,NW_UDP}NW_INET_TYPE;
// 网络通道类型
struct NW_SOCKET
{
    // 网络通道的状态
    bool status;

    // 网络通道的类型
    NW_INET_TYPE inetType;

    // 网络通道的ID
    NW_SOCK_ID socketId;

    // 网络通道的地址
    struct sockaddr_in address;

    NW_SOCKET()
        : status(false)
        , inetType(NW_NIL)
        , socketId(NW_INVALID)
    {}
    NW_SOCKET(NW_SOCK_ID id)
        : status(false)
        , inetType(NW_NIL)
        , socketId(id)
    {}
    NW_SOCKET(const NW_SOCKET&)=default;
    bool operator==(NW_SOCK_ID id)
    {return socketId == id;}
    bool operator!=(NW_SOCK_ID id)
    {return socketId != id;}
    NW_SOCKET& operator=(const NW_SOCKET&)=default;

};


// 数据包内容的最大值
#define PACKAGESIZE 1024

// 默认端口
#define DEFAULT_PORT 8899

// 默认IP地址
#define DEFAULT_IPV4 "0.0.0.0"

// 默认连接数
#define DEFAULT_BACKLOG 5

// 错误码
#define NW_FAILED -1

/*
网络数据的行为:
    NW_AC_IGN (filetransmission_Action_ignore)  忽略行为
        如果是忽略行为，那么这个数据包将不会被处理
    NW_AC_GET (filetransmission_Action_get)     获取行为
        如果是获取行为
            表示客户端向服务端请求数据
            可以请求文件，也可以请求文本
    NW_AC_PUT (filetransmission_Action_put)     上传行为
         如果是上传行为
            表示客户端向服务端发送数据
            可以发送文件，也可以发送文本
    NW_AC_MSG (filetransmission_Action_message) 消息行为
        如果是消息行为
            表示客户端可以向服务端发送文本消息
            或者服务端向客户端发送文本消息
    NW_AC_QUIT(filetransmission_Action_quit)    退出行为
        如果是退出行为
            表示客户端请求断开连接
    NW_AC_LOGIN(filetransmission_Action_login)  登录行为
        如果是登录行为
            表示客户端请求登录
*/
typedef enum
{NW_AC_IGN,NW_AC_GET,NW_AC_PUT,NW_AC_MSG,NW_AC_QUIT,NW_AC_LOGIN}NW_Action;

/*
网络数据的类型:
    NW_DT_IGN (filetransmission_DataType_Ignore)  忽略类型
        如果是忽略类型，那么这个数据包将不会被处理
    NW_DT_CMD (filetransmission_DataType_Command) 命令类型
        如果数据包是命令类型
            表示这个数据包是一个命令
    NW_DT_MSG (filetransmission_DataType_Message) 消息类型
        如果数据包是消息类型
            表示这个数据包是一个文本消息
    NW_DT_FIL (filetransmission_DataType_File)    文件类型
        如果数据包是文件类型
            表示这个数据包是一个文件
*/
typedef enum
{NW_DT_IGN,NW_DT_CMD,NW_DT_MSG,NW_DT_FIL}NW_DataType;

/*
网络数据包的状态:
    NW_DS_IGN (filetransmission_DataStatus_Ignore)   忽略（无效数据包）
        如果是忽略状态，那么这个数据包将不会被处理
    NW_DS_ONCE (filetransmission_DataStatus_Once)    单次（一次性数据包）
        如果是单次状态
            表示这个数据包是一个单次数据包
    NW_DS_ST (filetransmission_DataStatus_Start)     开始（第一个数据包）
        如果是开始状态
            表示这个数据包是一个连续数据的开始
    NW_DS_TT (filetransmission_DataStatus_Transport) 传输中（中间数据包）
        如果是传输中状态
            表示这个数据包是一个连续数据的中间
    NW_DS_FH (filetransmission_DataStatus_Finish)    结束（最后一个包）
        如果是结束状态
            表示这个数据包是一个连续数据的结束
*/
typedef enum
{NW_DS_IGN,NW_DS_ONCE,NW_DS_ST,NW_DS_TT,NW_DS_FH}NW_DataStatus;

/*
网络数据包的封装:
    pa_number 本次数据的序列
    pa_action 本次数据的行为
    pa_type   本次数据的类型
    pa_status 本次数据的状态
    pa_size   本次数据的大小
    pa_context本次数据的内容
*/
struct NW_Package
{
    int           pa_number;   // 本次数据的序列
    NW_Action     pa_action;   // 本次数据的行为
    NW_DataType   pa_type;     // 本次数据的类型
    NW_DataStatus pa_status;   // 本次数据的状态
    int           pa_size;     // 本次数据的大小
    char          pa_context[PACKAGESIZE];// 本次数据的内容

    // 构造函数
    NW_Package()
        : pa_number(1),pa_action(NW_AC_MSG),pa_type(NW_DT_MSG),pa_status(NW_DS_TT),pa_size(0)
    {
        for(int i = 0;i < PACKAGESIZE;i++)pa_context[i]=0;
    }

    // 有参构造函数
    NW_Package(int number,NW_Action action,NW_DataType type,NW_DataStatus status,int size,std::string context)
        : pa_number(number),pa_action(action),pa_type(type),pa_status(status),pa_size(size)
    {
        for(int i = 0;i < PACKAGESIZE;i++)pa_context[i]=0;
        strcpy(pa_context,context.c_str());
    }

    ~NW_Package()
    {
        // 清理数据包
        clear();
    }

    // 清空数据包
    void clear()
    {
        pa_number = 1;
        pa_action = NW_AC_MSG;
        pa_type = NW_DT_MSG;
        pa_status = NW_DS_TT;
        pa_size = 0;
        for(int i = 0;i < PACKAGESIZE;i++)pa_context[i]=0;
    }

};

// API
// 获取一个Tcp的服务端套接字
/*
    @brief 生成一个TCP服务端套接字
    @param ipv4 需要绑定的ipv4地址，可以为空，为空默认绑定INADDR_ANY
    @param port 需要绑定的端口号，可以为空，为空默认绑定DEFAULT_PORT
    @return NW_SOCKET 成功返回一个创建好的套接字，失败返回NW_INVALID
*/
NW_SOCKET NW_TcpServer(std::string ipv4="",int port = DEFAULT_PORT,int backlog = DEFAULT_BACKLOG);

// 获取一个Tcp的客户端套接字
/*
    @brief 生成一个TCP客户端端套接字
    @param ipv4 需要连接 服务端的ipv4地址
    @param port 需要连接 服务端的端口号
    @return NW_SOCKET 成功返回一个创建好的套接字，失败返回NW_INVALID
*/
NW_SOCKET NW_TcpClient(std::string ipv4,int port);

// 获取一个Udp的套接字
/*
    @brief 生成一个TCP客户端端套接字
    @param ipv4 数据包需要发送到的目标ipv4地址
    @param port 数据包需要发送到的目标端口号
    @param broadcast 是否广播,默认不广播
    @return NW_SOCKET 成功返回一个创建好的套接字，失败返回NW_INVALID
*/
NW_SOCKET NW_UdpSocket(std::string ipv4,int port,bool broadcast = false);

// 等待一个客户端连接
/*
    @brief 等待一个客户端连接
    @param socketId 需要等待客户端连接的服务端
    @return 成功返回一个客户端网络通道，失败返回NW_FAILED
*/
NW_SOCKET NW_Accept(NW_SOCKET &socketId);

// 关闭网络通道
/*
    @brief 关闭一个网络通道
    @param socket 需要关闭的网络通
*/
void     NW_ShutDown(NW_SOCKET &socketId);

// 通过指定的套接字发送一个网络数据包
bool NW_Send(NW_SOCKET &socketId,NW_Package &data);
bool NW_Send(NW_SOCKET &socketId,NW_Action action,NW_DataType type,std::string data);

// 通过指定的套接字获取一个网络数据包
bool NW_Recv(NW_SOCKET &socketId,NW_Package  &data);
bool NW_Recv(NW_SOCKET &socketId,std::string &data);

// 2025-01-01 Update
// 检查指定网络通道是否可用
bool NW_Select(NW_SOCKET &socketId);

// 输出最近一次的错误信息
const char *NW_Error();

// 数据解析
std::vector<std::string> NW_Parse(std::string data);

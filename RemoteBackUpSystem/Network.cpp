#include "Network.h"


// 获取一个Tcp的服务端套接字
/*
    @brief 生成一个TCP服务端套接字
    @param ipv4 需要绑定的ipv4地址，可以为空，为空默认绑定INADDR_ANY
    @param port 需要绑定的端口号，可以为空，为空默认绑定8899
    @return NW_SOCKET 成功返回一个创建好的套接字，失败返回NW_INVALID
*/

NW_SOCKET NW_TcpServer(std::string ipv4,int port,int backlog)
{
#ifdef  _WIN32 // 如果定义了WIN32宏
#ifndef  __linux__ // 没有定义LINUX宏,说明这个是在Windows平台使用
    // 初始化网络库
    WSADATA wd;
    WSAStartup(MAKEWORD(2,2),&wd);
#endif
#endif
    NW_SOCKET sock;
    sock.socketId = socket(AF_INET,SOCK_STREAM,0);
    if(sock.socketId == NW_INVALID)return NW_INVALID;

    sock.address.sin_family       = AF_INET;
    sock.address.sin_port         = htons(port==0?DEFAULT_PORT:port);

    sock.address.sin_addr.s_addr  = ipv4==""?INADDR_ANY:inet_addr(ipv4.c_str());

    if(bind(sock.socketId,(struct sockaddr*)&sock.address,sizeof(sock.address)) == NW_FAILED)
    {
        NW_ShutDown(sock);
        return NW_INVALID;
    }

    if(listen(sock.socketId,DEFAULT_BACKLOG) == NW_FAILED)
    {
        NW_ShutDown(sock);
        return NW_INVALID;
    }

    const char opt = 1;
    setsockopt(sock.socketId,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    sock.inetType = NW_TCP;
    sock.status = true;

    return sock;
}

// 获取一个Tcp的客户端套接字
/*
    @brief 生成一个TCP客户端端套接字
    @param ipv4 需要连接 服务端的ipv4地址
    @param port 需要连接 服务端的端口号
    @return NW_SOCKET 成功返回一个创建好的套接字，失败返回NW_INVALID
*/
NW_SOCKET NW_TcpClient(std::string ipv4,int port)
{
#ifdef  _WIN32 // 如果定义了WIN32宏
#ifndef  __linux__ // 没有定义LINUX宏,说明这个是在Windows平台使用
    // 初始化网络库
    WSADATA wd;
    WSAStartup(MAKEWORD(2,2),&wd);
#endif
#endif
    NW_SOCKET sock;
    sock.socketId = socket(AF_INET,SOCK_STREAM,0);
    if(sock.socketId == NW_INVALID)return NW_INVALID;

    sock.address.sin_family       = AF_INET;
    sock.address.sin_port         = htons(port);
    sock.address.sin_addr.s_addr  = INADDR_ANY;

    if(bind(sock.socketId,(struct sockaddr*)&sock.address,sizeof(sock.address)) == NW_FAILED)
    {
        NW_ShutDown(sock);
        return NW_INVALID;
    }

    const char opt = 1;
    setsockopt(sock.socketId,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    struct sockaddr_in server;
    server.sin_family       = AF_INET;
    server.sin_port         = htons(port);

    server.sin_addr.s_addr  = inet_addr(ipv4.c_str());

    if(::connect(sock.socketId,(struct sockaddr*)&server,sizeof(server)) == NW_FAILED)
    {
        NW_ShutDown(sock);
        return NW_INVALID;
    }

    sock.inetType = NW_TCP;
    sock.status = true;

    return sock;
}

// 获取一个Udp的套接字
/*
    @brief 生成一个TCP客户端端套接字
    @param ipv4 数据包需要发送到的目标ipv4地址
    @param port 数据包需要发送到的目标端口号
    @return NW_SOCKET 成功返回一个创建好的套接字，失败返回NW_INVALID
*/
NW_SOCKET NW_UdpSocket(std::string ipv4,int port,bool broadcast)
{
#ifdef  _WIN32 // 如果定义了WIN32宏
#ifndef  __linux__ // 没有定义LINUX宏,说明这个是在Windows平台使用
    // 初始化网络库
    WSADATA wd;
    WSAStartup(MAKEWORD(2,2),&wd);
#endif
#endif
    NW_SOCKET sock;
    sock.socketId = socket(AF_INET,SOCK_DGRAM,0);
    if(sock.socketId == NW_INVALID)return NW_INVALID;

    sock.address.sin_family       = AF_INET;
    sock.address.sin_port         = htons(port);
    sock.address.sin_addr.s_addr  = INADDR_ANY;

    if(bind(sock.socketId,(struct sockaddr*)&sock.address,sizeof(sock.address)) == NW_FAILED)
    {
        NW_ShutDown(sock);
        return NW_INVALID;
    }

    // 判断是否需要广播
    if(broadcast)
    {
        int opt = 1;
        if(setsockopt(sock.socketId,SOL_SOCKET,SO_BROADCAST,(char*)&opt,sizeof(opt)) == NW_FAILED)
        {
            NW_ShutDown(sock);
            return NW_INVALID;
        }
    }

    sock.inetType = NW_UDP;
    sock.status = true;

    return sock;
}

// 关闭网络通道
/*
    @brief 关闭一个网络通道
    @param socket 需要关闭的网络通
*/
void     NW_ShutDown(NW_SOCKET &socketId)
{
#ifdef  __linux__
#ifndef _WIN32
    close(socketId.socketId);
#endif
#endif

#ifdef  _WIN32
#ifndef __linux__
    WSACleanup();// 解除网络库的初始化操作
    closesocket(socketId.socketId);
#endif
#endif

    socketId.socketId = NW_INVALID;
    socketId.status   = false;
}

// 等待一个客户端连接
/*
    @brief 等待一个客户端连接
    @param socketId 需要等待客户端连接的服务端
    @return 成功返回一个客户端网络通道，失败返回NW_FAILED
*/
NW_SOCKET NW_Accept(NW_SOCKET &socketId)
{
    NW_SOCKET newSockId;
    while(1)
    {
        NW_SOCKLEN length = sizeof(newSockId.address);
        newSockId.socketId = accept(socketId.socketId,(struct sockaddr*)&newSockId.address,&length);
        if(newSockId.socketId == -1)return newSockId;
        break;
    }
    newSockId.status = true;
    newSockId.inetType = NW_TCP;
    return newSockId;
}

// 通过指定的套接字发送一个网络数据包
bool NW_Send(NW_SOCKET &socketId,NW_Package &data)
{
    // 如果是TCP通道，那么就使用send发送数据
    if(socketId.inetType == NW_TCP)
    { if(send(socketId.socketId,(const char *)&data,sizeof(data),0) == -1)return false;}

    // 如果是UDP通道，那么就使用sendto发送数据
    else if(socketId.inetType == NW_UDP)
    {if(sendto(socketId.socketId,(const char *)&data,sizeof(data),0,(struct sockaddr*)&socketId.address,sizeof(socketId.address))==-1)return false;}
    return true;
}

bool NW_Send(NW_SOCKET &socketId,NW_Action action,NW_DataType type,std::string data)
{
    // 创建一个网络数据包
    NW_Package inetData;
    inetData.pa_number = 1;
    inetData.pa_action = action;
    inetData.pa_type   = type;
    inetData.pa_status = NW_DS_ONCE;
    inetData.pa_size   = data.length();
    strcpy(inetData.pa_context,data.c_str());

    return NW_Send(socketId,inetData);
}

// 通过指定的套接字获取一个网络数据包
bool NW_Recv(NW_SOCKET &socketId,NW_Package &data)
{
    data.clear();
    if(socketId.inetType == NW_TCP)
    {if(recv(socketId.socketId,(char*)&data,sizeof(data),0) == -1)return false;}
    else if(socketId.inetType == NW_UDP)
    {if(recvfrom(socketId.socketId,data.pa_context,data.pa_size,0,NULL,NULL)==-1)return false;}
    return true;
}

bool NW_Recv(NW_SOCKET &socketId,std::string &data)
{
    NW_Package inetData;
    if(!NW_Recv(socketId,inetData))return false;
    data = inetData.pa_context;
    return true;
}

// 检查指定网络通道是否可用
bool NW_Select(NW_SOCKET &socketId)
{
    if(socketId.socketId == NW_INVALID) return false;

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(socketId.socketId, &read_fds);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 10000; // 10ms timeout

    int ret = select(socketId.socketId + 1, &read_fds, NULL, NULL, &timeout);
    if(ret == -1) {
        return false; // select error
    }
    if(ret == 0) {
        return false; // timeout
    }

    if(FD_ISSET(socketId.socketId, &read_fds)) {
        return true; // socket is ready
    }

    return false;
}

const char *NW_Error()
{
    static char errorMsg[256] = {0};

#ifdef  _WIN32 // 如果定义了WIN32宏
#ifndef  __linux__ // 没有定义LINUX宏,说明这个是在Windows平台使用
    // 获取错误码
    int errCode = WSAGetLastError();

    // 将错误码转换为错误信息
    LPVOID msgBuffer;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&msgBuffer,
        0, NULL);

    strncpy(errorMsg, (const char*)msgBuffer, sizeof(errorMsg)-1);
    LocalFree(msgBuffer);
    return errorMsg;
#endif
#endif

#ifdef  __linux__
#ifndef _WIN32
    return strerror(errno);
#endif
#endif
    return "未知错误";
}

// 数据解析:将字符串按照:分割成多个字符串
std::vector<std::string> NW_Parse(std::string data)
{
    std::vector<std::string> result;

    std::string fieldData = "";
    for(size_t i = 0; i < data.length(); i++)
    {
        if(data[i] == ':')
        {
            result.push_back(fieldData);
            fieldData.clear();
        }
        else fieldData.push_back(data[i]);
    }

    // 把最后一个字符串添加到结果中
    if(!fieldData.empty())result.push_back(fieldData);
    return result;
}

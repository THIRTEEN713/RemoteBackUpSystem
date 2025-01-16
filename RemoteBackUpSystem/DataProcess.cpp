#include "DataProcess.h"

QMutex DataProcess::mutex;

DataProcess::DataProcess(QObject *parent) 
    : QThread(parent)
    , isRun(false)
{

}

DataProcess::~DataProcess() 
{
    NW_ShutDown(nw);
}

// 判断是否连接
bool DataProcess::isConnect()
{return nw.status;}

// 设置地址
bool DataProcess::connectServer(QString ip, int port)
{
    nw = NW_TcpClient(ip.toStdString(), port);
    return nw.status;
}

// 断开连接
void DataProcess::shutDown()
{
    NW_ShutDown(nw);
    isRun = false;
}

bool DataProcess::sendData(NW_Package data)
{
    bool isSend = false;
    mutex.lock();
    isSend = NW_Send(nw,data);
    mutex.unlock();
    return isSend;
}

void DataProcess::run()
{
    isRun = true;
    while(isRun)
    {
        NW_Package recvData;
        mutex.lock();
        NW_Recv(nw,recvData);
    std::cout  << recvData.pa_context << std::endl;
        mutex.unlock();
        emit newRecv(recvData);
        QThread::msleep(100);
    }
}

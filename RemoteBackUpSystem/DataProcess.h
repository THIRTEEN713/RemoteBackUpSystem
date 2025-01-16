#ifndef DATAPROCESS_H
#define DATAPROCESS_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include "NetWork.h"

class DataProcess : public QThread
{
    Q_OBJECT
public:
    DataProcess(QObject *parent = nullptr);
    ~DataProcess();

    bool connectServer(QString ip, int port);

    bool isConnect();

    void run();

    void shutDown();

    // 发送消息
    bool sendData(NW_Package data);

signals:
    void newRecv(NW_Package data);
    void overSend(bool isSend);

private:
    NW_SOCKET nw;
    bool isRun;

    static QMutex mutex; // 互斥锁
};

#endif // DATAPROCESS_H

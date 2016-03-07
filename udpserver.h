#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QTextEdit>
#include <QUdpSocket>
#include <QTimer>
#include <QDateTime>

class UdpServer : public QTextEdit
{
    Q_OBJECT

public:
    UdpServer(QWidget *_parent = 0);
    ~UdpServer();

private slots:
    void slotSendDatagram();

private:
    QUdpSocket *udp;
};

#endif // UDPSERVER_H

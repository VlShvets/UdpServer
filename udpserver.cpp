#include "udpserver.h"

UdpServer::UdpServer(QWidget *_parent)
    : QTextEdit(_parent)
{
    setWindowTitle("UdpServer");

    udp = new QUdpSocket(this);

    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer, SIGNAL(timeout()), SLOT(slotSendDatagram()));
}

UdpServer::~UdpServer()
{

}

void UdpServer::slotSendDatagram()
{
    QByteArray baDatagram;
    QDataStream out(&baDatagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    QDateTime dt = QDateTime::currentDateTime();
    append("Sent: " + dt.toString());
    out << dt;
    udp->writeDatagram(baDatagram, QHostAddress::LocalHost, 2424);
}

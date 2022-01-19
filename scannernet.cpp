#include "scannernet.h"
#include <QCoreApplication>
#include <QAbstractSocket>
#include <QTcpSocket>

ScannerNet::ScannerNet(QObject *parent) : QObject(parent)
{

}

QVector<bool> ScannerNet::Scan(QString hostname, QVector<int> ports)
{
    QVector<bool> r;
    QTcpSocket* socket = new QTcpSocket();

    for ( int x = 0; x < ports.size(); x++)
    {
        socket->connectToHost(hostname, ports[x]);
        if (!socket->waitForConnected(1000)) {
            r.append(false);
        } else {
            r.append(true);
            socket->disconnectFromHost();
        }
  }
  return r;
}

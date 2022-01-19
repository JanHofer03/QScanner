#include "scanner.h"
#include "scannernet.h"
#include <QDebug>
#include <QVector>

Scanner::Scanner(QWidget *parent) :
    QWidget(parent)
{
    m_scan = new ScannerNet;
    setupUi(this);
}

void Scanner::on_startButton_clicked()
{
    resultWindow->setText("");
    m_port.clear();

    QStringList portlist = portEntry->text().split(',');
    for(int x = 0; x < portlist.size(); x++) m_port.append(portlist[x].toUInt());

    m_r = ScannerNet::Scan(hostnameEntry->text(), m_port);


    if(m_port[0] != 0)Scanner::Scanneropt();
}

void Scanner::Scanneropt()
{
    QString output;

    for(int x = 0; x < m_r.size(); x ++)
    {
        if(m_r[x] == true)
        {
            output = "Port "+ QString::number(m_port[x]) + ": Connected !";
            resultWindow->setTextColor("green");
        } else {
            output = "Port " + QString::number(m_port[x]) + ": not connected !";
            resultWindow->setTextColor("red");
        }
        resultWindow->append(output);
    }
}

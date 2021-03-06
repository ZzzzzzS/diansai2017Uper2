﻿#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QList>

class port : public QSerialPort
{

    Q_OBJECT
public:
    port();
    void PortScan();
    QList<QSerialPortInfo> PortInfo;
    bool OpenPort();

    char position;

    struct
    {
        QString portname;
        char baud;
        char Data;
        char stopbit;
        char parity;
    }settings;

public slots:
    void DistanceAddSlot();
    void distanceMinusSlot();
    void AngleSlot(int angle);   
    void PSlot(unsigned char P);
    void ISlot(unsigned char I);
    void DSlot(unsigned char D);
private:
    void SaveWrite(QByteArray &data);
    void SaveWrite(char *data);


};

extern port Port;

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // PORT_H

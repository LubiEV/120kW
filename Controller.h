#ifndef CONTROLLER_H
#define CONTROLLER_H

// SYSTEM INCLUDES
#include <QObject>
#include <QThread>
//#include "ocpp.h"
#include "dcmodule.h"
#include "dccomboplc.h"
// APPLICATION INCLUDES
#include "Worker.h"
#include "modbus.h"
#define MODBUS_THREAD 1

// DEFINES
// EXTERNAL FUNCTIONS
// EXTERNAL VARIABLES
// CONSTANTS
// STRUCTS
// TYPEDEFS
// FORWARD DECLARATIONS

class Controller : public QObject {
    Q_OBJECT

#ifdef MODBUS_THREAD
    QThread workerThread;
#endif
    QThread workerThread2;
#ifdef PLC_THREAD
    QThread workerThread3;
#endif
public:
    Controller() {
     //   auto worker = new Worker;
#ifdef MODBUS_THREAD
        auto modbus = new MODBUS;
#endif
        auto can_run = new Dcmodule;
#ifdef PLC_THREAD
        auto ComboPLC =  new dcComboPLC;
#endif
#ifdef MODBUS_THREAD
        modbus->moveToThread(&workerThread);
#endif
        can_run->moveToThread(&workerThread2);
#ifdef PLC_THREAD
        ComboPLC->moveToThread(&workerThread3);
#endif
#ifdef MODBUS_THREAD
        connect(&workerThread, &QThread::finished, modbus, &QObject::deleteLater);
#endif
        connect(&workerThread2, &QThread::finished, can_run, &QObject::deleteLater);
#ifdef PLC_THREAD
        connect(&workerThread3, &QThread::finished, ComboPLC, &QObject::deleteLater);
#endif
#ifdef MODBUS_THREAD
        connect(this, &Controller::requestWork, modbus, &MODBUS::Dcplcfunction);
#endif
        connect(this, &Controller::Plc_relay, can_run, &Dcmodule::can_module_run);
#ifdef PLC_THREAD

       connect(this, &Controller::ComboPlc_Request, ComboPLC, &dcComboPLC::readPLC_COM);
#endif

       // connect(worker, &Worker::resultReady, this, &Controller::handleResults);

        connect(can_run, &Dcmodule::send_signal, this, [this](int secsLeft) {
            emit onWorkProgress(secsLeft);
           // printf("in worker class\r\n");
        });
#ifdef PLC_THREAD
        connect(ComboPLC, &dcComboPLC::sgnCCS_Relay, this, [this](int secsLeft) {
            emit onComboPlc(secsLeft);
            printf("in worker class\r\n");
        });
#endif

#ifdef MODBUS_THREAD
        workerThread.start();
#endif
        workerThread2.start();
#ifdef PLC_THREAD
        workerThread3.start();
#endif
    }

    ~Controller() {
#ifdef MODBUS_THREAD
        if (workerThread.isRunning()) {
            workerThread.quit();
            workerThread.wait();
        }
#endif
        if (workerThread2.isRunning()) {
            workerThread2.quit();
            workerThread2.wait();
        }
#ifdef PLC_THREAD

         if (workerThread3.isRunning()) {
            workerThread3.quit();
            workerThread3.wait();
        }
#endif
    }
public slots:
    void handleResults(const QString &result) {        
        printf("Now in 1 second timer\r\n");
    }
signals:
    void onWorkFinished(const QString&);
    void onWorkProgress(int secsLeft);
#ifdef PLC_THREAD
    void onComboPlc(int secsLeft);
#endif
    void requestWork(int);
    void Plc_relay(int);
#ifdef PLC_THREAD
    void ComboPlc_Request(int);
#endif
};
#endif // CONTROLLER_H
#pragma once

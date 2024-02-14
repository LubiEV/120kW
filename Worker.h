#ifndef WORKER_H
#define WORKER_H
#pragma once

// SYSTEM INCLUDES
#include <QTimer>
#include <QThread>
#include <QObject>
#include <QEventLoop>

//class Worker : public QObject
//{
//    Q_OBJECT
//public slots:
//    void doWork(int count)  {
//        const QString result = "finished";
//        // Event loop allocated in workerThread
//        QEventLoop loop;
//        for (auto remSecs = count; remSecs >= 0; remSecs--) {
//            // wait 1000 ms doing nothing, not really sure why
//            // I cannot simply do QThread::msleep(1000)
//            QTimer::singleShot(1000, &loop, SLOT(quit()));
//            // process any signals emitted above
//            loop.exec();
//            printf("do work\r\n");
//            emit progressUpdate(remSecs);
//        }
//        emit resultReady(result);
//    }
//signals:
//    void progressUpdate(int secondsLeft);
//    void resultReady(const QString &result);
//};
#endif // WORKER_H

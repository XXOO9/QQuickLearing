#ifndef CMAINCONTROL_H
#define CMAINCONTROL_H
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QObject>
#include <QDebug>
#include <QQmlContext>
#include "CDevCameraControl.h"

class CMainControl : public QObject
{
    Q_OBJECT
public:
    explicit CMainControl( int argc, char **argv, QObject *parent = nullptr );
    ~CMainControl();


public:
//    void registType()

private:
    void init();
    void initCore( int argc, char **argv );
    void initUI();
    void initConnection();

private slots:
    void onViewEngineCreateFinished( QObject *object, const QUrl &url );

private:
    QGuiApplication        *m_pGuiApp;
    QQmlApplicationEngine  *m_pViewEngine;
    CDevCameraControl      m_DevCameraControler;

private:
    const QUrl              m_qmlUrl{QStringLiteral("qrc:/main.qml")};
};

#endif // CMAINCONTROL_H

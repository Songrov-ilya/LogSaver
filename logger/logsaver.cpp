#include "logsaver.h"
#include "logbook.h"

#include <QMetaClassInfo>

LogSaver::LogSaver(const QString &logDir, const QString &prefixLogFile, const QString &sufixLogFile, QObject *parent)
{
    GlobalSettingsLog globalSettingsLog;
    globalSettingsLog.logDir        = logDir;
    globalSettingsLog.prefixLogFile = prefixLogFile;
    globalSettingsLog.sufixLogFile  = sufixLogFile;
    logbook = new Logbook(globalSettingsLog, this);
    qDebug() << "\033[48;2;6;185;185m"
             << "Start" << QCoreApplication::applicationName() << QDateTime::currentDateTime().toString("yyyy:MM:dd - hh:mm:ss:zzz")
             << "applicationVersion:" << QCoreApplication::applicationVersion()
             << "\033[0m" << Qt::endl;
}

QString LogSaver::getVersionClass()
{
    const QString version = LogSaver::staticMetaObject.classInfo(LogSaver::staticMetaObject.indexOfClassInfo("Version")).value();
    qDebug() << QString("%1 version: %2").arg(LogSaver::staticMetaObject.className()).arg(version) << Qt::endl;
    return version;
}
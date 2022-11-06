#ifndef CLOCALCONFIG_H
#define CLOCALCONFIG_H

#include <QObject>
#include <QSettings>
#include <QCoreApplication>
#include <QFileInfo>

namespace LocalConfigKeys {
    const QString userName = "userName";
}

class CLocalConfig
{
public:
    CLocalConfig();
    QVariantMap getConfigs();
    void setTargetKeyValue( const QString &key, const QVariant &value );


private:
    void init();
    void resetPtr();
    bool isConfigFileExisted() const;
    void generateDefaultConfig();

private:
    QSettings   *m_pSettings = nullptr;


    const QString m_configFileName = "config.txt";
};

#endif // CLOCALCONFIG_H

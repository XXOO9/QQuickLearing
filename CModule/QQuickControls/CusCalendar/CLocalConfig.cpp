#include "CLocalConfig.h"

CLocalConfig::CLocalConfig()
{
    init();
}

void CLocalConfig::init()
{
    if( !isConfigFileExisted() ){
        generateDefaultConfig();
        return;
    }

    QString settingFileName = QCoreApplication::applicationDirPath() + "/config/" + m_configFileName;
     m_pSettings = new QSettings( settingFileName, QSettings::IniFormat );
}

void CLocalConfig::resetPtr()
{
    if( nullptr != m_pSettings ){
        delete m_pSettings;
        m_pSettings = nullptr;
    }
}

bool CLocalConfig::isConfigFileExisted() const
{
    QString settingFileName = QCoreApplication::applicationDirPath() + "/config/" + m_configFileName;
    bool ok = QFileInfo::exists( settingFileName );
    return ok;
}

void CLocalConfig::generateDefaultConfig()
{
    resetPtr();
    QString settingFileName = QCoreApplication::applicationDirPath() + "/config/" + m_configFileName;
    m_pSettings = new QSettings( settingFileName, QSettings::IniFormat );


    m_pSettings->beginGroup( "CXK" );

    //用户名
    m_pSettings->setValue( LocalConfigKeys::userName, "CXK" );

    m_pSettings->endGroup();
}

QVariantMap CLocalConfig::getConfigs()
{
    QVariantMap retMap;
    retMap.insert(  LocalConfigKeys::userName, m_pSettings->value( "CXK/" +  LocalConfigKeys::userName ) );

    return retMap;
}

void CLocalConfig::setTargetKeyValue(const QString &key, const QVariant &value)
{
    m_pSettings->beginGroup( "CXK" );
    m_pSettings->setValue( key, value );
    m_pSettings->endGroup();
}

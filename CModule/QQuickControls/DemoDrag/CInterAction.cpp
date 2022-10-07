#include "CInterAction.h"

CInterAction::CInterAction(QObject *parent) : QObject(parent)
{

}

void CInterAction::registEngine( QQmlApplicationEngine *pEngine)
{
    m_pEngine = pEngine;

    m_pEngine->rootContext()->setContextProperty( "ListDataModel", &m_listModel );
}

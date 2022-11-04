#include "CInteraction.h"

CInteraction::CInteraction(QObject *parent) : QObject(parent)
{
    m_pFilterModel = new CusFiltListModel();
    setFilterSourceModel( &m_srcModel );

    initOrginalFilterModel();
}

void CInteraction::setEnigne(QQmlApplicationEngine *pEngine)
{
    m_pEngine = pEngine;

    registMember();
}

void CInteraction::setFilterSourceModel(QAbstractItemModel *srcModel )
{
    m_pFilterModel->setSourceModel( srcModel );
    //    m_pFilterModel->setFilterCaseSensitivity( Qt::CaseInsensitive );
}

void CInteraction::setVariantList(QVariantList list)
{
    qDebug() << list;
}

void CInteraction::registMember()
{
    m_pEngine->rootContext()->setContextProperty( "FilterModel", m_pFilterModel );
    m_pEngine->rootContext()->setContextProperty( "OrginalFilterModel", &m_orginalFilterModel );
    qmlRegisterType<CusFiltListModel>( "App", 1, 0, "CusFiltModel" );
}

void CInteraction::initOrginalFilterModel()
{
    m_orginalFilterModel.setSourceModel( &m_srcModel );
    m_orginalFilterModel.setFilterRole( CModelUserSelect::UserItem::UserDepartment );

//    m_orginalFilterModel.setFilterWildcard( "*B" );
}

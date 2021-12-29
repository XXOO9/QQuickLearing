#include "CTableModelRowData.h"

CTableModelRowData::CTableModelRowData()
{
    setDisplayRole( "" );
    setUnqiueRole( "" );
}

CTableModelRowData::~CTableModelRowData()
{

}

void CTableModelRowData::setDisplayRole(QString val)
{
    m_unitData[DisplayRole] = val;
}

QString CTableModelRowData::displayRole()
{
    return m_unitData[DisplayRole];
}

void CTableModelRowData::setDataRole(QString val)
{
    m_unitData[DataRole] = val;
}

QString CTableModelRowData::dataRole()
{
    return m_unitData[DataRole];
}

void CTableModelRowData::setTipsRole(QString val)
{
    m_unitData[TipsRole] = val;
}

QString CTableModelRowData::tipsRole()
{
    return m_unitData[TipsRole];
}

void CTableModelRowData::setUnqiueRole(QString val)
{
    m_unitData[unquieRole] = val;
}

QString CTableModelRowData::unqiueRole()
{
    return m_unitData[unquieRole];
}

void CTableModelRowData::clear()
{
    m_unitData[DisplayRole] = "";
    m_unitData[DataRole] = "";
    m_unitData[TipsRole] = "";
    m_unitData[unquieRole] = "";
}

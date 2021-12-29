#include "CUnitData.h"

CUnitData::CUnitData()
{
    m_data[CDataModel::DisplayRole] = "";
    m_data[CDataModel::UniqueRole] = "";
    m_data[CDataModel::DataRole] = "";
}

CUnitData::~CUnitData()
{

}

void CUnitData::setDisplayContent(const QString val)
{
    m_data[CDataModel::DisplayRole] = val;
}

QString CUnitData::displayContent() const
{
    return m_data[CDataModel::DisplayRole];
}

void CUnitData::setUnique(const QString val)
{
    m_data[CDataModel::UniqueRole] = val;
}

QString CUnitData::unique() const
{
    return m_data[CDataModel::UniqueRole];
}

void CUnitData::setDataContent(const QString val)
{
    m_data[CDataModel::DataRole] = val;
}

QString CUnitData::data() const
{
    return m_data[CDataModel::DataRole];
}

#include "CUserSelectItem.h"

CUserSelectItem::CUserSelectItem()
{

}

bool CUserSelectItem::checkFlag() const
{
    return m_checkFlag;
}

void CUserSelectItem::setCheckFlag(bool checkFlag)
{
    m_checkFlag = checkFlag;
}

QString CUserSelectItem::photoPath() const
{
    return m_photoPath;
}

void CUserSelectItem::setPhotoPath(const QString &photoPath)
{
    m_photoPath = photoPath;
}

QString CUserSelectItem::userName() const
{
    return m_userName;
}

void CUserSelectItem::setUserName(const QString &userName)
{
    m_userName = userName;
}

QString CUserSelectItem::userNumber() const
{
    return m_userNumber;
}

void CUserSelectItem::setUserNumber(const QString &userNumber)
{
    m_userNumber = userNumber;
}

QString CUserSelectItem::userWeight() const
{
    return m_userWeight;
}

void CUserSelectItem::setUserWeight(const QString &userWeight)
{
    m_userWeight = userWeight;
}

QString CUserSelectItem::bindDevOrderNum() const
{
    return m_bindDevOrderNum;
}

void CUserSelectItem::setBindDevOrderNum(const QString &bindDevOrderNum)
{
    m_bindDevOrderNum = bindDevOrderNum;
}

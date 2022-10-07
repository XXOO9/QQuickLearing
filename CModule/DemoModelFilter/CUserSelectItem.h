#ifndef CUSERSELECTITEM_H
#define CUSERSELECTITEM_H

#include <QObject>
#include <QDebug>

class CUserSelectItem
{
public:


    CUserSelectItem();

    bool checkFlag() const;
    void setCheckFlag(bool checkFlag);

    QString photoPath() const;
    void setPhotoPath(const QString &photoPath);

    QString userName() const;
    void setUserName(const QString &userName);

    QString userNumber() const;
    void setUserNumber(const QString &userNumber);

    QString userWeight() const;
    void setUserWeight(const QString &userWeight);

    QString bindDevOrderNum() const;
    void setBindDevOrderNum(const QString &bindDevOrderNum);

    QString departmentName() const;
    void setDepartmentName(const QString &departmentName);

private:
    bool    m_checkFlag = false;
    QString m_photoPath = "null";
    QString m_userName = "null";
    QString m_userNumber = "-1";
    QString m_userWeight = "0";
    QString m_bindDevOrderNum = "-1";
    QString m_departmentName = "";

};

#endif // CUSERSELECTITEM_H

#include "CMainWidget.h"
#include "ui_CMainWidget.h"

CMainWidget::CMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMainWidget)
{
        getSyncVideoUrls();
        syncScoreStd();
        heartBeat();
        syncUserInfo();
        testFunc();
        upLoadCommonScore();
        queryHistory();
        syncClassInfo();
        upLoadBodyScore();
        userIdentify();
        touristUsageRecord();
        downLoadFile();

}

CMainWidget::~CMainWidget()
{
    delete ui;
}

void CMainWidget::testFunc()
{

}

void CMainWidget::getSyncVideoUrls()
{
        CHttpGetVideoUrls *getUrls = new CHttpGetVideoUrls( "8945632" );
        getUrls->httpRequest();

        connect( getUrls, &CHttpGetVideoUrls::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "failed...";
            }else{
                qDebug() << "11111111111111";
                qDebug() << getUrls->getSingleRet( 0, "picUrl" );
            }
        });
        qDebug() << "funciont done...";
}

void CMainWidget::syncScoreStd()
{
        CHttpSyncScoreStd *syncScoreStd = new CHttpSyncScoreStd();
        syncScoreStd->httpRequest();
        connect( syncScoreStd, &CHttpSyncScoreStd::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "request failed...";
            }else{
                qDebug() << "request success...";
                qDebug() << "grade = " << syncScoreStd->getSingleRet( 1, SYNCSCORE_GRADE );
            }
        });
}

void CMainWidget::heartBeat()
{
        CHttpHeartBeat *heartBeat = new CHttpHeartBeat();
        heartBeat->setStatus( devStatus::HARDWARE_CONNECTED );
        heartBeat->setBattery( "99" );
        heartBeat->setDevCode( "Test_Dev_mxq" );
        heartBeat->setDevType( "9" );

        heartBeat->httpRequest();

        connect( heartBeat, &CHttpHeartBeat::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "request failed...";
            }else{
                qDebug() << "request success...";
            }
        });
}

void CMainWidget::syncUserInfo()
{
        CHttpSyncUserInfo *syncUserInfo = new CHttpSyncUserInfo( "654564" );
        syncUserInfo->httpRequest();

        connect( syncUserInfo, &CHttpSyncUserInfo::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "request failed...";
            }else{
                qDebug() << "request success...";
                qDebug() << "size = " << syncUserInfo->userInfoCount();
                qDebug() << syncUserInfo->getSingleInfo( 50, SYNCUSERINFO_KEY_NAME );
            }
        });
}

void CMainWidget::upLoadCommonScore()
{
        CHttpUpLoadCommonScore *upLoadCommonScore = new CHttpUpLoadCommonScore();
        upLoadCommonScore->setUserId( "339" );
        upLoadCommonScore->setScoreType( testType::examType );
        upLoadCommonScore->setTestItem( TEST_ITEM::TEST_ITEM_VC );
        upLoadCommonScore->setResult( "1660" );
        upLoadCommonScore->setRecordTime( QString::number( upLoadCommonScore->currentTimeStamp() ) );
        upLoadCommonScore->setDeviceCode( "FHL10086" );
        upLoadCommonScore->setDeviceType( DEV_TYPE::DEV_TYPE_VC );

        upLoadCommonScore->httpRequest();
        connect( upLoadCommonScore, &CHttpUpLoadCommonScore::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "request failed...";
            }else{
                qDebug() << "upLoadCommonScore -> request success...";
            }
        });
}

void CMainWidget::upLoadBodyScore()
{
        CHttpUpLoadBodyScore *upLoadBodyScore = new CHttpUpLoadBodyScore();

        upLoadBodyScore->setUserId( "339" );
        upLoadBodyScore->setRecordTime( QString::number(upLoadBodyScore->currentTimeStamp()) );
        upLoadBodyScore->setDeviceCode( "XTC10086" );
        upLoadBodyScore->setDeviceType( DEV_TYPE::DEV_TYPE_BODY );

        upLoadBodyScore->setBMI( "66" );
        upLoadBodyScore->setTBW( "67" );
        upLoadBodyScore->setVFA( "68" );
        upLoadBodyScore->setWHR( "69" );
        upLoadBodyScore->setTBMM( "70" );
        upLoadBodyScore->setWBIS( "71" );
        upLoadBodyScore->setheight( "160" );
        upLoadBodyScore->setweight( "45" );
        upLoadBodyScore->setFatRate( "56" );
        upLoadBodyScore->setHeadFat( "72" );
        upLoadBodyScore->setHeadMuscle( "73" );
        upLoadBodyScore->setHeadWeight( "74" );

        upLoadBodyScore->httpRequest();

        connect( upLoadBodyScore, &CHttpUpLoadBodyScore::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "CHttpUpLoadBodyScore -> request failed...";
            }else{
                qDebug() << "CHttpUpLoadBodyScore -> request success...";
            }
        });
}

void CMainWidget::queryHistory()
{
        CHttpQueryHistoryScore *queryHistory = new CHttpQueryHistoryScore();
        queryHistory->setUserId( "339" );
        queryHistory->setTestItem( TEST_ITEM::TEST_ITEM_VC );
        queryHistory->setTimeInterval( queryTimeInterval::recent_three_month );
        queryHistory->setTestScoreType( testType::examType );

        queryHistory->httpRequest();

        connect( queryHistory, &CHttpQueryHistoryScore::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "request failed...";
                qDebug() << queryHistory->getErrorString();
            }else{
                qDebug() << "CHttpQueryHistoryScore -> request success...";
                qDebug() << queryHistory->getSingleRet( 0, QUERYHISTORY_RECORDTIME );
            }
        });
}

void CMainWidget::syncClassInfo()
{
        CHttpSyncClassInfo *syncClassInfo = new CHttpSyncClassInfo();
        syncClassInfo->httpRequest();

        connect( syncClassInfo, &CHttpQueryHistoryScore::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "request failed...";
            }else{
                qDebug() << "CHttpSyncClassInfo -> request success...";
                qDebug() << syncClassInfo->getSingleRet( 0, SYNCCLASSINFO_KEY_NAME );
            }
        });
}

void CMainWidget::userIdentify()
{
        CHttpUserIdentify *userIdentify = new CHttpUserIdentify( m_face );
        userIdentify->httpRequest();

        connect( userIdentify, &CHttpUserIdentify::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "CHttpUserIdentify -> request failed...";
            }else{
                qDebug() << "CHttpUserIdentify -> request success...";
                qDebug() << "user name = " << userIdentify->getUserInfoByKey( USERIDENTIFY_KEY_NAME );
            }
        });
}

void CMainWidget::touristUsageRecord()
{
        CHttpTouristRecord *touristRecord = new CHttpTouristRecord();
        touristRecord->setDeviceCode( "FHL10086" );
        touristRecord->setDeviceType( DEV_TYPE::DEV_TYPE_VC );
        touristRecord->setRecordTime( QString::number( touristRecord->currentTimeStamp()) );

        touristRecord->httpRequest();

        connect( touristRecord, &CHttpTouristRecord::sigRequestRetAvailable, [=](bool ok){
            if( !ok ){
                qDebug() << "CHttpTouristRecord -> request failed...";
                qDebug() << "error string == " << touristRecord->getErrorString();
            }else{
                qDebug() << "CHttpTouristRecord -> request success...";
            }
        });
}

void CMainWidget::downLoadFile()
{
        CHttpDownLoadFile *downLoader = new CHttpDownLoadFile();
        downLoader->startDownLoad( m_bodyUrl );
}

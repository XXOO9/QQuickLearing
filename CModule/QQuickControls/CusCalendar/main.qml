import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./JavaScript/CommonDefine.js" as Common

ApplicationWindow {
    id: root
    visible: true
    width: Common.perColumnWidth * 7 * factor
    height: Common.perRowHeight * 8 * factor
    title: qsTr("Hello World")

    property real factor: 1
    property QtObject calendarCmpObj: null
    property QtObject detailCmpObj: null
    //    flags: Qt.FramelessWindowHint | Qt.Window

    StackView{
        id: mainStackView
        width: Common.perColumnWidth * 7 * factor
        height: Common.perRowHeight * 8 * factor
        anchors.centerIn: parent
        padding: 0
        clip: true
        initialItem: calendarCmp
    }

    Component{
        id: calendarCmp
        CusTestCalendar{
            id: calendarItem
            onSigQueryDetailDateInfo: {
                Common.tmpCurHour = hour
                Common.tmpCurTimeCnt = timeCnt
                mainStackView.push( detailInfoPageCmp )
            }
        }
    }


    Component{
        id: detailInfoPageCmp
        CusDetailInfo{
            id: detailInfoItem
            onSigRefreshHourInfo: {
                Common.tmpCurHour = hour
                Common.tmpCurTimeCnt = timeCnt
                console.log( 'year = ' + Common.curYear + ' month = ' + Common.curMonth )

                let targetDate = Common.curYear +
                    String( Common.curMonth ).padStart( 2, '0' ) +
                    String( Common.curDateIndex ).padStart( 2, '0' )

                mainStackView.get( 0 ).setTargetDateIndexInfo( Common.curDateIndex, hour, timeCnt )
                let ok = InterAction.setTargetDateHourInfo( targetDate, hour, timeCnt )
                mainStackView.pop()
            }
        }
    }

}

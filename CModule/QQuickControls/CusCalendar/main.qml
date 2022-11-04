import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./JavaScript/CommonDefine.js" as Common

ApplicationWindow {

    visible: true
    width: Common.perColumnWidth * 7 * factor
    height: Common.perRowHeight * 8 * factor
    title: qsTr("Hello World")

    property real factor: 1
    //    flags: Qt.FramelessWindowHint | Qt.Window

    StackView{
        id: mainStackView
        width: Common.perColumnWidth * 7 * factor
        height: Common.perRowHeight * 7 * factor
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
                mainStackView.push( detailInfoPageCmp )
            }
        }
    }


    Component{
        id: detailInfoPageCmp
        CusDetailInfo{
            id: detailInfoItem
            onSigRefreshHourInfo: {

            }
        }
    }

}

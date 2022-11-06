import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./Components/"
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
    flags: Qt.FramelessWindowHint | Qt.Window

    Component.onCompleted: {
        if( InterAction.isNewUser() ){
            newUserNameInputPop.open()
        }
    }

    StackView{
        id: mainStackView
        width: Common.perColumnWidth * 7 * factor
        height: Common.perRowHeight * 8 * factor
        anchors.centerIn: parent
        padding: 0
        clip: true
        initialItem: calendarCmp
    }

    PopTipsTemplate{
        id: newUserNameInputPop
        closePolicy: Popup.NoAutoClose
        anchors.centerIn: parent
        Column{
            spacing: 10 * factor
            anchors.centerIn: parent
            Text {
                text: '给自己起个帅气的名字吧!'
                color: 'white'
                font{ family: "Microsoft YaHei"; pixelSize: 15 * factor }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }

            CusTextInput{
                id: newNmaeInput
                width: parent.width * 0.7
                height: parent.height * 0.3
                anchors.horizontalCenter: parent.horizontalCenter
            }

            CusClickBtn{
                width: parent.width * 0.4
                height: parent.height * 0.3
                radius: 15 * factor
                anchors.horizontalCenter: parent.horizontalCenter
                onSigClicked: {
                    InterAction.setUserName( newNmaeInput.text )
                    newUserNameInputPop.close()
                }
            }
        }
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

    function moveWindow( tarX, tarY ){
        root.x += tarX
        root.y += tarY
    }

}

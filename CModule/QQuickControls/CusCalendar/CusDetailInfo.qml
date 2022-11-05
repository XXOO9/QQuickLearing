import QtQuick 2.12
import QtQuick.Controls 2.12
import "./"
import "./Components/"
import "./JavaScript/CommonDefine.js" as Common

Item {
    id: root
    width: Common.perColumnWidth * 7 * factor
    height: Common.perRowHeight * 7 * factor

    signal sigRefreshHourInfo( var hour, var timeCnt )

    property alias hourText: hourTextInput.text
    property alias timeCntText: timeCntTextInput.text

    Component.onCompleted: {
        hourTextInput.text = Common.tmpCurHour
        timeCntTextInput.text = Common.tmpCurTimeCnt
    }

    Component.onDestruction: {
        console.log( 'date detail page destruct...' )
    }

    Rectangle{
        id: bkg
        anchors.fill: parent
        color: 'gray'
        MouseArea{
            anchors.fill: parent
            onDoubleClicked: mainStackView.pop()
        }
    }

    Text {
        id: curDate
        Component.onCompleted: {
            text = Common.curYear + '年' + ' ' + Common.curMonth + '月' + ' ' + Common.curDateIndex + '日'
        }

        font{ family: "Microsoft YaHei"; pixelSize: 18 * factor }
        anchors{ top: parent.top; topMargin: 10 * factor; left: parent.left; leftMargin: 20 * factor }
    }

    Row{
        spacing: 20 * factor
        anchors{ top: parent.top; topMargin: 50 * factor; left: parent.left; leftMargin: 20 * factor }
        TextField{
            id: hourTextInput
            width: root.width * 0.3
            placeholderText: '实际时长'
            height: Common.perRowHeight * 0.3
            background: Rectangle{
                border.color: 'red'
            }
            onTextChanged: calculate( hourTextInput.text, timeCntTextInput.text )
        }

        Text {
            text: 'X'
            font.family: "Microsoft YaHei"
            font.pixelSize: 25 * factor
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        TextField{
            id: timeCntTextInput
            width: root.width * 0.2
            placeholderText: '倍率'
            height: Common.perRowHeight * 0.3
            background: Rectangle{
                border.color: 'red'
            }
            onTextChanged: calculate( hourTextInput.text, timeCntTextInput.text )
        }

        Text {
            text: '='
            font.family: "Microsoft YaHei"
            font.pixelSize: 25 * factor
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: retText
            text: '?'
            font.family: "Microsoft YaHei"
            font.pixelSize: 25 * factor
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

    }

    CusClickBtn{
        id: saveBtn
        width: Common.perColumnWidth
        height: Common.perRowHeight * 0.5
        radius: 20 * factor
        z: 20
        anchors{ horizontalCenter: parent.horizontalCenter; bottom: parent.bottom; bottomMargin: 20 * factor }
        onSigClicked: sigRefreshHourInfo( hourTextInput.text, timeCntTextInput.text )
    }


    function calculate( hours, timeCnt ){

        retText.text = ( hours * timeCnt ).toFixed( 5 )
    }

}

import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: root

    implicitWidth: 236
    implicitHeight: 500

    readonly property int maxCandidateCount: 5
    readonly property real perRowHeight: 30

    //输入属性
    property string bkgColor: "#666666"
    property string bkgBorderColor: "#1A292D"
    property alias tips: textArea.placeholderText
    property alias tipsColor: textArea.placeholderTextColor

    //候选属性
    property var candidateObj
    property alias candidateModel: candidateView.model
    property string fontFamily: "Microsoft YaHei"

    TextField{
        id: textArea

        implicitWidth: parent.width
        implicitHeight: 30
        anchors{ top: parent.top; horizontalCenter: parent.horizontalCenter }

        background: Rectangle{
            anchors.fill: parent
            color: "red"
            border.color: bkgBorderColor
        }

        onTextEdited: timer.restart()

        Timer{
            id: timer
            interval: 1500
            onTriggered: {
                candidateView.visible = true
                candidateModel.setFilterWildcard( textArea.text + "*" )
            }
        }
    }

    ListView{
        id: candidateView
//        visible: false
        width: root.width
        clip: true
        height: count >= maxCandidateCount ? maxCandidateCount * perRowHeight : count * perRowHeight
        delegate: candidateContent
        anchors{ top: textArea.bottom; horizontalCenter: parent.horizontalCenter }
    }



    Component{
        id: candidateContent
        Rectangle{
            width: root.width
            height: perRowHeight
            color: bkgColor
            Text {
                text: display
                font{ family: fontFamily; pixelSize: 16 }
                anchors.centerIn: parent
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onEntered: parent.color = "skyblue"
                onExited: parent.color = bkgColor
                onClicked: {
                    console.log( "ret = " + display + " index = " + index )
                    candidateView.visible = false
                }
            }
        }
    }
}



import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.VirtualKeyboard 2.4
import QtQuick.VirtualKeyboard.Settings 2.2


Window {
    id: window
    visible: true
    width: 600
    height: 480
    title: qsTr("Hello World")

    Button{
        anchors.top: textInpuit.bottom
        anchors.horizontalCenter: textInpuit.horizontalCenter
        onClicked: {
            console.log( textInpuit.text )
        }
    }

    TextField{
        id: textInpuit
        implicitWidth: 200
        implicitHeight: 50
        placeholderText: "输入密码"
        placeholderTextColor: "red"
        font{ pixelSize: 30 }
        anchors.centerIn: parent
        background: Rectangle{
            id:backRect
            anchors.fill: parent
            color: "lightgreen"
        }
        onPressed: {
            backRect.border.color = "red"
        }
        onReleased: {
            backRect.border.color = "black"
        }
    }

    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}

﻿import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button{
        id: btn1
        text: "1"
        onClicked: {
            InterAction.testFunc()
        }
    }
}

﻿import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 800
    height: 800
    visible: true
    title: qsTr("Hello World")

    CusPieCircle{

        anchors.centerIn: parent
    }

    Button{

    }
}

﻿import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
//        test()
    }


    Button{
        id: btn1
        text: "暂停"
        onClicked: {
            ThreadMgr.stopThread()
        }
    }

    Button{
        id: btn2
        anchors.top: btn1.bottom
        text: "开始"
        onClicked: {
            ThreadMgr.timerControler( true )
        }
    }

    Button{
        id: btn3
        anchors.top: btn2.bottom
        text: "结束"
        onClicked: {
            ThreadMgr.killThread()
        }
    }
    Button{
        id: btn4
        anchors.top: btn3.bottom
        text: "结束"
        onClicked: {
            ThreadMgr.deletePrinter()
        }
    }


    function test(){
        let tmp = "4.0+4.2";
        let a = tmp.split( "+" )
        console.log( a[0] + "---" + a[1] )
    }
}

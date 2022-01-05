﻿import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import com.TME.CDataModel 1.0

Window {
    visible: true
    width: 800
    height: 800
    title: qsTr("Hello World")

    onWidthChanged: {
        m_tableView.forceLayout()
    }

    Button{
        id: btn1
        text: "1"
        onClicked: {
            Model.testfunc1()
            Model.testfunc2()
            Model.testfunc3()
            Model.testfunc4()
            Model.testfunc5()
        }
    }

    Button{
        text: "2"
        anchors.top: btn1.bottom
        onClicked: {
            Model.testfunc6()
        }
    }

    CustTableView{
        anchors.centerIn: parent
    }
}
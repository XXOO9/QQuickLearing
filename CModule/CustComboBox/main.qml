import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "."

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    ListModel{
        id: list
        ListElement{ name: "ppc" }
        ListElement{ name: "zmc" }
        ListElement{ name: "cyq" }
        ListElement{ name: "bpk" }
        ListElement{ name: "llb" }
        ListElement{ name: "gwq" }
        ListElement{ name: "slf" }
        ListElement{ name: "xhy" }
    }

    CusComboBox{
        model: list
        anchors{ top: parent.top; horizontalCenter: parent.horizontalCenter }
    }
}

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: root
    visible: true
    width: 1000
    height: 1000
    title: qsTr("Hello World")

    Component.onCompleted: {
        let obj = root.findChild( root, "list" )
        console.log( obj.count )
    }

    ListModel{
        id:list
        objectName: "list"
        ListElement{ index: 0 }
        ListElement{ index: 1 }
        ListElement{ index: 2 }
    }

    ListView{
        width: 150
        height: 800

        spacing: 10
        anchors{ top: parent.top; left: parent.left }
        model: list
        delegate: Qt.createComponent( "qrc:/CusDropArea.qml" )
    }

    CusDragRect{
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
    }



}

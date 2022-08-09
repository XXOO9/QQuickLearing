import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 900
    title: qsTr("Hello World")



//    CusListView{
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.left: parent.left
//    }

    CusDropArea{
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }

    CusDragRect{
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
    }


}

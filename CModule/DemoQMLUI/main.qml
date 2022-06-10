import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Rectangle{
        width: 200
        height: width
        anchors.centerIn: parent
        color: "gray"
        Text{
            anchors.left: parent.left
            width: 150
            height: width
            wrapMode: Text.Wrap //换行
            text: "444444444444444444444444444444444444444444444444444444444"
        }

        //        Text {
        //            id: str
        //            width: 450
        //            Component.onCompleted: {
        //                console.log( "ret = " + str.contentWidth)

        //            }

        //            text: "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222"
        //            anchors.centerIn: parent
        //        }
    }
}

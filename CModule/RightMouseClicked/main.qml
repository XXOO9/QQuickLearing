import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {
            if( mouse.button === Qt.LeftButton ){
                console.log( "LeftButton clicked" )
            }else if( mouse.button === Qt.RightButton ){
                console.log( "RightButton clicked" )
            }
        }
    }

}

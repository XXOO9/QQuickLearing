import QtQuick 2.12
import QtQuick.Window 2.12
import MyEnums.cmopany.TME 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property real val: 6

    Component.onCompleted: {
        console.log( typeof( val ) )
        console.log( ProjectEnums.SaturyDay === val )
    }
}

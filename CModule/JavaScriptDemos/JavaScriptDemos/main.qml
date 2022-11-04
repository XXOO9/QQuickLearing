import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./Test.js" as Test
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        console.log( "ret = " + Test.xtc.a )
    }

    Button{
        onClicked: str.func_replaceChar()
    }

    StringFuncs{
        id: str
    }
}

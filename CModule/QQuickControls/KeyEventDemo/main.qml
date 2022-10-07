import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    TextField{
        id: input
        focus: false
        Keys.onPressed: console.log( "key1 = " + event.key, " " + input.text )
        onFocusChanged: console.log( "text input's focus changed to " + focus )
    }

    CusClickBtn{
        id: btn1
        anchors.top: input.bottom
        colorRect: activeFocus ? "red" : "green"
//        focus: true

        Keys.enabled: true

        Keys.onPressed: console.log( "key2 = " + event.key, " " + input.text )
        onFocusChanged: console.log( "btn1 's focus changed to " + focus )

        MouseArea{
            anchors.fill: parent
            onClicked: {
                input.focus = false
                btn1.focus = true
            }
        }
    }

    CusClickBtn{
        id: btn2
        anchors.top: btn1.bottom
        focus: true

        colorRect: activeFocus ? "red" : "green"
        Keys.enabled: true

        Keys.onPressed: console.log( "key3 = " + event.key, " " + input.text )
    }

    CusClickBtn{
        anchors.top: btn2.bottom
        focus: true

        colorRect: activeFocus ? "red" : "green"
        Keys.enabled: true

        Keys.onPressed: console.log( "key3 = " + event.key, " " + input.text )
    }



}

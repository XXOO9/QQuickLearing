import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button{
        onClicked: {
//            pop.enabled = false
//            pop.focus = false
            pop.open()
            closeTimer.start()
        }
    }

    Timer{
        id:closeTimer
        interval: 3000
        onTriggered: {
            pop.close()
        }
    }


    Popup{
        id:pop
        width: 300
        height: width
        modal: true
        anchors.centerIn: parent
        //设置了这个属性过后，就只能后台关闭窗口
        closePolicy: Popup.NoAutoClose
        contentItem: Rectangle{
            width: 300
            height: width
            anchors.centerIn: parent
            color: "red"
        }
        MouseArea{
            anchors.fill: parent
//            enabled: pop.opened ? false : true
            onClicked: {
                console.log( "clicked..." )
            }
        }

        onClosed: {
            console.log( "closed" )
        }
    }

}

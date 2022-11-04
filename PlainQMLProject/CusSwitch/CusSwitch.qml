import QtQuick 2.12
import QtQuick.Controls 2.12

Switch {
    id: control
    text: qsTr("Switch")

    //      background: Rectangle{
    //          color: "lightyellow"
    //      }

    indicator: Rectangle {
        implicitWidth: 48
        implicitHeight: 26
        x: control.leftPadding
        y: parent.height / 2 - height / 2

        radius: 13
        color: control.checked ? "green" : "#ffffff"
        border.color: control.checked ? "green" : "#cccccc"

        //小圆点
        Rectangle {
            id : smallRect
            width: 26
            height: 26
            radius: 13
            color: control.down ? "#cccccc" : "#ffffff"
            border.color: control.checked ? (control.down ? "#17a81a" : "#21be2b") : "#999999"

            //改变小圆点的位置
            NumberAnimation on x{
                to: smallRect.width
                running: control.checked ? true : false
                duration: 200
            }

            //改变小圆点的位置
            NumberAnimation on x{
                to: 0
                running: control.checked ? false : true
                duration: 200
            }
        }
    }

    //要显示的文本
    contentItem: Text {
        text: control.checked.toString()
        font.pixelSize: 50
        //鼠标按下时  control.down
        color: control.down ? "green" : "red"
        verticalAlignment: Text.AlignVCenter
        anchors.left: indicator.right
    }
}


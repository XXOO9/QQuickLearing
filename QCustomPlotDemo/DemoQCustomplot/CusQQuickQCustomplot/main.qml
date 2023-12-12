import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import com.TME.CusQQuickPainterItem 1.0


ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


//    Rectangle{
//        anchors.fill: parent
//        color: "gray"
//    }

    CusPaninter{
        id: cusPainter
        width: 300
        height: 300
        anchors.top: parent.top
        anchors.left: parent.left
        Component.onCompleted: {
            cusPainter.init()
        }
    }
}

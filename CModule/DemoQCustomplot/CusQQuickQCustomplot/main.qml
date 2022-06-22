import QtQuick 2.15
import QtQuick.Window 2.15
import com.TME.CusQQuickPainterItem 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    CusPaninter{
        id: cusPainter
        Component.onCompleted: {
            cusPainter.drawCircle()
        }

        width: 150
        height: 150
        anchors.centerIn: parent
    }
}

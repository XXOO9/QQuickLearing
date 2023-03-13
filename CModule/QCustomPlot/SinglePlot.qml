import QtQuick 2.0
import CustPlot 1.0
Item{
    id: root

    width: 400
    height: width
    CustPlotItem{
        Component.onCompleted: {
            startTimer()
        }

        anchors.fill: parent


    }
}

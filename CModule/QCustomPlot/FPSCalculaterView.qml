import QtQuick 2.12
import QtQuick.Window 2.12
import CustPlot 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import CustPlotMulti 1.0

Item {
    Text {
        id: fpsCounter
        text: "FPS: Calculating..."
        font.pixelSize: 80
        color: 'red'
        anchors.centerIn: parent
        z: 5
    }

    property var lastTime: new Date().getTime()  // 上一帧的时间戳


    function updateFPS() {
        // 计算时间间隔
        var now = new Date().getTime();
        var elapsed = now - lastTime;
        lastTime = now;

        // 计算帧速率
        var fps = 1000 / elapsed;
        fpsCounter.text = "FPS: " + fps.toFixed(0);
    }

    Timer {
        interval: 1
        running: true
        repeat: true
        onTriggered: {
            updateFPS();
        }
    }

    Grid{
        anchors.fill: parent
        padding: 0
        rows: 2
        columns: 2
        Repeater{
            model: 1
            delegate:     CustPlotItemMulti{
                width: root.width / 2
                height: root.height / 2
                Text {
                    text: index
                    font.pixelSize: 50
                    color: 'red'
                }
            }
        }
    }
}

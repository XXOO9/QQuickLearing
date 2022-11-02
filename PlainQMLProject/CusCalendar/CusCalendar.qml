import QtQuick 2.12
import QtQuick.Controls 2.12

Item{
    id: root

    width: 400
    height: 600

    readonly property real perColumnWidth: 50
    readonly property real perRowHeight: 50
    property real localFactor: 1

    Rectangle{
        anchors.fill: parent
        color: 'red'
    }


    Row{
        id: weekDayRow
        anchors{ horizontalCenter: parent.horizontalCenter; top: parent.top }

        Repeater{
            model: [ '日', '一', '二', '三', '四', '五', '六' ]
            delegate: weekDayCmp
        }
    }

    GridView{
        clip: true
        width: perColumnWidth * 7
        height: perRowHeight * 6
        cellWidth: perColumnWidth
        cellHeight: perRowHeight
        model: generateTestData()
        delegate: weekDayCmp
        anchors{ top: weekDayRow.bottom; left: weekDayRow.left }
    }

    Component{
        id: weekDayCmp
        Rectangle{
            width: perColumnWidth
            height: perRowHeight
            border.color: 'black'
            Text {
                text: modelData
                font{ family: "Microsoft YaHei"; pixelSize: 20 * localFactor; bold: true }
                anchors.centerIn: parent
            }
        }
    }

    function generateTestData(){
        let retArray = []

        for( let index = 0; index < 100; index++ ){
            retArray.push( index )
        }

        return retArray
    }
}

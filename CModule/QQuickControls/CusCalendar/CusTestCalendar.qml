import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    width: 800
    height: 500

    property real localFactor: 1

    readonly property real perColumnWidth: 70 * localFactor
    readonly property real perRowHeight: 40 * localFactor

    Rectangle{
        anchors.fill: parent
        color: 'red'
    }

    Item{
        id: dateAdjustArea
        width: perColumnWidth * 7
        height: perRowHeight
        anchors{ top: parent.top; horizontalCenter: parent.horizontalCenter }
        Rectangle{
            anchors.fill: parent
            color: 'green'
        }

        Row{

        }

    }

    Item{
        id: calendarArea
        width: perColumnWidth * 7
        height: perRowHeight * 6
        anchors{ top: dateAdjustArea.bottom; left: dateAdjustArea.left }

        Rectangle{
            anchors.fill: parent
            color: 'black'
        }

        Row{
            id: dayWeekRow
            anchors{ top: parent.top; left: parent.left }
            Repeater{
                model: [ '一', '二', '三', '四', '五', '六', '日' ]
                delegate: weekDayCmp
            }
        }

        ListView{
            id: monthListArea
            width: perColumnWidth * 7
            height: perRowHeight * 5
            delegate: dateArea
            model: 1
            anchors{ top: dayWeekRow.bottom; left: dayWeekRow.left }
        }
    }





    Component{
        id: dateArea
        // 5 * 7 的网格
        GridView{
            width: perColumnWidth * 7
            height: perRowHeight * 5
            cellWidth: perColumnWidth
            cellHeight: perRowHeight
            model: test()
            delegate: perRectCmp
        }
    }



    function test(){
        let ret = []

        ret.push( 0 )
        ret.push( 0 )
        ret.push( 0 )
        for( let index = 1; index <= 31; index++ ){
            ret.push( index )
        }

        return ret
    }

    Component{
        id: weekDayCmp
        Rectangle{
            id: rect
            visible: modelData !== 0
            width: perColumnWidth
            height: perRowHeight
            Text {
                text: modelData
                font{ family: "Microsoft YaHei"; pixelSize: 20 * localFactor; bold: true }
                anchors.centerIn: parent
            }
        }
    }

    Component{
        id: perRectCmp
        Rectangle{
            id: rect
            visible: modelData !== 0
            width: perColumnWidth
            height: perRowHeight
            color: 'gray'
            Text {
                text: modelData
                font{ family: "Microsoft YaHei"; pixelSize: 20 * localFactor; bold: true }
                anchors.centerIn: parent
            }
            MouseArea{
                id: rectMouse
                hoverEnabled: true
                anchors.fill: parent
                onEntered: {
                    rect.border.width = 2 * localFactor
                    rect.border.color = 'blue'
                    rect.color = 'green'
                }

                onExited: {
                    rect.border.width = 0 * localFactor
                    rect.color = 'gray'
                }
            }
        }
    }

    Component{
        id: adjustNumberCmp
        Row{
            id: adjustRow
            property real adjustNumber: 2022
            property string adjustUnit: '年'
            Image {
                id: reduceYear
                rotation: 180
                source: "qrc:/resource/arrow.png"
            }

            Text {
                text: adjustRow.adjustNumber + adjustRow.adjustUnit
                font{ family: "Microsoft YaHei"; pixelSize: 20 * localFactor }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Image {
                id: addYear
                source: "qrc:/resource/arrow.png"
            }
        }
    }
}

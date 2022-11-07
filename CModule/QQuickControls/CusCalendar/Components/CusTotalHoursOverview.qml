import QtQuick 2.12
import QtQuick.Controls 2.12
import "../"
Item {
    id: root
    readonly property string unit: 'h'
    property real hours: 12
    property real calculateHours: 12
    property real costHours: -1

    Column{
        anchors.centerIn: parent
        spacing: 20 * factor

        Row{
            Text {
                text: '总时长:'
                font{ family: "Microsoft YaHei"; pixelSize: 15 * factor }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: totalHoursText
                text: hours + unit
                font{ family: "Microsoft YaHei"; pixelSize: 15 * factor }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Row{
            Text {
                text: '结算后:'
                font{ family: "Microsoft YaHei"; pixelSize: 15 * factor }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: calculateHourText
                text: calculateHours + unit
                font{ family: "Microsoft YaHei"; pixelSize: 15 * factor }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Row{
            Text {
                text: '请假时长:'
                font{ family: "Microsoft YaHei"; pixelSize: 15 * factor }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: costHousrs
                text: costHours + unit
                font{ family: "Microsoft YaHei"; pixelSize: 15 * factor }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }



    }
}

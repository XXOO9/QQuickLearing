import QtQuick 2.12
import QtQuick.Controls 2.12

Item{
    id: root

    width: 200
    height: 150

    property real adjustNumber: 2022
    property string adjustUnit: '年'

    property real max: 2030
    property real min: 2020

    Rectangle{
        visible: false
        anchors.fill: parent
        color: 'black'
    }

    Row{
        id: adjustRow
        anchors.centerIn: parent
        Image {
            id: reduceYear
            rotation: 180
            source: "qrc:/resource/arrow.png"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if( adjustNumber > min ){
                        adjustNumber--
                    }
                }
            }
        }

        Text {
            text: adjustNumber + adjustUnit
            font{ family: "Microsoft YaHei"; pixelSize: 20 * localFactor }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Image {
            id: addYear
            source: "qrc:/resource/arrow.png"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if( adjustNumber < max ){
                        adjustNumber++
                    }
                }
            }
        }
    }
}

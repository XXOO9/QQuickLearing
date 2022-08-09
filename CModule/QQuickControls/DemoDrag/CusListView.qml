import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: root
    width: 400
    height: 600

    property var arr: [ 1, 2, 3 ]

    ListView{
        id: view
        width: 400
        height: 600
        model: arr

        anchors.centerIn: parent


        delegate: Rectangle{

            color: "black"
            border.color: "white"
            width: view.width
            height: 100

            Text {
                color: "white"
                text: modelData
                anchors.centerIn: parent
                font.pixelSize: 20
            }
        }

    }
}

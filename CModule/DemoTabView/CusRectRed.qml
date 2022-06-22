import QtQuick 2.12
import QtQuick.Controls 2.12
Item {
    id: root
    width: 100
    height: width

    property string rectColor: "red"
    Rectangle{
        anchors.fill: parent
        color: rectColor
    }
}

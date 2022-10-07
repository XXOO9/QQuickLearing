import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    width: 150
    height: width
    property alias colorRect: rect.color
    Rectangle{id: rect
        anchors.fill: parent
        color: "skyblue"
    }
}

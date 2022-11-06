import QtQuick 2.12
import QtQuick.Controls 2.12
import "../"
Popup{
    id: root
    width: 250 * factor
    height: 150 * factor
    modal: true

    property alias bkgColor: bkgRect.color

    background: Rectangle{
        id: bkgRect
        color: 'gray'
        anchors.fill: parent
        radius: 20 * factor
    }
}

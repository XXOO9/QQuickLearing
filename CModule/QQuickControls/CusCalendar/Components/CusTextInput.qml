import QtQuick 2.12
import QtQuick.Controls 2.12
import "../"

TextField{
    id: root
    width: 250 * factor
    height: 50 * factor

    background: Rectangle{
        anchors.fill: parent
        radius: 15 * factor
        border{ width: 1.5 * factor; color: 'white' }
    }
}

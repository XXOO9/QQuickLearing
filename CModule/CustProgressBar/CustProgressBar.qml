import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    width: 400
    height: 100

    property real loadPersent: 0.0
    property real startWdith: 0.0
    property real tarGetWidth: 0.0


    Rectangle{
        id: bottomRect
        anchors.fill: parent
        radius: 30
        color: "lightgreen"
    }

    Rectangle{
        id: topRect
        width: loadPersent * root.width
        height: parent.height
        color: "red"
        radius: 30

        PropertyAnimation on width{
            id: animaltion
            from: startWdith
            to: tarGetWidth
            duration: 500

            onFinished: {
                startWdith = topRect.width
            }
        }
    }

    function setLoadPersent( persent ){
        tarGetWidth = persent * root.width
        animaltion.start()
    }
}

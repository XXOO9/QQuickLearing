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

    Column{
        id: menuElementRectColumn
        spacing: 10 * factor
        anchors{ top: parent.top; topMargin: 20 * factor }
        Component.onCompleted: {
            let i = 3
            while( i-- ){
                menuElementCmp.createObject( menuElementRectColumn )
            }
        }
    }

    Image {
        id: closeBtn
        width: 90 * factor
        height: width
        source: "qrc:/resource/close.png"
        anchors{ bottom: parent.bottom; horizontalCenter: parent.horizontalCenter }
        MouseArea{
            anchors.fill: parent
            onClicked: close()
        }
    }

    Component{
        id: menuElementCmp
        Rectangle{
            id: menuElementRect
            width: 200 * factor
            height: 50 * factor
            radius: 10 * factor
            color: 'mediumseagreen'
            anchors{ left: parent.left; leftMargin: -width * 0.7 }

            PropertyAnimation{
                id: mousEnterAnimation
                target: menuElementRect
                property: 'anchors.leftMargin'
                from: -menuElementRect.width * 0.7
                to: -menuElementRect.width * 0.3
                duration: 300
                loops: 1
            }

            PropertyAnimation{
                id: mousExistAnimation
                target: menuElementRect
                property: 'anchors.leftMargin'
                from: menuElementRect.anchors.leftMargin
                to: -menuElementRect.width * 0.7
                duration: 300
                loops: 1
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onEntered: mousEnterAnimation.start()
                onExited: mousExistAnimation.start()
            }
        }
    }
}

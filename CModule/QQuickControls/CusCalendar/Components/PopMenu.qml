import QtQuick 2.12
import QtQuick.Controls 2.12
import "../"
import "../SubPages/"

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
        z: 5
        Component.onCompleted: {
            menuElementCmp.createObject( menuElementRectColumn,
                                        { 'btnIcon': 'qrc:/resource/question.png', 'btnText': '是否有很多问号', 'btnIndex': 0 } )

            menuElementCmp.createObject( menuElementRectColumn,
                                        { 'btnIcon': 'qrc:/resource/bug.png', 'btnText': '如果发现了Bug', 'btnIndex': 1 } )

            menuElementCmp.createObject( menuElementRectColumn,
                                        { 'btnIcon': 'qrc:/resource/info.png', 'btnText': '关于这个玩意儿', 'btnIndex': 2 } )
        }
    }

    Loader{
        id: menuLoader
        width: 350 * factor
        height: parent.height * 0.8
        source: 'qrc:/SubPages/PageLegend.qml'
        anchors{ top: parent.top; topMargin: 20 * factor; right: parent.right; rightMargin: 50 * factor }

        onSourceChanged: comingAnimation.start()

        ParallelAnimation{
            id: comingAnimation
            loops: 1
            PropertyAnimation{ target: menuLoader; property: 'opacity'; from: 0; to: 1; duration: 200 }
            PropertyAnimation{ target: menuLoader; property: 'anchors.rightMargin'; from: 0; to: 50; duration: 200 }
        }

        function turnPage( pageIndex ){
            switch( pageIndex ){
            case 0:
                menuLoader.source = 'qrc:/SubPages/PageLegend.qml'
                break

            case 1:
                menuLoader.source = 'qrc:/SubPages/PageBugReport.qml'
                break

            case 2:
                menuLoader.source = 'qrc:/SubPages/PageAboutThis.qml'
                break
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
            property alias btnIcon: elementIcon.source
            property alias btnText: elementText.text
            property real  btnIndex: -1
            width: 300 * factor
            height: 50 * factor
            radius: 10 * factor
            color: 'mediumseagreen'
            anchors{ left: parent.left; leftMargin: -width * 0.7 }

            Text {
                id: elementText
                text: '是否有很多问号'
                color: 'white'
                font{ family: "Microsoft YaHei"; pixelSize: 20 * factor }
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                anchors{ verticalCenter: elementIcon.verticalCenter; right: elementIcon.left; rightMargin: 10 * factor }
            }

            Image {
                id: elementIcon
                source: "qrc:/resource/question.png"
                width: menuElementRect.height * 0.9
                height: width
                anchors{ verticalCenter: parent.verticalCenter; right: parent.right; rightMargin: 20 * factor }
                z: 5
            }

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
                id: elementBtnMous
                anchors.fill: parent
                hoverEnabled: true
                onEntered: mousEnterAnimation.start()
                onExited: mousExistAnimation.start()
                onPressed: menuElementRect.color = 'green'
                onReleased: menuElementRect.color = 'mediumseagreen'
                onClicked: menuLoader.turnPage( menuElementRect.btnIndex )
            }
        }
    }
}

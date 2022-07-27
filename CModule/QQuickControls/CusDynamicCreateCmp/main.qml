import QtQuick 2.12
import QtQml 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./Assistant.js" as Assistant

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property var obj

    Item {
        id: root
        Component.onCompleted: {
            console.log( "root width = ", width, " height = ", height )
        }

        onWidthChanged: console.log( " width changed, root width = ", width, " height = ", height )
        onHeightChanged: console.log( " height changed, root width = ", width, " height = ", height )

        Rectangle{
            anchors.fill: parent
            color: "gray"
        }

        anchors.centerIn: parent
    }


    Button{
        id: btn1
        anchors.top: parent.top
        onClicked: createObj()
    }

    Button{
        id: btn2
        anchors.left: btn1.right
        anchors.leftMargin: 5
        onClicked: Assistant.createCmp()

    }


    Component{
        id: blueRect
        Rectangle{
            width: 200
            height: width
            color: "blue"

            MouseArea{

                anchors.fill: parent
                onClicked: insideFunc( blueRect )
            }
        }
    }

    function createObj(){
        if( Assistant.tmpCmp.status === Component.Ready ){
            Assistant.tmpCmp.createObject()
        }else{
            console.log( "nnnnnn" )
        }
    }

    function createCmp(){
        let url = "qrc:/CusRect.qml"
        Assistant.tmpCmp = Qt.createComponent( url, Component.Asynchronous, root )
        Assistant.tmpCmp.statusChanged.connect( createObj )
    }


}

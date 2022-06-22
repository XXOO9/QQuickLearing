import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
//import QtWebEngine 1.8
 import QtWebEngine 1.10
import "./TotalJs.js" as Total
import "./Boom.js" as Boom
import "./Calculate.js" as Car

ApplicationWindow {
    visible: true
    width: 1200
    height: 1000
    title: qsTr("Hello World")

    Component.onCompleted: {
//        testFunc1()
    }

    Rectangle{
        anchors.fill: parent
        color: "lightgreen"
    }

    Item{
        id: webItem
        anchors.left: parent.left
        anchors.top: parent.top
        width: 600
        height: 600
        WebEngineView{
            id: view
            width: 600
            height: 600
            backgroundColor: "#5B5C6E"
            anchors.left: parent.left
/////////            @disable-check M7
            url: "file:///../demo1.html"

        }
    }

    Rectangle{
        width: 200
        height: width
        color: "red"
        anchors.left: webItem.right
        anchors.top: webItem.top
    }

    Button{
        id: btn1
        text: "1"
        onClicked: {
            timer.start()
        }
    }

    Button{
        id: btn2
        text: "2"
        anchors.top: btn1.bottom
        onClicked: {
//            timer.start()
            resizeWindow( 592, 592 )
//            resizeWindow( 590, 590 )
        }
    }

    Timer{
        id: timer
        interval: 100
        repeat: true
        onTriggered: {
            var val = Math.round(Math.random()*80)
            var funName = "appendData( '1', " + val + " )"
            console.log( "val = " + funName )
            view.runJavaScript( funName )
        }
    }

    function displayResult( ret ){
        console.log( "ret = " + ret )
    }

    function resizeWindow( width, height ){
        let funName = "resiezeWindow(" + width + "," + height + ")"
        view.runJavaScript( funName, function(ret){ console.log( "recv ret = " + ret )} )
    }

    function testFunc1(){
        var ppc = Boom.person
        ppc.isStu = 0


        if( ppc.isStu ){
            console.log( "WDNMD" )
        }else{
            console.log( "666666666666666666" )
        }

        console.log( "ret = " + ppc.isStu )
    }
}

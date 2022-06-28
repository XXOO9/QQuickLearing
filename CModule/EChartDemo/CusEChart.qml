import QtQuick 2.0
import QtWebEngine 1.10
Item{
    id: webItem
    anchors.left: parent.left
    anchors.top: parent.top
    width: 200
    height: 100
    WebEngineView{
        id: view
        width: 200
        height: 100
        backgroundColor: "#5B5C6E"
        anchors.left: parent.left
        /////////            @disable-check M7
        url: "file:///../demo1.html"

    }

    Timer{
        id: timer
        interval: 100

        running: true
        repeat: true
        onTriggered: {
            var val = Math.round(Math.random()*80)
            var funName = "appendData( '1', " + val + " )"
//            console.log( "val = " + funName )
            view.runJavaScript( funName )
        }
    }
}

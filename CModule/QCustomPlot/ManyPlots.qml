import QtQuick 2.0
import CustPlot 1.0
Item {

    property real num1: 32
    property real num2: 32

    property real curIndex1: 0
    property real curIndex2: 1024
    property real totalCnt: 1024

    GridView{
        id: gridView
        anchors.fill: parent
        cellWidth: root.width / num1
        cellHeight: root.height / num2
        model: totalCnt
        clip: true
        delegate: CustPlotItem{
            id: plot

            width: 70
            height: 40

            MouseArea{
                anchors.fill: parent
            }
            Text {
                text: index
                color: 'red'
                font.pixelSize: 20
            }
        }
    }

    Timer{
        id: autoAppendDataTimer1
//        running: true
        repeat: true
        interval: 100
        onTriggered: autoAppendData()
    }

    Timer{
        id: autoAppendDataTimer2
//        running: true
        interval: 100
        onTriggered: autoAppendData2()
    }

    Timer{
        id: timerTotal
        running: true
//        repeat: true
        interval: 50
        onTriggered: autoAppendDataTotal()
    }

    function autoAppendData(){
        if( curIndex1 >= totalCnt / 2 ){
            console.log( '1 index = ' + curIndex1 )
            curIndex1 = 0
        }

        gridView.currentIndex = curIndex1++
        gridView.currentItem.appendData()
    }

    function autoAppendData2(){
        if( curIndex2 < totalCnt / 2 ){
            console.log( '2 index = ' + curIndex2 )
            curIndex2 = 1023
        }

        gridView.currentIndex = curIndex2--
        gridView.currentItem.appendData()
    }

    function autoAppendDataTotal(){
        for( let index = 0; index < 1024; index++ ){
            gridView.currentIndex = index
            gridView.currentItem.appendData()
        }

        timerTotal.restart()


    }

}

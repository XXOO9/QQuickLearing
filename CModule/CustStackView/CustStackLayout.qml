import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


/*
  简单的封装一下StackLayout
  需要理解的东西: JavaScript 遍历数组 使用forEach( content, index ) 可以同时获取到数组的内容和下标
  */

Item {
    id:root
    width: 700
    height: 500


    property var menuList: ["第一页", "第二页", "第三页"]
    Rectangle{
        anchors.fill: parent
        color: "gray"
    }

    Row{
        id: rowHeaders
        width: parent.width
        height: 50
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        Component.onCompleted: {
            menuList.forEach( function( valOfIndex, index){
                headerComponent.createObject( rowHeaders, { width:parent.width / menuList.length, height: parent.height, menuText:valOfIndex, stackIndex:index, layout:stackLayout} )
            })

        }
    }

    StackLayout{
        id: stackLayout
        anchors.top: rowHeaders.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        currentIndex: 0

//        Behavior on currentIndex {
//            PropertyAnimation{
//                target: stackLayout
//                property: "currentIndex"
//                duration: 500
//            }
//        }

        Component.onCompleted: {
            menuList.forEach( function( valOfIndex, index ){
                var colorType
                if( index === 0 ) {
                    colorType = "lightgreen"
                }
                if( index === 1 ){
                    colorType = "yellow"
                }
                if( index === 2 ){
                    colorType = "gray"
                }

                contentComponent.createObject( stackLayout, { contentTextt: valOfIndex, color:colorType } )
            })

            console.log( "deepth = " + count )
        }

        onCurrentIndexChanged: {
            console.log( "current index = " + currentIndex )
        }
    }

    Component{
        id:headerComponent
        Button{
            property string menuText: ""
            property int stackIndex
            property var layout
            implicitWidth: 80
            implicitHeight: width / 3

            background: Rectangle{
                border.color: "red"
                color: "gray"
            }

            contentItem: Text {
                text: menuText
                color: "white"
                font{ pixelSize:  20 }
            }
            onClicked: {
                console.log( menuText + ' '  + stackIndex +  "clicked" )
                layout.currentIndex = stackIndex
                console.log( "ret = " + layout.count )
            }
        }
    }

    Component{
        id:contentComponent
        Rectangle{
            property string contentTextt: "WDNMD"
            property string contentColor: "black"
            color: contentColor
            Text {
                text: contentTextt
                color: "blue"
                font{ pixelSize: 30 }
                anchors.centerIn: parent
            }
        }
    }
}

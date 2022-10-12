import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    width: 800
    height: 600

    ListModel{
        id: selectElements
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
        ListElement{ name: "跳远起始设置" }
    }


    //初始化页展示需要设置的功能
    StackView{
        id: stackView
        initialItem: initCmp
        anchors.fill: parent
    }

    Component{
        id: initCmp
        Rectangle{
            id: elementRowRect
            width: root.width
            height: root.height

            readonly property real perRowHeight: 80
            ListView{
                model: selectElements
                anchors.fill: parent

                ScrollBar.vertical: ScrollBar{}

                delegate: Component{
                    Rectangle{
                        width: elementRowRect.width
                        height: elementRowRect.perRowHeight
                        color: "gray"
                        border.color: "green"
                        Text {
                            text: name
                            anchors.centerIn: parent
                        }

                        MouseArea{
                            enabled: true
                            anchors.fill: parent
                            onClicked: itemClicked( index )
                        }
                    }
                }
            }
        }
    }

    Component{
        id: page1
        Rectangle{
            width: root.width
            height: root.height

            color: "red"

            Button{
                onClicked: stackView.pop(  )
            }
        }
    }

    function itemClicked( targetIndex ){
        console.log( "index = " + targetIndex )

        stackView.push( page1 )
    }
}

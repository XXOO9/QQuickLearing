import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
//        InterAction.test_qml_callback( root.speak )
    }

    Rectangle{
        id: rect
        width: 150
        height: width
        color: 'red'
        anchors.centerIn: parent
    }

    Column{
        Button{
            id: btn
            onClicked: InterAction.changeColor( changeColor )
        }

        TextField{
            width: 150
            height: 50
//            validator: RegExpValidator{ regExp: /^(100|[1-9][0-9]|[0-9])$/ }
            validator: RegExpValidator{}
            background: Rectangle{
                anchors.fill: parent
                border.color: 'red'
            }
        }
    }





//    private
    function changeColor( targetColor ){
        rect.color = targetColor
        console.log( 'content = ' + targetColor )
    }
}

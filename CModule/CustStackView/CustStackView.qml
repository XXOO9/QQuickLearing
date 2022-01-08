import QtQuick 2.12
import QtQml 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
Item {
    id: root
    width:600
    height: 500

    Component.onCompleted: {
//        stack.push( cmp2 )
    }

    Rectangle{
        anchors.fill: parent
        color: "gray"
    }

    StackView{
        id:stack
        anchors.fill: parent
        initialItem: cmp1
        anchors.centerIn: parent
    }

    Component{
        id: cmp1
        Rectangle{
            width: 100
            height: width
            color: "red"
        }
    }

    Component{
        id: cmp2
        Rectangle{
            width: 100
            height: width
            color: "lightgreen"
        }
    }

    function pushCmp(){
        stack.push( cmp1 )
    }

    function getDeepth(){
        return stackView.depth
    }
}

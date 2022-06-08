import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import com.MyCompany.Enum 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
    }

//    CPPENUM{
//        id: cpp
//        name: "PPC"
//        //此处也会调用函数setColor
//        color: CPPENUM.GREEN
//        onSigColorChanged: {

//        }
//    }

    SubComponent{
        anchors.right: parent.right
    }

//    Button{
//        implicitWidth: 150
//        implicitHeight:  width

//        onClicked: {
//            cpp.color = CPPENUM.BLUE
//        }
//    }

    function setColor( color ){
        cpp.color = color
    }

    function getColor(){
        return cpp.colorName
    }
}

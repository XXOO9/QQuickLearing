import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        test( list, "isChecked" )
    }

    ListModel{
        id: list
        ListElement{ isChecked: false; name: "111" }
        ListElement{ isChecked: false; name: "222" }
    }

    CusFlowLayout{
        width: 0.9 * parent.width
        height: 0.9 * parent.height
        anchors.centerIn: parent
    }

    function test( dataModel, key ){
        for( let i = 0; i < dataModel.count; i++ ){
            console.log( dataModel.get( i )["name"] )
        }
    }
}

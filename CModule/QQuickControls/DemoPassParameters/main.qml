import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        testArray()
    }

    ListModel{
        id: list
        ListElement{ index: 1 }
        ListElement{ index: 2 }

    }


    function testArray(){
        let arr = [ 1, 2, 3, 4, 5, 6, 7, 8 ]

        let obj1 = { "name": "001" }
        let obj2 = { "name": "002" }

        let objArray = [ obj1, obj2 ]

        CInterAction.test_variantList( objArray )    //通过
    }


}

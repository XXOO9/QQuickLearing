import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


ApplicationWindow {
    visible: true
    width: 800
    height: 800
    title: qsTr("Hello World")

    Component.onCompleted: {
        console.log( "111111111111111 " + CModelUserSelect.rowCount() )

    }

    TextField{
        onFocusChanged: console.log( "focus changed, ret = " + focus )

        onActiveFocusChanged: console.log( "activeFocus changed, ret = " + activeFocus )
    }

    Button{
        anchors.bottom: parent.bottom
    }

    Rectangle{
        width: 50
        height: width
        color: "red"
        anchors.centerIn: parent
    }

    //    ListModel{
    //        id: list
    //    }

    //    CusTextInputFilter{
    //        anchors.centerIn: parent
    //        candidateModel: SuggestionsModel
    //    }


}

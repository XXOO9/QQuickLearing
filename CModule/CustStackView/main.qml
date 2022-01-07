import QtQuick 2.12
import QtQml 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 900
    height: 780
    title: qsTr("Hello World")


    CustStackView{
        anchors.centerIn: parent
    }


}

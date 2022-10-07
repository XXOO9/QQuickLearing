import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import App 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Foo{
        width: 200
        height: 100
        Component.onCompleted: {
            update()
        }
    }
}

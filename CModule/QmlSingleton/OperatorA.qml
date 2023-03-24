import QtQuick 2.0
Item {
    Component.onCompleted: {
        console.log( 'this is A' )
        TestGlobal.name = "A"
        console.log( 'name = ' + TestGlobal.name )
    }
}

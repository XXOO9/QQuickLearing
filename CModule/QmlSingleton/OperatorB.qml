import QtQuick 2.0

Item {
    Component.onCompleted: {
        console.log( 'this is B' )
        TestGlobal.name = "B"
        console.log( 'name = ' + TestGlobal.name )
    }
}

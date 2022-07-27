import QtQuick 2.0

Item {

    function display( content ){
        console.log( "recv parameter = " + content )
        return "this is display func..."
    }
}

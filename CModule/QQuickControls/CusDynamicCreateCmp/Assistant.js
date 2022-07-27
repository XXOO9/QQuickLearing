.pragma library
var tmpObj
var tmpCmp


function createCmp(){
    tmpCmp = Qt.createComponent( "qrc:/CusRect.qml" )
    if( tmpCmp.status === Component.Ready ){
        console.log( "1 ready" )
    }else{
        tmpCmp.statusChanged.connect(finishCreation);
    }
}

function finishCreation(){
    console.log( "2 ready" )
}

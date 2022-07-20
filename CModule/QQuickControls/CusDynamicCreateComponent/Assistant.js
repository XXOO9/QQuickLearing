.pragma library
var tmpObj
var tmpCmp

function createObj( tmpParent, cmp, data = {} ){
    let obj = cmp.createObject( tmpParent, data )
    return obj
}

function createObjFromUrl( url, tmpParent ){
    let obj = Qt.createQmlObject( url, tmpParent )
    return obj
}

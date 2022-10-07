import QtQuick 2.0

Item {

    Component.onCompleted: {
        for( let i = 0; i < 5; i++ ){
            listModel.append( { "userName": "name_" + i, "index": "index_" + i } )
        }

        let tarList = translate2Array( listModel )

        InterAction.setVariantList( tarList )
    }

    ListModel{
        id: listModel
    }

    function translate2Array( list ){
        let size = list.count
        let tmpBindUserObj
        let tmpBindUserInfo = {}
        let retArray = []

        for( let i = 0; i < size; i++ ){
            tmpBindUserObj = listModel.get( i )

            retArray.push( { "userName": tmpBindUserObj.userName,
                              "index": tmpBindUserObj.index } )
        }

        return retArray
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    id: root
    width: 800
    height: width

    property string str1: '<font color=\'#03617B\'; font size=50 >HaHaHa</font>'

    Component.onCompleted: {
        a1.text = generateRichText( 100 )

    }

    Column{
        spacing: 50
        Text {
            id: a1
            text:'<font color=\'#03617B\'; font size=50 >HaHaHa</font>'
            textFormat: Text.RichText   //千万，千万，必须， 必须 要设置嘞个东西，woc!
        }

        Text {
            text: '<font color=\'red\'; font size=50 >HaHaHa</font>'
            textFormat: Text.RichText
        }
    }

    function generateRichText( val ){
        let targetVal = val
        let valColor = 'red'
        let template = `<font color=\'${valColor}\'; font size=50>${targetVal}</font>`

        return template
    }



}

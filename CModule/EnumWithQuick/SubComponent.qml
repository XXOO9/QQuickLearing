import QtQuick 2.0
import QtQuick.Controls 2.12
import com.MyCompany.Enum 1.0


Item {
    width: 500
    height: width
    Button{
        width: 100
        height: width
        anchors.right: parent.right
        onClicked: {
            setColor( CPPENUM.BLUE )
        }
    }

    Button{
        width: 100
        height: width
        anchors.left: parent.left
        onClicked: {
            console.log( "color = ", getColor() )
        }
    }
}

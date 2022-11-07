import QtQuick 2.12
import QtQuick.Controls 2.12

Text {
    id: root
    property string preFix: '前缀'
    property string suffFix: '后缀'
    text: preFix + suffFix
    color: 'black'
    font{ family: "Microsoft YaHei"; pixelSize: 20 * factor }
    horizontalAlignment: Text.AlignRight
    verticalAlignment: Text.AlignVCenter
}

import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12

Item {
    id: root
    width: 700
    height: 500

    property string fileName: "D:/Demos/github/TME/CModule/DemoVideoPlayer/DEV_TYPE_BODY.mp4"

    property int videoDuration: 0

    property string strCurPos: "00:00"
    property string strtotalDuration: "00:00"

    Rectangle{
        anchors.fill: parent
        color: "gray"
    }

    Rectangle{
        id: outside
        width: 483
        height: 272
        anchors.centerIn: parent
        color: "red"
        border.color: "red"

        MediaPlayer{
            id: player
            source: fileName
            onPlaybackStateChanged: {
                if( player.playbackState === MediaPlayer.PlayingState ){
                    videoDuration = player.duration
                }
            }

        }

        VideoOutput{
            Component.onCompleted: {
                player.play()
            }

            anchors.fill: parent
            source: player
            fillMode: VideoOutput.PreserveAspectFit

            Text {
                id: cutPosText
                text: strCurPos
                color: "white"
                anchors.verticalCenter: slider.verticalCenter
                anchors.right: slider.left
            }

            Text {
                id: totalDurationText
                text: strtotalDuration
                color: "white"
                anchors.left: slider.right
                anchors.verticalCenter: slider.verticalCenter
            }

            Slider{
                id: slider
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                from:0
                value: player.position
                to: player.duration
                onMoved: setPostion( slider.value )
            }
        }
    }

    Timer{
        id: timer
        interval: 1000
        repeat: true
        running: player.playbackState === MediaPlayer.PlayingState ? true : false
        onTriggered: {
            strCurPos = translateTimeLine( player.position )
            strtotalDuration = translateTimeLine( player.duration )
        }
    }

    Button{
        id: btn1
        text: "1"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        onClicked: getVideoInfo()
    }

    Button{
        id: btn2
        text: "2"
        anchors.bottom: parent.bottom
        anchors.left: btn1.right
        onClicked: setPostion( 0.5 )
    }

    function getVideoInfo(){
        videoDuration = player.duration

        console.log( "duration = " + videoDuration )
    }

    function setPostion( persent ){
        persent = 0.01 * persent
        if( player.seekable ){
            let pos = Math.trunc( persent * player.duration )// 62165
            console.log( "duration = " + pos )
            player.seek( pos )
        }

    }

    function translateTimeLine( timeLine ){
        let totalSecs = timeLine / 1000
        let totalMins = String( Math.trunc( totalSecs / 60 ) ).padStart( 2, '0' )
        let restSecs = String( Math.trunc( totalSecs % 60 ) ).padStart( 2, '0' )
        let ret = totalMins + ":" + restSecs
        console.log( ret )
        return ret
    }
}

import QtQuick 2.12
import QtQuick.Window 2.12
import Data 1.0

Window {
    visible: true
    width: 1040
    height: 640
    title: qsTr("Corona stats")

    CoronaData {
        id: cData
        stats: " TESTTTTTT"
    }

    Text {
        id: txt
        width: 100; height: 100
        x: parent.width/4
        y: parent.height/4
        text: cData.stats
    }
}

import QtQuick 2.12
import QtQuick.Window 2.12
import Qt.labs.animation 1.0
import QtQuick.Controls 2.13

Window {
    id: window
    visible: true
    width: 1080
    height: 720
    property alias window: window
    title: qsTr("Hello title")

    Rectangle {
        id: rectangle
        color: "#e29999"
        anchors.rightMargin: 87
        anchors.bottomMargin: 35
        anchors.leftMargin: 127
        anchors.topMargin: 105
        anchors.fill: parent

        Text {
            id: element
            x: 251
            y: -121
            text: qsTr("myText")
            anchors.horizontalCenterOffset: 116
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 30
        }

        Button {
            id: button
            x: 411
            y: 182
            text: qsTr("myButton")
            anchors.horizontalCenterOffset: 533
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                element.text="Hello, Rebecca"
            }
        }

    }
}

/*##^##
Designer {
    D{i:1;anchors_height:200;anchors_width:200;anchors_x:146;anchors_y:124}
}
##^##*/

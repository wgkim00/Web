import QtQuick 2.11


Rectangle{
    width: 200
    height: 100
    anchors.centerIn: parent
    color: isOn ? "green" : "yellow"
    border.width: 2
    border.color: "black"

    property bool isOn: false // state flag로 사용될 사용자정의 프로퍼티

    // 시그널 정의
    signal buttonPressed(bool isPressed)
    signal buttonReleased(bool isPressed)
    signal buttonClicked()

    Text {
        id: title
        anchors.fill: parent
        text: parent.isOn? qsTr("On") : qsTr("Off") // state flag에 따라 text를 설정하는 삼항연산자
        font.pixelSize: 20
        font.bold: true
        color: parent.isOn? "yellow" : "green"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    MouseArea{
        anchors.fill: parent             // Rectangle의 영역을 채움
        onPressed: buttonPressed(pressed) //parent.isOn = true    // on설정
        onReleased: buttonPressed(pressed) //parent.isOn = false  // off설정
        onClicked: buttonClicked()  // console.log("clicked")
        onPressedChanged: console.log("state: " + parent.isOn)
    }
}

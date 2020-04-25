import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 700
    height: 500
    title: "ListView"
    color:"grey"

    ListModel{
        id: groupModel
        ListElement{name: "group1"}
        ListElement{name: "group2"}
        ListElement{name: "group3"}
        ListElement{name: "group4"}
        ListElement{name: "group5"}
    } // group list

    Rectangle{
        id: background
        anchors.fill: parent
        color: "blue"
    }

    ListView{
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height
        clip: true
        spacing: 20
        orientation: Qt.Horizontal
        model: groupModel

        delegate:
            Item{
            id: stack
            height: 100
            width: 200
            anchors.verticalCenter: parent.verticalCenter

            signal itemEmpty()

            onItemEmpty: {
                console.log("group : " , name)
                groupModel.remove(index)
            }

            ListView{
                model: ListModel{
                    id: stackModel
                    ListElement{name: "item1"}
                    ListElement{name: "item2"}
                    ListElement{name: "item3"}
                    ListElement{name: "item4"}
                }
                anchors.fill: parent
                orientation: Qt.Horizontal

                delegate:
                Rectangle{
                    id: widget
                    width: 200
                    height: 100
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: (index * spacing)
                    z: stackModel.count - index
                    border.width: 1
                    color: "#cb917d"

                    readonly property int spacing: 5

                    onYChanged: {
                        var value = 1.0 - yRatio()
                        opacity = value.toFixed(1)
                    }

                    function yRatio(){
                        var cal = (index * spacing)
                        var position = Math.abs(y - cal)
                        return (position / height)
                    }

                    PropertyAnimation{
                        id: yPositionUpAni
                        target: widget
                        property: "y"
                        duration: 100
                        to: -120
                        onStopped: {
                            stackModel.remove(index)

                            if(stackModel.count <= 0){
                                stack.itemEmpty()
                            }
                        }
                    }
                    PropertyAnimation{
                        id: yPositionDownAni
                        target: widget
                        property: "y"
                        duration: 100
                        to: index * 5
                        easing.type: Easing.InCubic
                    }

                    MouseArea{
                        anchors.fill: parent
                        drag.target: widget
                        drag.axis: Drag.YAxis
                        drag.maximumY: index * parent.spacing
                        hoverEnabled: true

                        onReleased: {
                            var opacity = parent.yRatio()
                            if(opacity > 0.5){
                                yPositionUpAni.start()
                            }else{
                                yPositionDownAni.start()
                            }
                        }
                    }
                }
            }
        }
    }
}

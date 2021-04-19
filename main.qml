import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    width: 500
    height: 500
    visible: true
    id: root

    Row {
        id: tools

        Button {
            id: clear
            width: 50
            height: 50
            text: "Clear"
            onClicked: {
                canvas.clear()
            }
        }

        Button {
            id: save
            width: 50
            height: 50
            text: "Save"
            onClicked: {
                mouse.save()
            }
        }
    }

    Canvas {
        id: canvas
        anchors.top: tools.bottom
        width: 500
        height: 500
        property int lastX: 0
        property int lastY: 0

        function clear() {
            var ctx = getContext("2d")
            ctx.reset()
            canvas.requestPaint()
            mouse.clear()
        }

        onPaint: {
            //Painting
            var ctx = getContext("2d")
            ctx.lineWidth = 2
            ctx.strokeStyle = color.red

            ctx.beginPath()
            ctx.moveTo(lastX, lastY)
            lastX = area.mouseX
            lastY = area.mouseY
            ctx.lineTo(lastX, lastY)
            ctx.stroke()

            mouse.test()
            mouse.add(lastX,lastY)
            mouse.add(Qt.point(lastX,lastY))
        }

        MouseArea {
            id:area
            anchors.fill: parent
            onPressed: {
                canvas.lastX = mouseX
                canvas.lastY = mouseY
            }

            onPositionChanged: {
                canvas.requestPaint();
            }
        }
    }
}

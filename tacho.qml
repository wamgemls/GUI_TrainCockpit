import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls 2.13
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Item {
    id: element
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 640
        height: 480
        radius: 100
        border.color: "#000000"
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#e00d0d"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
        }
    }

    CircularGauge {
        id: circularGauge
        x: 52
        y: 40
        width: 400
        height: 400
        layer.textureSize.height: 1
        layer.textureSize.width: 1
        layer.smooth: false
        value: 0
    }

    Slider {
        id: slider
        x: 343
        y: 220
        width: 400
        scale: 1
        rotation: 270
        stepSize: 1
        to: 100
        value: 0.5
    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls 2.13
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Item {
    CircularGauge {
        id: circularGauge
        x: 100
        y: 40
        width: 400
        height: 400
        value: 0
    }

    Slider {
        id: slider
        x: 373
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

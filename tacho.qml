import QtQuick 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls 2.13

Item {
    CircularGauge {
        id: circularGauge
        x: 216
        y: 136
    }

    Slider {
        id: slider
        x: 220
        y: 392
        value: 0.5
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

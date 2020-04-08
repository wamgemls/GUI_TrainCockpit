import QtQuick 2.4
import QtQuick.Controls 2.13
import QtQuick.Extras 1.4
import QtQuick.Window 2.13

Item {
    width: 400
    height: 400

    Slider {
        id: slider
        x: 100
        y: 352
        value: 1
    }

    CircularGauge {
        id: circularGauge
        x: 96
        y: 96
        value: 9
    }
}

import QtQuick 2.0
import QtPositioning 5.8
import QtLocation 5.9

Item {
    PositionSource{
        active: true


        //PluginParameter {name:"QT_NMEA_SERIAL_PORT"; value:"COM8"}
        //PluginParameter { name: "serialnmea.serial_port"; value: "com8" }
        //nmeaSource: "ws://192.168.2.120:4649"


        onPositionChanged:{
            console.log(position.coordinate);
        }
    }

    Plugin {
        id: osm
        name: "osm"


        PluginParameter { name: "osm.useragent"; value: "My great Qt OSM application" }
        PluginParameter { name: "osm.mapping.host"; value: "http://tiles.openrailwaymap.org/" }
        PluginParameter { name: "osm.mapping.copyright"; value: "All mine" }
        PluginParameter { name: "osm.routing.host"; value: "http://osrm.server.address/viaroute" }
        PluginParameter { name: "osm.geocoding.host"; value: "http://geocoding.server.address" }

        //PluginParameter { name: "osm.mapping.providersrepository.address"; value: "http://maps-redirect.qt.io/osm/5.8/satellite" }
    }

    Plugin {
        id: esri
        name: "esri"

    }

    Plugin {
        id: mapboxgl
        name: "mapboxgl"

    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapboxgl

        center {
            latitude: 49.013611
            longitude: 8.404444
        }
        zoomLevel: 15

        gesture.enabled: true
    }
}

import QtQuick 2.0
import QtPositioning 5.8
import QtLocation 5.9
import QtQuick.Window 2.0

Item {
    PositionSource{
        active: true
        onPositionChanged:{
            console.log(position.coordinate);
        }
    }

    Plugin {
        id: osm
        name: "osm"

        //PluginParameter { name: "osm.mapping.providersrepository.disabled"; value: "true"}

        PluginParameter { name: "osm.useragent"; value: "My great Qt OSM application" }
        PluginParameter { name: "osm.mapping.host"; value: "http://osm.tile.server.address/" }
        PluginParameter { name: "osm.mapping.copyright"; value: "All mine" }
        PluginParameter { name: "osm.routing.host"; value: "http://osrm.server.address/viaroute" }
        PluginParameter { name: "osm.geocoding.host"; value: "http://geocoding.server.address" }

    }

    Plugin {
        id: esri
        name: "esri"

    }

    Plugin {
        id: mapbox
        name: "mapboxgl"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: esri
        activeMapType: MapType.SatelliteMapDay


        center {
            latitude: -27
            longitude: 153
        }
        zoomLevel: map.minimumZoomLevel

        gesture.enabled: true
    }
}

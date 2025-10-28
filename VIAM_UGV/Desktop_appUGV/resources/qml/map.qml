import QtQuick 2.0
import QtPositioning 5.8
import QtLocation 5.8

Rectangle {
    id: window
    objectName: "rect"
    width: 1180
    height: 780
    visible: true

//    property var latList: [10.77549,10.775507,10.774907,10.774894,10.774873,10.774747,10.774733,10.774666,10.774647,10.77449,10.774505,10.774271,10.774255,10.774098,10.774041,
//    10.774267,10.774249,10.774403,10.774384,10.77442,10.774597,10.774632,10.774613,10.774578,10.774471,10.774457,10.774382,10.774403,10.774362,10.774381,10.774333,10.774309,10.774316,10.77426]
//    property var lonList: [106.65978,106.659814,106.660121,106.660175,106.66014,106.660216,106.660263,106.660029,106.660093,106.660126,106.660163,106.660244,106.660296,106.659906,106.659889
//    ,106.659813,106.659776,106.659736,106.659701,106.659681,106.65963,106.659611,106.659577,106.659595,106.659303,106.659362,106.659366,106.659399,106.65938,106.659414,106.659266,106.659278,106.659461,106.659446]
//    property var nameList: ["0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33"]
//    property var edgeList: ["1,0","0,2","2,4","4,3","3,1","4,5","6,3","2,21","20,4","21,22","23,20","20,21","22,23","5,7","8,6","7,9","10,8","9,10","9,11","12,10","11,13","14,12","13,15","16,14","16,15",
//    "15,17","18,16","18,17","17,19","19,18","17,20","23,19","19,32","33,18","32,29","29,27","27,26","26,30","30,31","31,28","28,33","28,29","27,25","25,23","22,24","24,26","3,2","17,18"]
//    QStringList llist = {"0","21","26","15","17","12","50","51"};
//10.88177,106.80547 nha thi dau d0
//10.88093,106.80521 sau h3 d3
//10.88053,106.80501 h2 d5
//10.87991,106.80577 h6 d8
//10.88006,106.80470 b1 d10
//10.88020,106.80637 x buyt 12
//10.88130,106.80619 d1
//10.88062,106.80574 d2
//10.88022,106.80548 d4
//10.88119,106.80637 d6
//10.88002,106.80562 d7
//10.87959,106.80510 d9
//10.88051,106.80593 d11

//    property var nameList: ["0","1","2","3","4","5","6","7","8","9","10","11","12","13","14"]
//    property var lList: ["0","3","5","8","10", "12"]
//    property var lonList: [106.80550, 106.80618, 106.80574, 106.80530, 106.80548, 106.80501,106.80638,106.80561,106.80574,106.80510,106.80470,106.80593,106.80637,106.80461,106.80527]
//    property var latList: [10.88174, 10.88129, 10.88060, 10.88088, 10.88022, 10.88053, 10.88116, 10.87998,10.87989,10.87959, 10.88006, 10.88046, 10.88020, 10.87990, 10.87948]
//    property var location: ["Nhà Thi Đấu", "d1", "d2", "Tòa H3", "d4", "Tòa H2", "d6", "d7", "Tòa H6", "d9", "Tòa B1", "d11", "Trạm bus H6", "d13", "d14"]
//    property var edgeList: ["0,1", "1,0", "1,2", "2,1", "1,6", "6,1","11,6", "6,11", "2,3", "3,2", "2,4", "4,2", "2,11", "11,12","12,11", "11,2", "7,11", "11,7", "7,8", "8,7", "7,14", "14,7", "4,5", "5,4","4,9", "9,4", "13,9", "9,13", "14,9", "9,14", "13,10", "10,13", ]



    property var nameList: ["0","1","2","3","4","5","6","7","8"]
    property var lList: ["0","2","3","6","8"]
    property var lonList: [106.65879, 106.65965,106.65991, 106.66002,106.65937,106.65947,106.65929,106.65994,106.65959]
    property var latList: [10.77258, 10.77303, 10.77265, 10.77300,10.77340,10.77351,10.77373,10.77398,10.77462]
    property var location: ["Tòa B3", "d1", "Bãi đậu xe A1", "Tòa A2", "d2", "d3", "Tòa B6", "d4", "Tòa C1"]
    property var edgeList: ["0,1", "1,0", "1,2", "2,1","2,3", "3,2"]

    property var location_indoor: ["Cổng thư viện C2", "dd1", "phòng công tác A1", "dd2", "BKfood cổng 1", "BKfood cổng 2", "Phòng xây dựng", "dd3", "Phòng sinh hoạt C1", "Phòng tự học C1","dd4"]
    property var location_indoor_x: []
    property var location_indoor_y: []
    property var latList_inddor: [10.77302,10.77273,10.77266,10.77353,10.77346,10.77366,10.77406,10.77469,10.77456,10.77491,10.77478]
    property var lonList_indoor: [106.66008,106.66022,106.66007,106.65889,106.65875,106.65878,106.65856,106.65955,106.65929,106.65945,106.65918]
    property var location_indoor_list: ["0","1","2","3","4","5","6","7","8","9","10"]
    property var location_indoor_llist: ["0","2","4","5","6","8","9"]

    function updateRealPath(point) {
        realPath.addCoordinate(point)
        target_marker.coordinate = point
        target_marker.visible = true
    }

    function createDesiredPath(point) {
        desiredPath.addCoordinate(point)
//        for (var i = 0; i < pointList.length; i++) {
//            desiredPath.addCoordinate(pointList[i])
//        }
    }

    function clearRealPath() {
        realPath.path = []
    }

    Plugin {
        id: mapPlugin
        name: 'osm'
        PluginParameter {
            name: 'osm.mapping.custom.host'
            value: 'qrc:/maps/bachkhoa.osm'
        }
        PluginParameter {
            name: 'osm.mapping.providersrepository.disabled'
            value: true
        }
    }

    Map {
        id: mapView
        anchors.fill: parent
        activeMapType: mapView.supportedMapTypes[1]
        center: QtPositioning.coordinate(10.903162, 106.796567)
        zoomLevel: maximumZoomLevel
        rotation: 0
        plugin: mapPlugin

        gesture.enabled: true
        gesture.acceptedGestures: MapGestureArea.PinchGesture | MapGestureArea.PanGesture

        MapPolyline {
            id: realPath
            line.width: 3
            line.color: 'red'
        }

        MapPolyline {
            id: desiredPath
//            objectName: 'desiredPath'
            line.width: 3
            line.color: 'blue'
//            path:[QtPositioning.coordinate(10.7725199382, 106.658854267),
//                QtPositioning.coordinate(10.7729817708, 106.659619141),
//                QtPositioning.coordinate(10.7726765951, 106.659814453)]

        }

//        MapPolyline {
//            id: cubePath
////            objectName: 'cubePath'
//            line.width: 3
//            line.color: 'green'
//            path:[QtPositioning.coordinate(10.7725524902, 106.658837891),
//                QtPositioning.coordinate(10.7730041504, 106.659651693),
//                QtPositioning.coordinate(10.7726338704, 106.659847005),
//                QtPositioning.coordinate(10.7722066243, 106.659098307),
//            QtPositioning.coordinate(10.7725524902, 106.658837891)]

//        }

        MapQuickItem {
            id: target_marker
            coordinate: QtPositioning.coordinate(0, 0)
            anchorPoint.x: target_marker_image.width / 2
            anchorPoint.y: target_marker_image.height
            sourceItem: Image{
                id: target_marker_image
                source: 'qrc:/images/markers/marker2.png'
            }
            visible: false
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
//            pressAndHoldInterval: 200

            onDoubleClicked: {
                var mouseGeoPos = mapView.toCoordinate(Qt.point(mouse.x, mouse.y));
                var preZoomPoint = mapView.fromCoordinate(mouseGeoPos, false);
                if (mouse.button === Qt.LeftButton) {
                    mapView.zoomLevel = Math.floor(mapView.zoomLevel + 1)
                } else if (mouse.button === Qt.RightButton) {
                    mapView.zoomLevel = Math.floor(mapView.zoomLevel - 1)
                }
                var postZoomPoint = mapView.fromCoordinate(mouseGeoPos, false);
                var dx = postZoomPoint.x - preZoomPoint.x;
                var dy = postZoomPoint.y - preZoomPoint.y;

                var mapCenterPoint = Qt.point(mapView.width / 2.0 + dx, mapView.height / 2.0 + dy);
                mapView.center = mapView.toCoordinate(mapCenterPoint);
            }
        }

        Component.onCompleted: {
            for (var i = 0; i < nameList.length; i++) {
                var name = nameList[i];
                if (lList.indexOf(name) !== -1) {
                    var component = Qt.createComponent("Marker_outdoor.qml").createObject(mapView)
                    component.coordinate = QtPositioning.coordinate(latList[i], lonList[i])
                    component.name = location[i]
                    mapView.addMapItem(component)
                }
           }
            for (var ii = 0; ii < location_indoor_list.length; ii++) {
                name = location_indoor_list[ii];
                if (location_indoor_llist.indexOf(name) !== -1) {
                    var component = Qt.createComponent("Marker_indoor.qml").createObject(mapView)
                    component.coordinate = QtPositioning.coordinate(latList_inddor[ii], lonList_indoor[ii])
                    component.name = location_indoor[ii]
                    mapView.addMapItem(component)
                }
           }
        }
    }
}

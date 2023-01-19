import QtQuick 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 640
    title: qsTr("Scroll")

    MainPage {
        id: mainPage
        anchors.fill: parent
    }

//    ListView {
//        width: parent.width
//        model: 20
//        delegate: ItemDelegate {
//            text: "Item " + (index + 1)
//            width: parent.width
//        }
//    }
}

import QtQuick 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.2

import "MainElements"

ApplicationWindow {
    id: window
    visible: true

    maximumHeight: 640
    maximumWidth: 640

    minimumHeight: 640
    minimumWidth: 640

    header: MainHeader{
        id: mainHeader
        titleIsChangeble: false
    }

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

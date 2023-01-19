import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.VirtualKeyboard 2.2

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    ListView {
        width: parent.width
        model: 20
        delegate: ItemDelegate {
            text: "Item " + (index + 1)
            width: parent.width
        }
    }
}

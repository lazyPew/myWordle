import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle {
    property string letter : label.text

    width: 60
    height: 60
    color: "transparent"
    border.color: "white"
    border.width: 5
    radius: 15

    Label {
        id: label
        text: letter
    }
}

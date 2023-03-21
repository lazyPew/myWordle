import QtQuick 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQml 2.2

ToolBar {
    id: root
    property bool titleIsChangeble: true

    signal newWord()
    width: parent.width
    height: 45

    background: Rectangle {
        id: back
        color: Material.primary
    }

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10

        ToolButton{
            icon.source: "/Icons/Icons/exit"
            font.pixelSize: root.height/2
            onClicked: game.turnOff()
        }

        Item{
            Layout.fillWidth: true
        }

        ToolButton{
            text: "NEW"
            font.pixelSize: root.height/3
            onClicked: game.generateNewWord()
        }
    }
}

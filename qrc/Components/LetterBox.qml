import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import DataModels 1.0

Rectangle {
    property string letter : label.text
    property int correctness : 0

    implicitWidth: 60
    implicitHeight: 60
    color: correctness == WordClass.LetterCorrect
           ? "green"
           : correctness == WordClass.LetterInAnotherPlace
             ? "yellow"
             : "transparent"
    border.color: "white"
    border.width: 5
    radius: 15

    Label {
        id: label
        text: letter
        font.family: "Helvetica"
        font.pointSize: 30
        anchors.centerIn: parent
    }
}

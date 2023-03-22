import QtQuick 2.10
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

RowLayout{
    property var word: wordRole
    property var letters: lettersRole

//    width: parent.width
    Layout.alignment: Qt.AlignHCenter
    spacing: 2
    Repeater{
        Layout.alignment: Qt.AlignHCenter
        model:5
        LetterBox{
            letter: word[modelData]
            correctness: lettersRole[modelData]
        }
    }
}

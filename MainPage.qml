import QtQuick 2.10
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3
import QtQuick.VirtualKeyboard 2.2
import QtQuick.VirtualKeyboard.Settings 2.2

Page {
    id: root

//    WordPane{
//        id: wordPane
//        implicitHeight: parent.height - inputPanel.height
////        Layout.fillHeight: true
//        Layout.fillWidth: true
//    }
//    ListView{
//        id:view
//        width: parent.width
//    }

    contentItem: ColumnLayout{

        Repeater{
            model:6
            RowLayout{
                Layout.alignment: Qt.AlignHCenter
                Repeater{
                model: 5
                    LetterBox{
                    }
                }
            }
        }
        Layout.fillHeight: true
        Layout.fillWidth: true
        Repeater{
//            model:Repeater{
//                model: 5
                    LetterBox{
                    }
//            }
        }
    }

    InputPanel {
        id: inputPanel
        z: 99
        visible: active
        active: true
        implicitWidth: parent.width
        Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
        Component.onCompleted: {
            //// -BUG empty locales list
            //console.log(VirtualKeyboardSettings.availableLocales)
            VirtualKeyboardSettings.activeLocales = ["ru_RU",/*"en_EN"*/];
            VirtualKeyboardSettings.locale = "ru_RU"//"en_EN"//"British English"
        }
    }
}

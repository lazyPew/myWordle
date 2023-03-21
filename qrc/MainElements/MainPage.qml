import QtQuick 2.10
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3
import QtQuick.VirtualKeyboard 2.2
import QtQuick.VirtualKeyboard.Settings 2.2

import "../Components"

Page {
    id: root

    contentItem: ColumnLayout{
        Layout.fillHeight: true
        Layout.fillWidth: true

//        ListView {
//            id: view
//            model: game.wordsModel
//            height: parent.height
//            width: parent.width
//            clip: true
//            spacing: 20
//            delegate: DiskDelegate {
//                width: parent.width - (scroll.width*3)
//                height: 80

//            }
//        }

        Repeater{
            model: game.wordsModel.wordTries
            RowLayout{
                property var word: getArray(modelData)

                Layout.alignment: Qt.AlignHCenter
                Repeater{
                    model:5
                    LetterBox{
                        letter: word[modelData]
                        correctness: word
                    }
                }
            }
//            Component.onCompleted:
        }


        // TODO create own keyboard???

//        InputPanel {
//            id: inputPanel
//            z: 99
//            visible: active
//            active: game.tryNumber < game.maxNumber
//            implicitWidth: parent.width
//            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
//            Component.onCompleted: {
//                //// -BUG empty locales list
//                //console.log(VirtualKeyboardSettings.availableLocales)
//                VirtualKeyboardSettings.activeLocales = ["ru_RU"];
//                VirtualKeyboardSettings.locale = "ru_RU"
//    //            VirtualKeyboardSettings.activeLocales = ["en_EN"];
//    //            VirtualKeyboardSettings.locale = "en_EN"
//            }
//        }
    }

    function getArray(str){
        var arr = []
        for (var i = 0; i < str.length; i++) {
            arr.push(str.charAt(i))
        }
        console.log(arr)
        return arr
    }
}

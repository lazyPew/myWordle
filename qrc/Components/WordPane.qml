import QtQuick 2.10
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

Pane {
    id: root
    property string text: label.text

    Label{
        id:label
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

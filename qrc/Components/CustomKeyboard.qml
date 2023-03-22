import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

Control {
    property int buttonWidthHeight: 50

    ColumnLayout{
        Layout.fillWidth: true
        spacing: 4
        RowLayout{
            Layout.fillWidth: true
            spacing: 3
            Repeater{
                model:[
                    "й","ц","у","к","е","н",
                    "г","ш","щ","з","х","ъ"
                ]
                delegate: Button{
                    height: 10
                    width: 10
                    text: modelData
                    background: Rectangle{
                        implicitHeight: buttonWidthHeight
                        implicitWidth: buttonWidthHeight
                        color: "grey"
                    }
                }
            }
        }
        RowLayout{
            Layout.fillWidth: true
            spacing: 2
            Button{
                text: "Enter"
                background: Rectangle{
                    implicitHeight: buttonWidthHeight*2 + parent.spacing
                    implicitWidth: buttonWidthHeight
                    color: "grey"
                }
            }
            ColumnLayout{
                Layout.fillWidth: true
                RowLayout{
                    Layout.fillWidth: true
                    spacing: 2
                    Repeater{
                        model:[
                            "ф","ы","в","а","п","р",
                            "о","л","д","ж","э"
                        ]
                        delegate: Button{
                            text: modelData
                            background: Rectangle{
                                implicitHeight: buttonWidthHeight
                                implicitWidth: buttonWidthHeight
                                color: "grey"
                            }
                        }
                    }
                }
                RowLayout{
                    Layout.fillWidth: true
                    spacing: 2
                    Repeater{
                        model:[
                            "я","ч","с","м","и","т",
                            "ь","б","ю"
                        ]
                        delegate: Button{
                            text: modelData
                            background: Rectangle{
                                implicitHeight: buttonWidthHeight
                                implicitWidth: buttonWidthHeight
                                color: "grey"
                            }
                        }
                    }
                    Button{
                        text: "<=="
                        background: Rectangle{
                            implicitHeight: buttonWidthHeight
                            implicitWidth: buttonWidthHeight*2 + parent.spacing/2
                            color: "grey"
                        }
                    }
                }
            }
        }
    }
}

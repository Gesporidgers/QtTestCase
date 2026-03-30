import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3



Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text{
        x: 0
        y: 0
        width: 640
        height: 27
        text: "База данных"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 22
    }

    TextField {
        id: textField
        x: 0
        y: 53
        placeholderText: "Введите что нужно найти"
        font.pointSize: 12
    }

    GroupBox {
        id: groupBox
        x: 265
        y: 33
        width: 231
        height: 60
        hoverEnabled: true
        wheelEnabled: false
        title: qsTr("Поле поиска")

        RadioButton {
            id: radioButton
            x: -12
            y: -6
            width: 109
            height: 28
            text: qsTr("ФИО")
        }

        RadioButton {
            id: radioButton1
            x: 98
            y: -6
            width: 109
            height: 28
            text: qsTr("Группа")
        }
    }

    Button {
        objectName: "buttonSearch"
        x: 206
        y: 53
        width: 53
        height: 40
        text: "Поиск"
        display: AbstractButton.TextOnly
    }
    Row {
                height: 20
                y: 104
                Text { text: "ФИО"; font.pointSize: 11;horizontalAlignment: Text.AlignHCenter; width: 180; font.bold: true}
                Text { text: "Группа";font.pointSize: 11;horizontalAlignment: Text.AlignHCenter; width: 160; font.bold: true }
                Text { text: "Логин"; font.pointSize: 11;horizontalAlignment: Text.AlignHCenter; width: 100; font.bold: true }
                Text { text: "Пароль"; font.pointSize: 11;horizontalAlignment: Text.AlignHCenter;width: 160; font.bold: true }
                
}
    ListView {
        x: 0
        y:130
        width: 640
        height: 350
        objectName: "listv"

        delegate: Row {
            height: 30
            TextField { text: name; width: 180;readOnly: true; height: 30}
            TextField { text: gr; width: 160;readOnly: true; height: 30 }
            TextField { text: login; width: 100;readOnly: true; height: 30 }
            TextField { text: pass; width: 160;horizontalAlignment: Text.AlignHCenter; echoMode: "Password"; readOnly: true; height: 30}
            
        }
    }
}
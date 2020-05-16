import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.12
import "."

Dialog {
    property string label: "New item"
    property string hint: ""
    property alias editText: editTextItem

    standardButtons: StandardButton.Ok | StandardButton.Cancel

    onVisibleChanged: {
        editTextItem.focus = true
        editTextItem.selectAll()
    }

    onButtonClicked: {
        Qt.inputMethod.hide()
    }
    Rectangle {
        implicitWidth: parent.width
        implicitHeight: 100
        ColumnLayout {
            Text {
                id: labelItem
                text: label
                color: Style.text
            }
            TextInput {
                id: editTextItem
                inputMethodHints: Qt.ImhPreferUppercase
                text: hint
                color: Style.text
            }
        }
    }
}

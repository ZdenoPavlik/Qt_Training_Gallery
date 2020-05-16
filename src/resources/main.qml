import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import "."

ApplicationWindow {

    readonly property alias pageStack: stackView

    id: app
    visible: true
    width: 1200
    height: 800
    color: Style.windowBackground

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: AlbumListPage {}
    }

    onClosing: {
            if (stackView.depth > 1) {
                close.accepted = false
                stackView.pop()
            }
    }
}

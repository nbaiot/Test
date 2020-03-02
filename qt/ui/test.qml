import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

import ui.dispatcher 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: "hello qml"

    Button {
        id: b1
        text: qsTr("hello button")
        onClicked: {
            ActionDispatcher.Dispatcher("clicked");
        }
    }
}
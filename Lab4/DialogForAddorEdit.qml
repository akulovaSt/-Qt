import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.5   // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 1.2


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Добавление информации о звезде")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    property bool isEdit: false
    property int currentIndex: -1

    GridLayout {
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: buttonCancel.top; margins: 10 }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Название звезды:")
        }
        TextField {
            id: textName
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Созвездие:")
        }
        TextField {
            id: textGroup
            Layout.fillWidth: true
            placeholderText: qsTr("Введите созвездие")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Видимая звездная величина:")
        }
        TextField {
            id: textSize
            Layout.fillWidth: true
            placeholderText: qsTr("Введите величину")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Расстояние от Земли:")
        }
        TextField {
            id: textDistance
            Layout.fillWidth: true
            placeholderText: qsTr("Введите расстояние")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Координаты на небосклоне:")
        }
        TextField {
            id: textCoordinates
            Layout.fillWidth: true
            placeholderText: qsTr("Введите координаты")
        }
    }

    Button {
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("ОК")
        width: 100
        onClicked: {
            root.hide()
            if (currentIndex<0)
            {
                add(textName.text, textGroup.text, textSize.text, textDistance.text, textCoordinates.text)
            }
            else
            {
                edit(textName.text, textGroup.text, textSize.text, textDistance.text, textCoordinates.text, root.currentIndex)
            }

        }
    }

    Button {
        id: buttonCancel
        anchors { right: parent.right; bottom: parent.bottom; rightMargin: 10; bottomMargin: 10 }
        text: qsTr("Отменить")
        width: 100
        onClicked: {
             root.hide()
        }
    }

    // изменение статуса видимости окна диалога
    onVisibleChanged: {
      if (visible && currentIndex < 0) {
          textName.text = ""
          textGroup.text = ""
          textSize.text = ""
          textDistance.text = ""
          textCoordinates.text = ""
      }
    }

    function execute(name, group, size, distance, coordinates, index){
        isEdit = true
        textName.text = name
        textGroup.text = group
        textSize.text = size
        textDistance.text = distance
        textCoordinates.text = coordinates
        root.currentIndex = index

        root.show()
    }


 }

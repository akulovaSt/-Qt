import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Добавление информации о звезде")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    GridLayout {
        anchors {
            left: parent.left;
            top: parent.top;
            right: parent.right;
            bottom: buttonCancel.top;
            margins: 10
        }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Название звезды:")
        }
        TextField {
            id: textName
            Layout.fillWidth: true//чтобы все колонки имели одинаковую ширину и заполняли всё пространство
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Созвездие:")
        }
        TextField {
            id: textGroup
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название созвездия")
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
        visible: {textName.length>0 && textGroup.length>0}
        anchors {
            right: buttonCancel.left;
            verticalCenter: buttonCancel.verticalCenter;
            rightMargin: 10
        }
        text: qsTr("Добавить")
        width: 100
        onClicked: {
            root.hide()
            add(textName.text, textGroup.text, textSize.text, textDistance.text, textCoordinates.text)
        }
    }
    Button {
        id: buttonCancel
        anchors {
            right: parent.right;
            bottom: parent.bottom;
            rightMargin: 10;
            bottomMargin: 10
        }
        text: qsTr("Отменить")
        width: 100
        onClicked: {
             root.hide()
        }
    }

    // изменение статуса видимости окна диалога
    onVisibleChanged: {
      if (visible) {
          textName.text = ""
          textGroup.text = ""
          textSize.text = ""
          textDistance.text = ""
          textCoordinates.text = ""
      }
    }
 }

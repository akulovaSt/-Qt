import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным (за исключением этого диалогового окна,
                                   //все окно приложения не может принимать ответы пользователя и находится в состоянии ожидания,
                                   //пока модальное диалоговое окно не будет закрыто)
    title: qsTr("Редактирование информации о звезде")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    property int currentIndex: -1

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
            placeholderText: qsTr("Введите название созвездия")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Видимая звездная величина")
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

    /*Button {
        visible: {textName.length>0 && textGroup.length>0 && root.currentIndex <0}
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
    }*/

    Button {
        visible: {root.currentIndex>=0}
        anchors {
            right: buttonCancel.left;
            verticalCenter: buttonCancel.verticalCenter;
            rightMargin: 10
        }
        text: qsTr("Применить")
        width: 100
        onClicked: {
            root.hide()
            edit(textName.text, textGroup.text, textSize.text, textDistance.text, textCoordinates.text, root.currentIndex)
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
        text: qsTr("Отмена")
        width: 100
        onClicked: {
             root.hide()
        }
    }


    function execute(name, group, size, distance, coordinates, index){
        textName.text = name
        textGroup.text = group
        textSize.text = size
        textDistance.text = distance
        textCoordinates.text = coordinates
        root.currentIndex = index

        root.show()
    }
 }

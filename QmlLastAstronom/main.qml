import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0

Window {
    visible: true
    width: 800
    height: 550
    title: qsTr("СПРАВОЧНИК АСТРОНОМА")

    SystemPalette {
        id: palette;
        colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left//якори
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: butAdd.top
        anchors.bottomMargin: 8
        border.color: "#806b2a"        

    ScrollView {
        anchors.fill: parent
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15

    ListView {
        id: starList
        anchors.fill: parent
        model: starModel // назначение модели, данные которой отображаются списком
        delegate: DelegateForStar{}
        clip: true //чтобы контент не выходил за границы ListView
        activeFocusOnTab: true  // реагирование на перемещение между элементами ввода с помощью Tab
        focus: true  // элемент может получить фокус
        }
    }
    }

    Button {
        id: butAdd
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.right:butEdit.left
        text: "Добавить"
        width: 100
        onClicked: windowAdd.show()    
    }

    Button {
        id: butEdit
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: butDel.left
        anchors.rightMargin: 8
        text: "Изменить"
        width: 100
        onClicked: {
            var nameStar = starList.currentItem.starData.nameOfStar
            var groupStar = starList.currentItem.starData.groupOfStar
            var sizeStar = starList.currentItem.starData.sizeOfStar
            var distanceStar = starList.currentItem.starData.distanceOfStar
            var coordinatesStar = starList.currentItem.starData.coordinatesOfStar

            windowEdit.execute(nameStar, groupStar, sizeStar, distanceStar, coordinatesStar, starList.currentIndex)
        }
    }

    Button {
        id: butDel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right:parent.right
        anchors.rightMargin: 8
        text: "Удалить"
        width: 100
        enabled: starList.currentIndex >= 0
        onClicked: del(starList.currentIndex)
    }

        Label {
            id: labelSize
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 12
            anchors.left: parent.left
            anchors.rightMargin: 8
            anchors.leftMargin: 8
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Введите необходимую звездную величину:")
            }

        TextField {
            id: textFindSize
            Layout.fillWidth: true
            placeholderText: qsTr("")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.leftMargin: 8
            anchors.left: labelSize.right
            anchors.rightMargin: 8
            }

    Button {
            id: butCount
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            anchors.left: textFindSize.right
            anchors.leftMargin: 8
            text: "Найти"
            width: 85
            enabled: textFindSize.text != ""
            onClicked: windowAnswer.countStars(textFindSize.text)
        }

    DialogForAdd {
        id: windowAdd
    }
    DialogForEdit {
        id: windowEdit
    }
    DialogForAnswer {
        id: windowAnswer
    }
}

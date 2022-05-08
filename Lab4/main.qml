import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.5  // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 1.2


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Справочник астронома")

    // объявляется системная палитра
    SystemPalette {
          id: palette;
          colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: btnAdd.top
        anchors.bottomMargin: 8
        border.color: "gray"

    ScrollView {
        anchors.fill: parent

        Text {
            anchors.fill: parent
            text: "Could not connect to SQL"
            color: "red"
            font.pointSize: 20
            font.bold: true
            visible: IsConnectionOpen == false
        }

        ListView {
            id: starList
            anchors.fill: parent
            model: starModel // назначение модели, данные которой отображаются списком
            delegate: DelegateForStar{}
            clip: true //
            activeFocusOnTab: true  // реагирование на перемещение между элементами ввода с помощью Tab
            focus: true  // элемент может получить фокус
            opacity: {if (IsConnectionOpen == true) {100} else {0}}
        }

    }
   }

    Button {
        id: btnAdd
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.right:btnEdit.left
        text: "Добавить"
        width: 100

        onClicked: {
            windowAddEdit.currentIndex = -1
            windowAddEdit.show()
        }
    }

    Button {
        id: btnEdit
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: btnDel.left
        anchors.rightMargin: 8
        text: "Редактировать"
        width: 100
        onClicked: {
            var nameStar = starList.currentItem.personData.NameOfstar
            var groupStar = starList.currentItem.personData.GroupOfStar
            var sizeStar = starList.currentItem.personData.SizeOfStar
            var distanceStar = starList.currentItem.personData.DistanceOfStar
            var coordinatesStar = starList.currentItem.personData.CoordinatesOfStar
            var elementID = starList.currentItem.personData.Id_star

            windowAddEdit.execute(nameStar, groupStar, sizeStar, distanceStar, coordinatesStar, elementID)
        }
    }

    Button {
        id: btnDel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right:parent.right
        anchors.rightMargin: 8
        text: "Удалить"
        width: 100
        enabled: {
            if (starList.currentItem==null || starList.currentItem.personData == null)
            {false}
            else
            {starList.currentItem.personData.Id_star >= 0} }
        onClicked: del(starList.currentItem.personData.Id_star)
    }

    DialogForAddorEdit {
        id: windowAddEdit
    }
}

import QtQuick 2.6
import QtQuick.Controls 2.5  // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 1.2

Rectangle {
    id: starItem
    readonly property color evenBackgroundColor: "#faf2fa"  // цвет для четных пунктов списка
    readonly property color oddBackgroundColor: "#ebcef2"   // цвет для нечетных пунктов списка
    readonly property color selectedBackgroundColor: "#ba55d3"  // цвет выделенного элемента списка

    property bool isCurrent: starItem.ListView.view.currentIndex === index   // назначено свойство isCurrent истинно для текущего (выделенного) элемента списка
    property bool selected: starItemMouseArea.containsMouse || isCurrent // назначено свойство "быть выделенным",
    //которому присвоено значение "при наведении мыши,
    //или совпадении текущего индекса модели"

    property variant personData: model // свойство для доступа к данным конкретного студента

    width: parent ? parent.width : starList.width
    height: 160

    // состояние текущего элемента (Rectangle)
    states: [
        State {
            when: selected
            // как реагировать, если состояние стало selected
            PropertyChanges { target: starItem;  // для какого элемента должно назначаться свойство при этом состоянии (selected)
                color: isCurrent ? "#EA8DF7" : selectedBackgroundColor  /* какое свойство целевого объекта (Rectangle)
                                                                                                  и какое значение присвоить*/
            }
        },
        State {
            when: !selected
            PropertyChanges { target: starItem;  color: isCurrent ? palette.highlight : index % 2 == 0 ? evenBackgroundColor : oddBackgroundColor }
        }
    ]

    MouseArea {
        id: starItemMouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            starItem.ListView.view.currentIndex = index
            starItem.forceActiveFocus()
        }
    }
    Item {
        id: itemOfStar
        width: parent.width
        height: 160
        Column{
            id: t2
            anchors.left: parent.left
            anchors.leftMargin: 10
            width: 240
            anchors.verticalCenter: parent.verticalCenter
            Text {
                id: t1
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Название звезды:"
                color: "black"
                font.pointSize: 12
            }
            Text {
                id: textName
                anchors.horizontalCenter: parent.horizontalCenter
                text: NameOfStar
                color: "black"
                font.pointSize: 18
                font.bold: true
            }
        }

        Column{
            anchors.left: t2.right
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            Text {

                text: "Созвездие:"
                color: "black"
                font.pointSize: 10
            }
            Text {
                id: textGroup
                text: GroupOfStar
                color: "black"
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: "Видимая звездная величина:"
                color: "black"
                font.pointSize: 10
            }
            Text {
                id: textSize
                color: "black"
                text: SizeOfStar
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: "Расстояние от Земли:"
                color: "black"
                font.pointSize: 10
            }
            Text {
                id: textDistance
                text: DistanceOfStar
                color: "black"
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: "Координаты на небосклоне:"
                color: "black"
                font.pointSize: 10
            }
            Text {
                id: textCoordinates
                text: CoordinatesOfStar
                color: "black"
                font.pointSize: 12
                font.bold: true
            }
        }

    }
}


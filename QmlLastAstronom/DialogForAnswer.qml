import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Результат поиска")
    width: 220
    height: 50

    property int currentIndex: -1

    GridLayout {
        anchors {
            left: parent.left;
            top: parent.top;
            right: parent.right;
            margins: 10
        }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Количество найденных звезд:")
        }
        TextField {
            id: textCount
            Layout.fillWidth: true // чтобы все колонки имели одинаковую ширину и заполняли всё пространство
        }
    }

    function countStars(size){
        textCount.text = count(size);
        root.show()
    }
 }


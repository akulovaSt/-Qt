#include "groupdelegate.h"
#include "QtWidgets"
#include "star.h"

GroupDelegate::GroupDelegate(QObject *parent): QItemDelegate(parent)
{

}


QWidget *GroupDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
{
    QComboBox* cmb = new QComboBox(parent);
    QStringList groups = Star::GetGroups();
    foreach  (QString gr, groups)
    {
        cmb->addItem(gr);
    }
    return cmb;
}

void GroupDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *myeditor = static_cast<QComboBox*>(editor);

    QString value = myeditor->currentText();

    model->setData(index, value, Qt::EditRole);
}

void GroupDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *myeditor = qobject_cast<QComboBox *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    const int cbIndex = myeditor->findText(currentText);
    if (cbIndex >= 0)
       myeditor->setCurrentIndex(cbIndex);
}

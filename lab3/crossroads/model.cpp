#include "model.hpp"

CrossroadsModel::CrossroadsModel(QObject *parent, int count) :
    QAbstractListModel(parent)
{}

int CrossroadsModel::rowCount(const QModelIndex &parent) const
{
    return _list.count();
}

QVariant CrossroadsModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
        return _list.at(index.row());
    default:
        return QVariant();
    }
}

bool CrossroadsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
        _list.replace(index.row(), value.toString());
}

Qt::ItemFlags CrossroadsModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

void CrossroadsModel::setStringList(const QStringList & list) {
    _list = list;
    emit dataChanged(QModelIndex(), QModelIndex());
}

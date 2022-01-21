#ifndef MODEL_HPP
#define MODEL_HPP

#include <QAbstractListModel>
#include <QStringList>

class CrossroadsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    QStringList _list;
    explicit CrossroadsModel(QObject * parent = 0, int count = 0);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;

    void setStringList(const QStringList & list);
private:

signals:

public slots:
};

#endif // MODEL_HPP

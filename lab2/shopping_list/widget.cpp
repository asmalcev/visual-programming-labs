#include "widget.h"
#include "ui_widget.h"

#include <QDateTime>
#include <QtXml>
#include <QMessageBox>
#include <QInputDialog>
#include <QXmlStreamWriter>
#include <QColor>

#include <iostream>
#include <fstream>
#include <sstream>

constexpr char * DATE_FORMAT = "dd.MM.yyyy";
const QColor SUM_COLOR(129, 212, 250);

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("Shopping List");

    ui->productDateInput->setDateTime( QDateTime::currentDateTime() );

    QFile input_file("data.xml");
    QDomDocument document;

    if (!input_file.open(QIODevice::ReadOnly))
        return;
    if (!document.setContent(&input_file)) {
        input_file.close();
        return;
    }
    input_file.close();

    ui->treeWidget->clear();
    QDomElement docElem = document.documentElement();
    QDomNode n = docElem.firstChild();
    while (!n.isNull()) {
        QDomElement e = n.toElement();
        if(!e.isNull() && e.tagName() == "date") {

            QStringList sl;
            sl << e.attribute("when");
            QTreeWidgetItem * item = new QTreeWidgetItem(sl);
            ui->treeWidget->addTopLevelItem(item);

            int summaryCost = 0;

            QDomNode product = n.firstChild();
            while (!product.isNull()) {
                QDomElement product_el = product.toElement();
                if (!product_el.isNull()) {
                    sl.clear();
                    sl << product_el.attribute("what") << product_el.attribute("cost");
                    summaryCost += product_el.attribute("cost").toInt();
                    QTreeWidgetItem * product_item = new QTreeWidgetItem(sl);
                    item->addChild(product_item);
                }
                product = product.nextSibling();
            }

            sl.clear();
            sl << "Summary cost" << QString::number( summaryCost );
            QTreeWidgetItem * cost_item = new QTreeWidgetItem(sl);
            cost_item->setBackgroundColor(0, SUM_COLOR);
            cost_item->setBackgroundColor(1, SUM_COLOR);
            item->addChild(cost_item);

        }
        n = n.nextSibling();
    }
}

Widget::~Widget()
{
    QString output;
    QXmlStreamWriter stream(&output);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("shoppingList");

    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
        QString date_output;
        QXmlStreamWriter date_stream(&date_output);
        date_stream.setAutoFormatting(true);

        QTreeWidgetItem * item = ui->treeWidget->topLevelItem(i);

        date_stream.writeStartElement("date");
        date_stream.writeAttribute("when", item->text(0));
        for (int j = 0; j < item->childCount(); j++) {
            if (item->child(j)->text(0) == "Summary cost") continue;

            date_stream.writeEmptyElement("product");
            date_stream.writeAttribute("what", item->child(j)->text(0));
            if (!item->child(j)->text(1).isEmpty()) {
                date_stream.writeAttribute("cost", item->child(j)->text(1));
            }
        }
        date_stream.writeEndElement();

        stream.writeDTD(date_output);
    }

    stream.writeEndElement();
    stream.writeEndDocument();

    std::ofstream output_file("data.xml", std::ofstream::out | std::ofstream::trunc);
    if (output_file.is_open()) {
        output_file << output.toStdString();
    } else {
        std::cerr << "Can't open file data.xml to write" << std::endl;
    }

    output_file.close();

    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString productName = ui->productNameInput->text();
    QDateTime productDate = QDateTime( ui->productDateInput->date() );

    if (productName.size() == 0) {
        QMessageBox msgBox;
        msgBox.setText("Product name cannot be empty");
        msgBox.exec();

        return;
    }

    int itemIndex = -1, i;
    for (i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
        QDateTime currentItemDate = QDateTime::fromString( ui->treeWidget->topLevelItem(i)->text(0), DATE_FORMAT );
        if (currentItemDate == productDate) {
            itemIndex = i;
            break;
        } else if (currentItemDate > productDate) {
            break;
        }
    }

    QTreeWidgetItem * item;
    if (itemIndex == -1) {
        QStringList sl;
        sl << productDate.toString(DATE_FORMAT);

        item = new QTreeWidgetItem(sl);
        ui->treeWidget->insertTopLevelItem(i, item);
    } else {
        item = ui->treeWidget->topLevelItem(itemIndex);
    }

    QStringList sl;
    sl << productName;
    QTreeWidgetItem * sub_item = new QTreeWidgetItem(sl);
    item->addChild(sub_item);

    item->setExpanded(true);
    ui->productNameInput->setText(tr(""));

    countNewSum(item);
}

void Widget::on_treeWidget_itemDoubleClicked(QTreeWidgetItem * item, int column)
{
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
        if (item == ui->treeWidget->topLevelItem(i)) {
            return;
        }
    }
    if (!item->text(1).isEmpty()) {
        return;
    }

    bool ok;
    int cost = QInputDialog::getInt(this,
        tr("Enter the cost of the product"),
        tr("Product's cost:"),
        100, 0, 100000, 1,
        &ok
    );
    if (ok) {
        item->setText(1, QString::number(cost));
    }

    countNewSum(item->parent());
}

void Widget::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("All products will be removed");
    msgBox.setInformativeText("Do you want to remove it?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Ok) {
        ui->treeWidget->clear();
    }
}


void Widget::countNewSum(QTreeWidgetItem * item) {
    int sum = 0;
    for (int i = 0; i < item->childCount(); i++) {
        if (item->child(i)->text(0) == "Summary cost") {
            item->removeChild( item->child(i) );

            if (item->childCount() == i) break;
        }
        sum += item->child(i)->text(1).toInt();
    }

    QStringList sl;
    sl << "Summary cost" << QString::number( sum );
    QTreeWidgetItem * cost_item = new QTreeWidgetItem(sl);
    cost_item->setBackgroundColor(0, SUM_COLOR);
    cost_item->setBackgroundColor(1, SUM_COLOR);
    item->addChild(cost_item);
}

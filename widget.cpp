#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCOFFEE->setEnabled(false);
    ui->pbTEA->setEnabled(false);
    ui->pbMILK->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);
    SetButton();
}

void Widget::SetButton(void)  {
    if (money < 100) {
        ui->pbCOFFEE->setEnabled(false);
    }
    else {
        ui->pbCOFFEE->setEnabled(true);
    }

    if (money < 150) {
        ui->pbTEA->setEnabled(false);
    }
    else {
        ui->pbTEA->setEnabled(true);
    }

    if (money < 200) {
        ui->pbMILK->setEnabled(false);
    }
    else {
        ui->pbMILK->setEnabled(true);
    }
}

void Widget::on_pbCOIN10_clicked()
{
    ChangeMoney(10);
}


void Widget::on_pbCOIN50_clicked()
{
    ChangeMoney(50);
}


void Widget::on_pbCOIN100_clicked()
{
    ChangeMoney(100);
}


void Widget::on_pbCOIN500_clicked()
{
    ChangeMoney(500);
}


void Widget::on_pbCOFFEE_clicked()
{
    ChangeMoney(-100);
}


void Widget::on_pbTEA_clicked()
{
    ChangeMoney(-150);
}


void Widget::on_pbMILK_clicked()
{
    ChangeMoney(-200);
}


void Widget::on_pbRESET_clicked()
{
    QMessageBox mb;
    int coin500 = money / 500;
    money %= 500;
    int coin100 = money / 100;
    money %= 100;
    int coin50 = money / 50;
    money %= 50;
    int coin10 = money / 10;

    char content[100];
    sprintf(content, "500 coin: %d\n100 coin: %d\n50 coin: %d\n10 coin: %d", coin500, coin100, coin50, coin10);

    mb.information(this, "changes", content);
    ChangeMoney(-money);
}


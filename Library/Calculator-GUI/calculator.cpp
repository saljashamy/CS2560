#include "calculator.h"
#include "ui_calculator.h"
#include <iostream>

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

void Calculator::getInput()
{
    A = BigNumbers(ui->a->toPlainText().toStdString());
    B = BigNumbers(ui->b->toPlainText().toStdString());
}

void Calculator::on_add_released()
{
    getInput();
    result = A + B;
    QString strResult = QString::fromStdString(result.toString());
    ui->result->setPlainText(strResult);
}

void Calculator::on_subtract_released()
{
    getInput();
    result = A - B;
    QString strResult = QString::fromStdString(result.toString());
    ui->result->setPlainText(strResult);
}

void Calculator::on_multiply_released()
{
    getInput();
    result = A * B;
    QString strResult = QString::fromStdString(result.toString());
    ui->result->setPlainText(strResult);
}

void Calculator::on_divide_released()
{
    getInput();
    result = A / B;
    QString strResult = QString::fromStdString(result.toString());
    ui->result->setPlainText(strResult);
}

void Calculator::on_modulo_released()
{
    getInput();
    result = A % B;
    QString strResult = QString::fromStdString(result.toString());
    ui->result->setPlainText(strResult);
}

Calculator::~Calculator()
{
    delete ui;
}

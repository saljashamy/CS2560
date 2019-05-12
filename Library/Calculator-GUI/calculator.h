#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "BigNumbers.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    BigNumbers A;
    BigNumbers B;
    BigNumbers result;
    void getInput();

private slots:
    void on_add_released();
    void on_subtract_released();
    void on_multiply_released();
    void on_divide_released();
    void on_modulo_released();
};

#endif // CALCULATOR_H

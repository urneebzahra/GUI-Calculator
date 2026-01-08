#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    firstNumber = 0;

    // Number buttons
    connect(ui->btn0, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btn1, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btn2, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btn3, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btn4, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btn5, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btn6, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btn7, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btn8, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btn9, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->btnDot, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
// Operator buttons
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnSub, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnMul, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnDiv, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);

    // Equal & Clear
    connect(ui->btnEqual, &QPushButton::clicked, this, &MainWindow::onEqualClicked);
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::onClearClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------- Slots Implementation ----------

void MainWindow::onNumberClicked()
{
    QPushButton *button = (QPushButton*)sender();
    ui->display->setText(ui->display->text() + button->text());
}

void MainWindow::onOperatorClicked()
{
    QPushButton *button = (QPushButton*)sender();
    firstNumber = ui->display->text().toDouble();
    currentOperator = button->text();
    ui->display->clear();
}

void MainWindow::onEqualClicked()
{
    double secondNumber = ui->display->text().toDouble();
    double result = 0;

    if (currentOperator == "+")
        result = firstNumber + secondNumber;
    else if (currentOperator == "-")
        result = firstNumber - secondNumber;
    else if (currentOperator == "*")
        result = firstNumber * secondNumber;
    else if (currentOperator == "/")
        result = firstNumber / secondNumber;

    ui->display->setText(QString::number(result));
}

void MainWindow::onClearClicked()
{
    ui->display->clear();
    firstNumber = 0;
    currentOperator.clear();
}

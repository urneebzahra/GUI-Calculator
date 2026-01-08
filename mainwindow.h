#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNumberClicked();
    void onOperatorClicked();
    void onEqualClicked();
    void onClearClicked();

private:
    Ui::MainWindow *ui;
    double firstNumber;
    QString currentOperator;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setMessages();
    void checkDirectory();
    void resizeQComboBoxes();
    std::string getFileDirectory();
    void updateDebitList();
    void updateCreditList();
    std::string monthToNum(std::string month);
    void setSpecialRules();
    std::string ithWord(std::string text, int ith);
    void updateLCD();
    std::string spacesToNonSpace(std::string text);

private slots:


    void on_CreateButton_clicked();

    void on_NewItemButton_clicked();

    void on_LoadButton_clicked();

    void on_FinishedButton_clicked();

    void on_DebitRemoveButton_clicked();

    void on_CreditRemoveButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

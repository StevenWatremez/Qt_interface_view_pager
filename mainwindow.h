#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Individu.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    vector<Individu> readIndividuFromFile(const string filename);

private slots:
    void on_previousButton_clicked();

    void on_nextButton_clicked();

private:
    Ui::MainWindow *ui;
    vector<Individu> vec_individus;
    int vectorIndex = 0;
};

#endif // MAINWINDOW_H

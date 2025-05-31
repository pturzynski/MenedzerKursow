#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H
#include "loginwindow.h"
#include <QMainWindow>

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(CourseManager* cm, QWidget *parent = nullptr);
    ~StudentWindow();

    void fillKursyTable();
    void fillMojeKursyTable();

private slots:
    void on_wylogujButton_clicked();
    void on_zapiszKursButton_clicked();

private:
    CourseManager *cm;
    Ui::StudentWindow *ui;
};

#endif // STUDENTWINDOW_H

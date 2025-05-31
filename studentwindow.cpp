#include "studentwindow.h"
#include "ui_studentwindow.h"

StudentWindow::StudentWindow(CourseManager* cm, QWidget *parent)
    : QMainWindow(parent),
    cm(cm),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
    fillCoursesTable();
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::on_wylogujButton_clicked()
{
    LoginWindow *login = new LoginWindow(cm);
    login->show();
    this->close();
}

void StudentWindow::fillCoursesTable()
{
    QList<Course> courses = cm->getCourses();

    ui->listaKursowTableWidget->setRowCount(courses.size());
    ui->listaKursowTableWidget->setColumnCount(2);

    QStringList headers;
    headers << "Nazwa" << "Opis";
    ui->listaKursowTableWidget->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < courses.size(); ++row) {
        const Course& course = courses.at(row);

        ui->listaKursowTableWidget->setItem(row, 0, new QTableWidgetItem(course.getName()));
        ui->listaKursowTableWidget->setItem(row, 1, new QTableWidgetItem(course.getDescription()));
    }
}

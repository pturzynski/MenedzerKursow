#include "coursemanager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

CourseManager::CourseManager() {
    loadStudentCourses();

    if (allCourses.isEmpty() && studentCourses.isEmpty()){
        allCourses.append(Course(nextId++, "Matematyka", "Podstawy matematyki"));
        allCourses.append(Course(nextId++, "Fizyka", "Podstawy fizyki"));
        allCourses.append(Course(nextId++, "Programowanie", "Nauka programowania w C++"));
        allCourses.append(Course(nextId++, "Chemia", "Podstawy chemii"));
        allCourses.append(Course(nextId++, "Biologia", "Podstawy biologii"));
    }
}

QList<Course> CourseManager::getAllCourses() const
{
    return allCourses;
}

QList<Course> CourseManager::getStudentCourses() const
{
    return studentCourses;
}

void CourseManager::saveStudentCourses()
{
    QFile file("kursystudenta.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Nie można otworzyć pliku do zapisu!";
        return;
    }
    QTextStream out(&file);
    for (const Course &course : studentCourses)
    {
        out << course.getId() << "|" << course.getName() << "|" << course.getDescription() << "\n";
    }
    file.close();
}
void CourseManager::loadStudentCourses()
{
    QFile file("kursystudenta.txt");
    if (!file.exists())
    {
        //tworzenie pliku jesli nie istnieje
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Nie można utworzyć pliku kursystudenta.txt";
            return;
        }
        file.close();
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Nie można otworzyć pliku do odczytu.";
        return;
    }

    studentCourses.clear();

    QTextStream in(&file);
    bool hasData = false;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (line.trimmed().isEmpty())
            continue;

        hasData = true;

        QStringList parts = line.split("|");
        if (parts.size() == 3)
        {
            bool ok = false;
            int id = parts[0].toInt(&ok);
            if (!ok)
                continue;

            bool found = false;
            for (int i = 0; i < allCourses.size(); ++i)
            {
                if (allCourses[i].getId() == id)
                {
                    studentCourses.append(allCourses[i]);
                    allCourses.removeAt(i);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                studentCourses.append(Course(id, parts[1], parts[2]));
            }
        }
    }
    file.close();
}

bool CourseManager::enrollStudent(int courseId)
{
    for (int i = 0; i < allCourses.size(); ++i)
    {
        if (allCourses[i].getId() == courseId)
        {
            studentCourses.append(allCourses[i]);
            allCourses.removeAt(i);
            saveStudentCourses(); // zapis do pliku po zapisie kursu
            return true;
        }
    }
    return false; // kurs nie znaleziony
}

bool CourseManager::addCourse(const User* user, const QString& name, const QString& description)
{
    if (!user->isAdmin())
        return false;

    allCourses.append(Course(nextId++, name, description));
    return true;
}

bool CourseManager::removeCourse(const User* user, int courseId)
{
    if (!user->isAdmin())
        return false;

    for (int i = 0; i < allCourses.size(); ++i)
    {
        if (allCourses[i].getId() == courseId)
        {
            allCourses.removeAt(i);
            return true;
        }
    }
    return false;
}

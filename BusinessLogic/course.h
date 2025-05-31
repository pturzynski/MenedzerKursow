#ifndef COURSE_H
#define COURSE_H
#include <QString>
#include <QList>
#include "BusinessLogic_global.h"
using namespace std;
class BUSINESSLOGIC_EXPORT Course
{
private:
    QString name;
    QString description;
    int id;
    QList<QString> enrolledStudents;
public:
    Course(int id, const QString &name, const QString &description);

    int getId() const;
    QString getName() const;
    QString getDescription() const;
    void enrollStudent(const QString &nick);
    const QList<QString> getEnrolledStudents() const;
    bool isStudentEnrolled(const QString &nick) const;
};

#endif // COURSE_H

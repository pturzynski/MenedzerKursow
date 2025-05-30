#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
#include<vector>
class Course
{
private:
    string name;
    string description;
    int id;
    vector<string> enrolledStudents;
public:
    Course(int id, const string &name, const string &description);

    int getId() const;
    string getName() const;
    string getDescription() const;
    void enrollStudent(const string &nick);
    const vector<string> getEnrolledStudents() const;
    bool isStudentEnrolled(const string &nick) const;
};

#endif // COURSE_H

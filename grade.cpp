#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student
{
    private:
    string f_name, l_name;
    string ID;

    public:
    Student(string f_name, string l_name, string ID)
    {
        this->f_name = f_name;
        this->l_name = l_name;
        this->ID = ID;
    }
    string get_f_name() const
    {
       return f_name;
    }
     string get_l_name() const
    {
       return l_name;
    }
    string get_ID() const
    {
       return ID;
    }


};
class Assignment
{
    private:
    string assignment;
    int total_points;

    public:
    Assignment(string assignment, int total_points)
    {
        this->assignment = assignment;
        this->total_points = total_points;
    }
    string get_assignment() const
    {
       return assignment;
    }
    int get_total_points() const
    {
       return total_points;
    }


};

class Grade
{
    private:
    string f_name, l_name;
    string assignment;
    int grade;

    public:
    Grade(string f_name, string l_name, string assignment, int grade)
    {
        this->f_name = f_name;
        this->l_name = l_name;
        this->assignment = assignment;
        this->grade = grade;
    }
    string get_f_name() const
    {
       return f_name;
    }
    string get_l_name() const
    {
       return l_name;
    }
    string get_assignment() const
    {
       return assignment;
    }
    int get_grade() const
    {
       return grade;
    }

};

class Gradebook
{
    private:
    vector<Student>students;
    vector<Assignment>assignments;
    vector<Grade>grades;

    public:
    void add_student(string f_name, string l_name, string ID);
    void add_assignment(string assignment, int total_points);
    void enter_grade(string f_name, string l_name, string assignment, int grade);
    void report();


};
void Gradebook::add_student(string f_name, string l_name, string ID)
{
    this->students.push_back(Student(f_name, l_name,ID));
}
void Gradebook::add_assignment(string assignment, int total_points)
{
    this->assignments.push_back(Assignment(assignment, total_points));
}
void Gradebook::enter_grade(string f_name, string l_name, string assignment, int grade)
{
    this->grades.push_back(Grade(f_name, l_name, assignment, grade));
}
void Gradebook::report() {

   
    for (Student student : students) 
    {
        cout << student.get_l_name() << "," << student.get_f_name() << "," << student.get_ID();

        for (Assignment assignment : assignments) {
            bool no_grade = false;
            for (Grade grade : grades) {
                if (grade.get_f_name() == student.get_f_name() &&
                    grade.get_l_name() == student.get_l_name() &&
                    grade.get_assignment() == assignment.get_assignment()) {
                    cout << "," << grade.get_grade();
                    no_grade = true;
                    break;
                }
            }
            if (!no_grade) {
                cout << ",none"; 
            }
        }
        cout << endl;
    }
}

int main()
{
    Gradebook gradebook;
    gradebook.add_student("Bob", "Bobberson", "ABC123");
    gradebook.add_student("Sam", "Sammerson", "DEF456");
    gradebook.add_student("Jess", "Jesserson", "HIJ789");

    gradebook.add_assignment("Quiz 1", 100);
    gradebook.add_assignment("Lab 1", 50);

    gradebook.enter_grade("Sam", "Sammerson", "Quiz 1", 95);
    gradebook.enter_grade("Bob","Bobberson", "Quiz 1", 85);
    gradebook.enter_grade("Jess", "Jesserson", "Lab 1", 49);
    gradebook.enter_grade("Jess", "Jesserson", "Quiz 1", 93);
    gradebook.enter_grade("Bob", "Bobberson", "Lab 1", 0);

    gradebook.report();
}

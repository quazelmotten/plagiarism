using namespace std;

class Student {
private:
    string studentName;
    vector<int> grades;

public:
    Student(string name) : studentName(name) {}

    void recordGrade(int grade) {
        grades.push_back(grade);
    }

    double getAverage() const {
        double total = 0;
        for (int i = 0; i < grades.size(); i++) {
            total += grades[i];
        }
        return grades.empty() ? 0.0 : total / grades.size();
    }

    void displayStudentInfo() const {
        cout << "Name: " << studentName << endl;
        cout << "Grades: ";
        for (size_t i = 0; i < grades.size(); i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
        cout << "Average Grade: " << fixed << setprecision(2) << getAverage() << endl;
    }
};

class Gradebook {
private:
    vector<Student> students;

public:
    void addStudent(const string& name) {
        students.push_back(Student(name));
    }

    void assignGradeToStudent(const string& name, int grade) {
        for (auto& student : students) {
            if (student.getName() == name) {
                student.recordGrade(grade);
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void printAllReports() const {
        for (const auto& student : students) {
            student.displayStudentInfo();
            cout << "=====================" << endl;
        }
    }
};

int main() {
    Gradebook gb;

    gb.addStudent("Alice");
    gb.addStudent("Bob");

    gb.assignGradeToStudent("Alice", 88);
    gb.assignGradeToStudent("Alice", 94);
    gb.assignGradeToStudent("Bob", 75);
    gb.assignGradeToStudent("Bob", 82);

    gb.printAllReports();

    return 0;
}

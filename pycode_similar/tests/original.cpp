using namespace std;

class Student {
private:
    string name;
    vector<int> grades;

public:
    Student(string studentName) : name(studentName) {}

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    double calculateAverage() {
        double sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return grades.empty() ? 0.0 : sum / grades.size();
    }

    void printReport() {
        cout << "Student: " << name << endl;
        cout << "Grades: ";
        for (int grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
        cout << "Average: " << fixed << setprecision(2) << calculateAverage() << endl;
    }
};

class Gradebook {
private:
    vector<Student> students;

public:
    void addStudent(string name) {
        students.push_back(Student(name));
    }

    void addGradeToStudent(string name, int grade) {
        for (Student &student : students) {
            if (student.getName() == name) {
                student.addGrade(grade);
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void generateReports() {
        for (Student &student : students) {
            student.printReport();
            cout << "----------------------------" << endl;
        }
    }
};

int main() {
    Gradebook gradebook;

    // Add students
    gradebook.addStudent("Alice");
    gradebook.addStudent("Bob");

    // Add grades
    gradebook.addGradeToStudent("Alice", 88);
    gradebook.addGradeToStudent("Alice", 94);
    gradebook.addGradeToStudent("Bob", 75);
    gradebook.addGradeToStudent("Bob", 82);

    // Generate reports
    gradebook.generateReports();

    return 0;
}

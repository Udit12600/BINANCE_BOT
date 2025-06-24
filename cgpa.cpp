#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Course {
    string courseName;
    float grade;        // on a 4.0 or 10.0 scale (depending on your system)
    int creditHours;
};

int main() {
    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    float totalGradePoints = 0;
    int totalCredits = 0;

    // Input loop
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter details for course " << i + 1 << ":\n";
        cout << "Course Name: ";
        cin >> ws; // consume newline
        getline(cin, courses[i].courseName);

        cout << "Grade (e.g., 8.5 or 3.7): ";
        cin >> courses[i].grade;

        cout << "Credit Hours: ";
        cin >> courses[i].creditHours;

        // Accumulate totals
        totalGradePoints += courses[i].grade * courses[i].creditHours;
        totalCredits += courses[i].creditHours;
    }

    // Compute CGPA
    float cgpa = totalGradePoints / totalCredits;

    // Display results
    cout << "\n--- Grade Report ---\n";
    cout << left << setw(20) << "Course"
         << setw(10) << "Grade"
         << setw(15) << "Credit Hours" << endl;

    for (const auto& course : courses) {
        cout << left << setw(20) << course.courseName
             << setw(10) << course.grade
             << setw(15) << course.creditHours << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Credit Hours: " << totalCredits << endl;
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}

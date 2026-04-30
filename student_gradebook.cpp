#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    vector<int> marks;
    double average;
    char grade;
};

char getGrade(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

double getAverage(vector<int>& marks) {
    int sum = 0;
    for (int m : marks) sum += m;
    return (double)sum / marks.size();
}

void displayStudent(Student& s, int rank) {
    cout << rank << ". " << s.name
         << " | Avg: " << s.average
         << " | Grade: " << s.grade << "\n";
}

int main() {
    vector<Student> students = {
        {"Alice",   {85, 90, 78, 92, 88}},
        {"Bob",     {70, 65, 72, 68, 75}},
        {"Charlie", {95, 98, 92, 96, 99}},
        {"Diana",   {55, 60, 58, 62, 57}},
        {"Eve",     {80, 82, 79, 85, 83}},
    };

    // Calculate average and grade for each student
    for (Student& s : students) {
        s.average = getAverage(s.marks);
        s.grade = getGrade(s.average);
    }

    // Sort by average descending
    sort(students.begin(), students.end(), [](Student& a, Student& b) {
        return a.average > b.average;
    });

    cout << "=== Student Gradebook ===\n\n";
    cout << "Rank | Name    | Average | Grade\n";
    cout << "-----+---------+---------+------\n";
    for (int i = 0; i < students.size(); i++)
        displayStudent(students[i], i + 1);

    cout << "\nTop student: " << students[0].name
         << " with average " << students[0].average << "\n";

    return 0;
}
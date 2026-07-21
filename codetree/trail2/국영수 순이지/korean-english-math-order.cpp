#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

class Student {
    public:
        string name;
        int kor;
        int eng;
        int math;

        Student(string name, int kor, int eng, int math) {
            this->name = name;
            this->kor = kor;
            this->eng = eng;
            this->math = math;
        }

        Student(){}
};

int n;

bool cmp(Student a, Student b) {
    return make_tuple(a.kor, a.eng, a.math) > make_tuple(b.kor, b.eng, b.math);
}

int main() {

    cin >> n;

    Student students[n];

    for(int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;
    }

    sort(students, students+n, cmp);

    for(int i = 0; i < n; i++) {
        cout << students[i].name << " " << students[i].kor << " " << students[i].eng << " " << students[i].math;
        cout << '\n';
    }


    return 0;
}
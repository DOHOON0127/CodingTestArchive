#include <iostream>
#include <algorithm>
using namespace std;

class Student{
    public:
        int height;
        int weight;
        int num;

        Student(int height, int weight, int num) {
            this->height = height;
            this->weight = weight;
            this->num = num;
        }

        Student() {}
};

bool cmp(Student a, Student b) {
    if(a.height != b.height) { 
        return a.height < b.height;
    }
    return a.weight > b.weight;
}

int n;
Student students[1000];

int main() {

    cin >> n;
    for(int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        students[i] = Student(h, w, i+1);
    }

    sort(students, students+n, cmp);

    for(int i = 0; i < n; i++) {
        cout << students[i].height << " ";
        cout << students[i].weight << " ";
        cout << students[i].num << "\n";
    }

    return 0;
}
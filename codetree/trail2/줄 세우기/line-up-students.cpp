#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

class Student {
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

bool cmp (Student a, Student b) {
    if(a.height == b.height) {
        if(a.weight == b.weight) {
            return a.num < b.num;
        }
        return a.weight > b.weight;
    }
    return a.height > b.height;
}

int main() {

    int n;
    cin >> n;

    Student students[n];

    for(int i = 0; i < n; i++) {
        students[i].num = i+1;
        cin >> students[i].height >> students[i].weight;
    }

    sort(students, students+n, cmp);

    for(int i = 0; i < n; i++) {
        cout << students[i].height << " " << students[i].weight << " " << students[i].num << '\n';
    }

    return 0;
}
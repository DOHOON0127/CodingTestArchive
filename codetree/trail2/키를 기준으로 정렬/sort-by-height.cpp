#include <iostream>
#include <algorithm>
using namespace std;

class Student{
    public:
        string name;
        int height;
        int weight;

        Student(string name, int height, int weight) {
            this->name = name;
            this->height = height;
            this->weight = weight;
        }

        Student(){}
};

int n;
string name[10];
int height[10];
int weight[10];

bool cmp(const Student &a, const Student &b) {
    return a.height < b.height; 
}

int main() {
    cin >> n;

    Student students[10];

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> height[i];
        cin >> weight[i];

        students[i] = Student(name[i], height[i], weight[i]);
    }

    sort(students, students+n, cmp);

    for (int i = 0; i < n; i++) {
        cout << students[i].name << " ";
        cout << students[i].height << " ";
        cout << students[i].weight << " ";
        cout << '\n';
    }


    return 0;
}
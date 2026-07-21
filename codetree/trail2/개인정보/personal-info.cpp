#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Person{
    public:
        string name;
        int height;
        float weight;

        Person(string name, int height, float weight){
            this->name = name;
            this->height = height;
            this->weight = weight;
        }

        Person() {}
};

bool cmp_name(Person a, Person b) {
    return a.name < b.name;
}

bool cmp_height(Person a, Person b) {
    return a.height > b.height;
}

Person persons[5];

int main() {

    for(int i = 0; i < 5; i++) {
        string name;
        int height;
        float weight;

        cin >> name >> height >> weight;

        persons[i] = Person(name, height, weight);
    }

    cout << fixed << setprecision(1);

    sort(persons, persons+5, cmp_name);

    cout << "name" << '\n';
    for(int i = 0; i < 5; i++) {
        cout << persons[i].name << " ";
        cout << persons[i].height << " ";
        cout << persons[i].weight << '\n';
    }
    cout << '\n';

    sort(persons, persons+5, cmp_height);

    cout << "height" << '\n';
    for(int i = 0; i < 5; i++) {
        cout << persons[i].name << " ";
        cout << persons[i].height << " ";
        cout << persons[i].weight << '\n';
    }

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    public:
        string name;
        int height;
        int weight;

        Person(string name, int height, int weight) {
            this->name = name;
            this->height = height;
            this->weight = weight;
        }

        Person() {}
};

bool cmp(Person a, Person b)
{
    if(a.height != b.height) {
        return a.height < b.height;
    }else {
        return a.weight > b.weight;
    }
}

int n;
Person persons[10];

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        string name;
        int height;
        int weight; 

        cin >> name >> height >> weight; 

        persons[i] = Person(name, height, weight);
    }

    sort(persons, persons+n, cmp);

    for(int i = 0; i < n; i++) {
        cout << persons[i].name << " ";
        cout << persons[i].height << " ";
        cout << persons[i].weight << '\n';
    }

    return 0;
}
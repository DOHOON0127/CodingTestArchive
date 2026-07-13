#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Person {
    public: 
        string name;
        string address;
        string loc;

        Person(string name, string address, string loc) {
            this->name = name;
            this->address = address;
            this->loc = loc;
        }

        Person(){}
};

int main() {

    int n;

    cin >> n;

    string name;
    string address;
    string loc;

    Person persons[11];

    vector<string> V;

    for(int i = 0; i < n; i++) {
        cin >> name >> address >> loc;
        persons[i] = Person(name, address, loc);
        V.push_back(name);
    }

    sort(V.begin(), V.end(), greater<string>());

    for(int i = 0; i < n; i++) {
        if(V[0] == persons[i].name) {
            cout << "name " << persons[i].name << '\n';
            cout << "addr " << persons[i].address << '\n';
            cout << "city " << persons[i].loc << '\n';
        }
    }

    return 0;
}
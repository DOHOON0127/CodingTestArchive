#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
string name[10];
int score1[10];
int score2[10];
int score3[10];

bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
    string name;
    int sc1, sc2, sc3;
    tie(name, sc1, sc2, sc3) = a;
    string name_b;
    int sc1_b, sc2_b, sc3_b;
    tie(name_b, sc1_b, sc2_b, sc3_b) = b;

    return sc1 + sc2 + sc3 < sc1_b + sc2_b + sc3_b;
}

int main() {
    cin >> n;

    tuple<string, int, int, int> students[10];

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> score1[i];
        cin >> score2[i];
        cin >> score3[i];

        students[i] = make_tuple(name[i], score1[i], score2[i], score3[i]);
    }

    sort(students, students+n, cmp);

    for(int i = 0; i < n; i++) {
        string name;
        int sc1, sc2, sc3;
        tie(name, sc1, sc2, sc3) = students[i];
        cout << name << " " << sc1 << " " << sc2 << " " << sc3;
        cout << '\n';
    }


    return 0;
}
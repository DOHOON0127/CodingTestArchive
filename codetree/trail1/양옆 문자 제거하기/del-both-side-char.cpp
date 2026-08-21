#include <iostream>
using namespace std;

int main() {

    string str;

    cin >> str ;

    str.erase(1,1);
    str.erase((int)str.size()-2, 1);

    cout << str;
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    int a;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
    }

    string str = to_string(sum);  

    cout << str.substr(1,(int)str.size()-1) + str.substr(0,1);

    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int n;
string arr[20];
char c;

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> c;

    int sum_str = 0;
    int cnt_str = 0;

    for(auto str : arr) {
        if(str[0] == c) {
            cnt_str++;
            sum_str += (int)str.length();
        }
    }

    cout << fixed << setprecision(2);
    cout << cnt_str << ' ';
    cout << (double)sum_str / cnt_str;

    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

string a;

int calculate(string str) {
    int sum = 0;

    for(int i = (int)str.length()-1; i >= 0; i--) {
        int start = 1;

        if(str[(int)str.length()-1 - i] == '1') {
            
            for(int j = 0; j < i; j++) {
                start = start * 2;
            }
            
            sum += start;

        }
        else {

        }

    }
    
    return sum;

}

int main() {

    cin >> a;

    int max_n = INT_MIN;

    for(int i = 0; i < (int)a.length(); i++) {

        string str = a;

        if(str[i] == '0') {
            str[i] = '1';
        }
        else {
            str[i] = '0';
        }

        // 이진수 계산하고

        max_n = max(max_n, calculate(str)); 

    }

    cout << max_n;

    return 0;
}
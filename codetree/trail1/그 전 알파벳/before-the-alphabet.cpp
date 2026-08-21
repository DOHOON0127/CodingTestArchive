#include <iostream>
using namespace std;

int main() {
    // Please write your code here.

    char c;
    cin >> c;

    if (c == 'a') {
        cout << 'z';
    } 
    // 그 외의 알파벳은 아스키 코드에서 -1 하여 이전 알파벳 출력
    else {
        cout << (char)(c - 1);
    } 

    return 0;
}
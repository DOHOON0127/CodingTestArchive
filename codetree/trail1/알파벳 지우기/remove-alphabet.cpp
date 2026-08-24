#include <iostream>
#include <string> // string과 stoi()를 사용하기 위해 추가
#include <cctype> // isdigit(), isalpha()를 사용하기 위해 추가

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int sum = 0;
    string temp_str = ""; // 숫자를 모아둘 문자열 바구니 생성

    // 1. 첫 번째 문자열(a)에서 숫자 떼어내기
    for(char c : a) {
        // !isalpha(c)도 좋지만, "숫자인지" 확인할 땐 isdigit(c)가 더 명확합니다.
        if(isdigit(c)) { 
            temp_str += c; // 바구니에 문자 이어 붙이기
        }
    }

    // 바구니에 숫자가 모였을 때만 더해주기 (예외 처리)
    if(temp_str != "") {
        sum += stoi(temp_str); // 문자열을 정수로 변환하여 더함
    }

    // 2. 바구니 초기화 (b를 담기 위해 비워줌)
    temp_str = ""; 

    // 3. 두 번째 문자열(b)에서 숫자 떼어내기
    for(char c : b) {
        if(isdigit(c)) {
            temp_str += c;
        }
    }

    if(temp_str != "") {
        sum += stoi(temp_str);
    }

    cout << sum;
    return 0;
}
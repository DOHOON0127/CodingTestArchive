#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    
    string str1;
    string str2;
    string str3;


    cin >> str1 >> str2 >> str3;

    // 길이를 int 타입으로 먼저 변환하여 저장
    int len1 = str1.size();
    int len2 = str2.size();
    int len3 = str3.size();

    int max_str = max({len1, len2, len3});
    int min_str = min({len1, len2, len3});

    cout << max_str - min_str;

    return 0;
}
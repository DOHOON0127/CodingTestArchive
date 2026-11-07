#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool cmp(const int &a, const int &b) {

    string ans1 = to_string(a) + to_string(b);
    string ans2 = to_string(b) + to_string(a);
    
    return ans1 > ans2;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for(int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    
    if(answer[0] == '0') {
        answer = "0";
    }
    
    return answer;
}
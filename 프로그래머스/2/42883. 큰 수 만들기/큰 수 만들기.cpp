#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int length = number.size() - k;
    
    // 1924
    // 9  4
    // 1231234
    //  3 1 2
    // 4177252841
    
    for(char c : number) {
        while(k > 0 && !answer.empty() && answer.back() < c) {
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }
    
    answer = answer.substr(0, length);
    
    return answer;
}
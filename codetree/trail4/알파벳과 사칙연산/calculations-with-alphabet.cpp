#include <iostream> 
#include <vector>
#include <climits>
using namespace std;

string str;
vector<char> letters;
int val[26];
long long answer = LLONG_MIN;

long long evaluate() {
    long long result = val[str[0] - 'a'];
    for(int i = 1; i < (int)str.size(); i += 2) {
        char op = str[i];

        long long operand = val[str[i+1] - 'a'];

        if(op == '+') result += operand;
        else if(op == '*') result *= operand;
        else if(op == '-') result -= operand;
    }
    return result;
}

void solve(int idx) {
    if(idx == (int)letters.size()) {
        answer = max(answer, evaluate());
        return;
    }
    for(int v = 1; v <= 4; v++) {
        val[letters[idx] - 'a'] = v;
        solve(idx + 1);
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    bool seen[26] = {false};
    for(char c : str) {
        if(c >= 'a' && c <= 'f' && !seen[c - 'a']) {
            seen[c - 'a'] = true;
            letters.push_back(c);
        }
    }

    solve(0);

    cout << answer << '\n';

    return 0;
}
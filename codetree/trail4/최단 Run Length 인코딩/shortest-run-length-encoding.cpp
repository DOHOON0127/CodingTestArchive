#include <bits/stdc++.h>
#include <climits>
using namespace std;

string RunLengthEncoding(string a) {

    string result = "";
    int count = 1;

    for (int i = 1; i < a.length(); i++) {
        if (a[i] == a[i-1]) {
            count++;
        }else {
            result += a[i-1] + to_string(count);
            count = 1;
        }
    }

    result += a[a.length()-1] + to_string(count);

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string A;

    cin >> A;

    int N = A.length();
    string S = A;
    int minLength = INT_MAX;

    for (int i = 0; i < N; i++) {
        A = S;
        for (int t = 0; t < i; t++) {
            char temp = A[N-1];

            for (int j = N-1; j > 0; j--) {
                A[j] = A[j-1];
            }

            A[0] = temp;
        }

        string t =  RunLengthEncoding(A);
        if (t.length() < minLength) {
            minLength = t.length();
        }
    }
    cout << minLength;
}
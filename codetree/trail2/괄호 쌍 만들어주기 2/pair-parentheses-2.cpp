#include <iostream>
using namespace std;

string a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a;

    int cnt = 0;

    for(int i = 0; i < (int)a.size(); i++) {
        
        if(a[i] == '(') {
            if(a[i+1] == '(') {

                for(int j = i+2; j < (int)a.size(); j++) {
                    
                    if(a[j] == ')') {
                        if(a[j+1] == ')') {
                            cnt++;
                        }
                        else {
                            continue;
                        }
                    }
                    else {
                        continue;
                    }

                }

            }
            else {
                continue;
            }
        }
        else {
            continue;
        }
    }

    cout << cnt;


    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

int n;
int x[100];
int y[100];
int max_w = INT_MIN;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // 1, 5


    // 1, 1                    7, 1

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {

                if(x[i] == x[j] || x[i] == x[k] || x[j] == x[k]) {
                    if(y[i] == y[j] || y[i] == y[k] || y[j] == y[k]) {

                        if(abs(x[j] - x[i]) != 0) {
                            int x1 = abs(x[j] - x[i]);

                            int y1 = 0;

                            if(abs(y[j] - y[i]) != 0) {
                                y1 = abs(y[j] - y[i]);
                            }
                            else {
                                y1 = abs(y[k] - y[j]);
                            }

                            int max_width = x1 * y1;
                            max_w = max(max_w, max_width);

                        }else {
                            int x1 = abs(x[k] - x[j]);

                            int y1 = 0;

                            if(abs(y[j] - y[i]) != 0) {
                                y1 = abs(y[j] - y[i]);
                            }
                            else {
                                y1 = abs(y[k] - y[j]);
                            }
                            
                            int max_width = x1 * y1;
                            max_w = max(max_w, max_width);

                        }

                    }
                }
                
            }
        }
    }

    if(max_w == INT_MIN) {
        cout << 0;
        return 0;
    }
        
    cout << max_w;
    

    return 0;
}
#include <iostream>
#include <climits>
#define max_loc 101
using namespace std;

int n;
int max_photo_size = INT_MIN;
char arr[max_loc];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int loc;
        char c;

        cin >> loc >> c;

        arr[loc] = c;
    }

    for(int i = 0; i < max_loc; i++) {
        if(arr[i] == 0) continue;
        for(int j = i; j < max_loc; j++) {
            if(arr[j] == 0) continue;
            int numG = 0;
            int numH = 0;

            int max_len = 0;

            for(int k = i; k <= j; k++) {

                if(arr[k] == 'G') {
                    numG++;
                }
                else if(arr[k] == 'H'){
                    numH++;
                }

            }

            if(numG == 0 && numH > 0) { // H로만 이루어져 있음
                max_len = j-i;
                max_photo_size = max(max_photo_size, max_len);
            }   
            else if(numG > 0 && numH == 0) {
                max_len = j-i;
                max_photo_size = max(max_photo_size, max_len);
            } 
            else if (numG == numH) {
                max_len = j-i;
                max_photo_size = max(max_photo_size, max_len);
            }   
        }
    }

    cout << max_photo_size;

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

class Num{
    public:
        int num;
        int loc;

        Num(int num, int loc) {
            this->num = num;
            this->loc = loc;
        }

        Num(){}
};

bool cmp(Num a, Num b) {
    if(a.num == b.num) {
        return a.loc < b.loc;
    }
    return a.num < b.num;
}

int n;
Num nums[1000];
Num nums2[1000];

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> nums[i].num;
        nums[i].loc = i+1;
    }

    sort(nums, nums+n, cmp);

    for(int i = 0; i < n; i++) {
        nums2[i].num = nums[i].loc;
        nums2[i].loc = i+1;
    }

    sort(nums2, nums2+n, cmp);

    for(int i = 0; i < n; i++) {
        cout << nums2[i].loc << " ";
    }

    return 0;
}
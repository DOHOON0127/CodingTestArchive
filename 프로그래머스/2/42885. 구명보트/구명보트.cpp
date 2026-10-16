#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0; // 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값
    
    // O(N)에 해결해야 함
    
    sort(people.begin(), people.end());
        
    // 50 50 70 80
    // 최대 2명씩만 탈 수 있음
    // 30 30 70 70 <- 이러면 순서대로 하면 3개인데, 최소는 2개임
    
    // 30 30 60 70 90
    
    int left = 0;
    int right = people.size()-1;
    
    while(right >= left) {

        if(people[right] + people[left] <= limit) {
            left++;
            right--;
            answer++;
        }else {
            right--;
            answer++;
        }
        
    }
    
    return answer;
}
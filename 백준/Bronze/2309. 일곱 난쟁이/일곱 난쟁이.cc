#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
 
int main(){
    vector <int> h;
    int sum=0;
    
    // 입력
    for(int i=0;i<9;i++){
        int ht;
        cin>>ht;
        sum+=ht;
        h.push_back(ht);
    }
    
    // 탐색
    for(int i=0; i<h.size()-1; i++){ // i는 끝까지 갈 필요 없음
        for(int j=i+1; j<h.size(); j++){
            int mus = h[i] + h[j];
            
            if(sum - mus == 100){
                
                h.erase(h.begin() + j); 
                h.erase(h.begin() + i);
                
                // 정렬 및 출력
                sort(h.begin(), h.end());
                for(int k=0; k<h.size(); k++){
                    cout << h[k] << "\n";
                }
                
                return 0; 
            }
        }       
    }
    return 0;
}
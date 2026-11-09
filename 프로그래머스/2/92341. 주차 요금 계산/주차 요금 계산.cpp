#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 5000 + ⌈(334 - 180) / 10⌉ x 600 = 14600

vector<int> solution(vector<int> fees, vector<string> records) {
    // 주차 요금과 입-출차 내역
    vector<int> answer;
    
    // vecotr<int> v_time;
    vector<string> v_carName;
    // vector<string> v_inOut;
    
    map<string, int> m;
    map<string, int> m_res; // 누적 시간 합
    
    for(int i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        
        string time, carName, inOut;
        
        ss >> time >> carName >> inOut;
        
        int mintues = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));
        
        // v_time.push_back(mintues);
        v_carName.push_back(carName);
        // v_inOut.push_back(inOut);
        
        
        if(m.find(carName) == m.end()) {
            m[carName] = mintues;
        }else{
            m_res[carName] += mintues - m[carName];
            m.erase(carName);
        }   
    }
    
    for(int i = 0; i < v_carName.size(); i++) {
        if(m.find(v_carName[i]) != m.end()) {
            m_res[v_carName[i]] += (23*60+59) - m[v_carName[i]];
            m.erase(v_carName[i]);
        }
    }
    
    map<string, int>::iterator it;
    
    for(it = m_res.begin(); it != m_res.end(); it++) {
        
        if((it->second) > fees[0]) {
            answer.push_back(fees[1] + ceil((((it->second) - fees[0]) / (double)fees[2])) * fees[3]);
        }
        else {
            answer.push_back(fees[1]);
        }
    }    
    
    return answer;
}
#include <iostream>
using namespace std;

class Fweather{
    public:
        string date;
        string day;
        string weather;

        Fweather(string date, string day, string weather) {
            this->date = date;
            this->day = day;
            this->weather = weather;
        }

        Fweather(){}
};

// C++의 문자열 비교는 
// 앞에서부터 한 글자씩 아스키코드 값을 비교하는 
// 사전순 방식을 따릅니다.

int main() {
    int n;

    cin >> n;

    string date, day, weather;

    Fweather weathers[101];

    string closeDate = "2101-00-00";

    for(int i = 0; i < n; i++) {
        cin >> date >> day >> weather;
        weathers[i] = Fweather(date, day, weather);

        if(weather == "Rain") {
            if(closeDate > date) {
                closeDate = date;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(weathers[i].weather == "Rain") {
            if(weathers[i].date == closeDate) {
                cout << weathers[i].date << " " << weathers[i].day << " " << weathers[i].weather;
            }
        }  
    }

    return 0;
}
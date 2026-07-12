#include <iostream>
#include <string>

using namespace std;

string secret_code;
char meeting_point;
int Itime;

class Agent {
public: 
    string secret_code;
    char meeting_point;
    int time;

    Agent(string secret_code, char meeting_point, int time) {
        this->secret_code = secret_code;
        this->meeting_point = meeting_point;
        this->time = time;
    }
};

int main() {
    cin >> secret_code >> meeting_point >> Itime;

    Agent agent1 = Agent(secret_code, meeting_point, Itime);

    cout << "secret code : " << agent1.secret_code << '\n';
    cout << "meeting point : " << agent1.meeting_point<< '\n';
    cout << "time : " << agent1.time<< '\n';

    return 0;
}
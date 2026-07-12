#include <iostream>
using namespace std;

class Spy{
    public: 
        char codeName;
        int score;

        Spy(char codeName = 'a', int score = 0) {
            this->codeName = codeName;
            this->score = score;
        }

};

int main() {
    char codeName;
    int score;

    int min_score = 101;

    Spy spys[5]; 

    for(int i = 0; i < 5; i++) {
        cin >> codeName >> score;
        spys[i] = Spy(codeName, score);

        if(score < min_score) {
            min_score = score;
        }
    }

    for(int i = 0; i < 5; i++) {
        if(spys[i].score == min_score) {
            cout << spys[i].codeName << ' ' << spys[i].score;
        }
    }

    


    return 0;
}
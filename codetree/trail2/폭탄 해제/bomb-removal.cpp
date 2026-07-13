#include <iostream>
using namespace std;

class Bomb{
    public:
        string codes;
        char lineColors;
        int times;

        Bomb(string code, char lineColor, int time) {
            this->codes = code;
            this->lineColors = lineColor;
            this->times = time;
        }
};

int main() {

    string code;
    char lineColor;
    int time;

    cin >> code >> lineColor >> time;

    Bomb bombs = Bomb(code, lineColor, time);

    cout << "code : " << bombs.codes << '\n';
    cout << "color : " << bombs.lineColors << '\n';
    cout << "second : " << bombs.times;




    return 0;
}
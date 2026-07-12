#include <iostream>
#include <string>
using namespace std;

class Game{
    public: 
        string id;
        int level;

        Game(string id, int level) {
            this->id = id;
            this->level = level;
        }
};

int main() {
    string name;
    int iLevel;

    cin >> name >> iLevel;

    Game game1 = Game("codetree", 10);

    Game game2 = Game(name, iLevel);


    cout << "user " << game1.id << " lv " << game1.level << '\n';

    cout << "user " << game2.id << " lv " << game2.level;

    return 0;
}
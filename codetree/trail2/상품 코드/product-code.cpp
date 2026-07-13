#include <iostream>
using namespace std;

class Product{
    public:
        string pName;
        int pCode;

        Product(string pName, int pCode) {
            this->pName = pName;
            this->pCode = pCode;
        }

        Product(){}
};

int main() {

    string pName;
    int pCode;

    Product p[2];

    cin >> pName >> pCode;

    p[0] = Product("codetree", 50);
    p[1] = Product(pName, pCode);

    for(int i = 0; i < 2; i++) {
        cout << "product " << p[i].pCode << " is " << p[i].pName << '\n'; 
    }


    return 0;
}
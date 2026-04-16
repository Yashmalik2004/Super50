#include <iostream>
using namespace std;

class ATM {
private:
    double balance;
    string name;

public:
    // Constructor
    ATM(int amount, string name) {
        (*this).balance = amount;
        this->name = name;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void getData() {
        cout << "Balance of "<<name<<" is: " << balance << endl;
    }
};

int main() {

    ATM a = ATM(100000,"yash"); 
    ATM b= ATM(a); // shallow copy 
    
    b.deposit(1111);
    b.getData();

    return 0;
}
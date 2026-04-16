// // issue with private constructors is that it cannot be initialised.


// #include<bits/stdc++.h>
// using namespace std;

// // class Animal{
// //   protected:
// //   int a=90;
// //   void makeSound(){
// //     cout<<"Bla bla bla"<<endl;
// //   }
// // };

// // class Dog:private Animal{
// //   public:
// //   void makeSound(){
// //     cout<<"Woof woof"<<endl;
// //     cout<<a;
// //   }
// // };

// // int main(){
// //   Dog d = Dog();
// //   d.makeSound();
// //   return 0;
// // }

// class BankAccount{
//     private: 
//       string name;
//       double amount;
//       string id;
//       static int count;
//     public:
//       BankAccount(string name, double amount, string id)
//       {
//         this->name = name;
//         this->amount = amount;
//         this->id = id;
//         count++;
//       }
//       public:
//         static int getTotalBankAccounts()
//         {
//           return count;
//         }
    
// };

// int BankAccount::count = 0;

// class zeroBankBalanceAcc: public BankAccount{
//   public:
//   static int getTotalBankAccounts()
//   {
//     return BankAccount::getTotalBankAccounts();
//   }

// };

// int main(){
//   BankAccount b1= BankAccount("yash",100000,"06");
//   BankAccount b2= BankAccount("sneha",100,"10");
//   BankAccount b3= BankAccount("susie",10,"1");
//   cout<<BankAccount::getTotalBankAccounts()<<endl;


//   return 0;
// }

#include<bits/stdc++.h>
using namespace std;

class Box{
  private:
    int width = 10;
    friend class Inspector;
};

class Inspector{
  public:
    void check(Box b){
      cout<<"The width of the box is: "<<b.width<<endl;
    }
};
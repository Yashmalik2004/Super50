#include<bits/stdc++.h>
using namespace std;

class Animal{
  protected:
  string name;

  public:
  Animal(string n) {
    name = n;
  }
};

class dog: public Animal{
  private:
  string breed;

  public:
  dog(string n, string b):Animal(n) {
    breed = b;
  }
  void getdata(){
    cout << "Name: " << name << endl;
    cout << "Breed: " << breed << endl;
  }
};

int main(){
  dog d("cashu","pug");
  d.getdata();

  Animal a; //upcasting
  a = new dog("kuku","cat");
}
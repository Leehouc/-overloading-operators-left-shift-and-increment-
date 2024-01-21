//ostream& operator<<(ostream& out, ppp p)
//ppp operator++(int)

#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iomanip>

using namespace std;


class ppp {
    friend ostream& operator<<(ostream& cout,ppp p);
public:
    int a;
    int b;
    ppp() {
        a = 0;
        b = 0;
    }
    ppp(int a, int b) {
        this->a = a;
        this->b = b;
    }

    ppp& operator++();

    ppp operator++(int);

};

ppp& ppp::operator++() {
        this->a++;
        this->b++;
        return *this;
    }

ppp ppp::operator++(int) {
   ppp* temp = new ppp();
   *temp = *this;
   this->a++;//记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
   this->b++;
   return *temp;
} 

ostream& operator<<(ostream& out,ppp p){
    out << p.a<<" " << p.b;
    return out;
}

void testwork(){
    ppp p1(1, 10);
    cout << p1++ << endl;
    cout << p1 << endl;
    ppp p2(1, 10);
    cout << ++p2 << endl;
    cout << p2 << endl;
}

int main(){
    testwork();
    return EXIT_SUCCESS;
}
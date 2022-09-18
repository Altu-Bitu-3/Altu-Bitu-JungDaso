//
// Created by dasoya on 17.09.22.
//
#include "iostream"

using namespace  std;

int getEndNumber(int n){


    int num = 665;
    int index = 0;

    string s;

    while(index != n){

        s = to_string(++num);
        if(s.find("666") !=string::npos){
            index++;
        }

    }

    return num;


}

int main(){

    int n ;

    cin >> n;

    cout << getEndNumber(n);


    return 0;
}
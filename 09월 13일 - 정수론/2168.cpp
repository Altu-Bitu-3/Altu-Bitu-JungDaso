#include "iostream"

using namespace std;

long long gcd(int x, int y){

    if(y==0){
        return x;
    }

    return gcd(y,x%y);
}


int main(){

    int x, y;

    cin >> x >> y;

    long long output = x + y - gcd(x,y);

    cout << output;
}
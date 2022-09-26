#include "iostream"
#include "map"
using namespace std;


int checkGroupWord(string input){

    map<char,bool> check;


    check[input[0]] = true;

    for (int i = 1; i < input.length(); ++i) {


       if(input[i]==input[i-1])// 이전 문자 같을 때
           continue;

       if(check[input[i]]) // 나온적 있는 문자가 또 나왔다면
       {
           return 0;
       }

       check[input[i]] = true;

    }

    return  1;
}

int main(){

    int n, ans=0;

    cin >> n;
    string input;


    while(n--){
        cin >> input;
        ans += checkGroupWord(input);
    }

    cout << ans;
}


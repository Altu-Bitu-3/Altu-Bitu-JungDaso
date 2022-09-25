#include "iostream"
#include "map"
using namespace std;


int checkGroupWord(string input){

    map<char,bool> check;

    for (int i = 0; i < input.length(); ++i) {

        if(i==0){
            check[input[i]] = true;
        }
        else if(input[i]!=input[i-1]){ // 이전 문자 같지 않을때
            if(!check[input[i]]){ // 나온적 없는 문자
                check[input[i]] = true;
            }else{ // 이미 나온적 있는 문자라면
                return 0;
            }
        }

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


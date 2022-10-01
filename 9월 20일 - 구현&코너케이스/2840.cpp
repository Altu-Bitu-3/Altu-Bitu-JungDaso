#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> wheel;
int cursor = 0;

int rotate(int s, char input){

    cursor += s;
    cursor %= wheel.size();

    if(wheel[cursor] == '?'){
        //중복 되는 알파벳이 없는 경우
        if(find(wheel.begin(),wheel.end(),input)== wheel.end()){
            wheel[cursor] = input;

            return 0;
        }
        else{
            return 1;
        }
       
    }else{  // 바퀴가 비어있지 않은 경우
        
        if(input==wheel[cursor]){
            return 0;
        }
        else{
            // 같지 않은 경우
            return 1;
        }
        
    }

    return 0;


}

int main(){

    int n,k;
    cin >> n >> k;

    wheel.assign(n,'?');

    while(k--){

        int s;
        char input;

        cin >> s >> input;
        
        if(rotate(s, input)){
            // -1이 반환된 경우
            cout << "!";
            return 0;
        }
        
        
    }


        int i = cursor;
        do{
            cout << wheel[i];
            i = (i -1+n)%n;

        }
        while(i != cursor);


    
    
    
    

}
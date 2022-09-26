#include "iostream"
#include "vector"
#include "algorithm"
#include "stack"
#include "queue"
using namespace std;

string getOutput(string arr){
    vector<char> sortedArr;
    stack<char> s;

    if(arr.length()%2==0){ //길이가 짝수이면

        for(int i=0; i< arr.length();i+=2){
            if(arr[i]==arr[i+1]){
                sortedArr.push_back(arr[i]);
                s.push(arr[i+1]);
            }
            else{

                return "I'm Sorry Hansoo";

            }
        }

        //스택에 쌓아둔 문자들을 문자열에 차례로 쌓음
        while(!s.empty()){
            sortedArr.push_back(s.top());
            s.pop();
        }
        string answer(sortedArr.begin(),sortedArr.end());

        return answer;
    }
    else{ // 길이가 홀수면

        char temp = '\n';
        for(int i=0; i< arr.length();i+=2){
            if(arr[i]==arr[i+1]){
                sortedArr.push_back(arr[i]);
                s.push(arr[i+1]);

            }
            else if(temp == '\n'){
                temp = arr[i];
                // 중복이 안되는 문자는 가운데 단 하나만 올 수 있다.

            }
            else{

                return "I'm Sorry Hansoo";

            }
        }

        sortedArr.push_back(temp);
        while(!s.empty()){
            sortedArr.push_back(s.top());
            s.pop();
        }
        string answer(sortedArr.begin(),sortedArr.end());

        return answer;

    }



}



int main(){

    string name;

    cin >> name;
    sort(name.begin(),name.end());

    cout << getOutput(name);

}
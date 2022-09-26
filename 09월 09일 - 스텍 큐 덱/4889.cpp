
#include "iostream"
#include "stack"
#include "vector"

using namespace std;

int getOutput(string& s){

    stack<char> st;
    int sum = 0; // 최소 연산 수


    for (int i = 0; i < s.length(); ++i) {

        if(s[i] == '{'){

            st.push('{');

        }

        if(s[i] == '}') {

            if(st.empty()){ // 불안정하게 만든 경우
                sum++;
                st.push('{');
            }
            else if (st.top() == '{') {
                st.pop();
            }

        }

    }


    sum += st.size()/2; // 스택에 남은 수열은 { 밖에 없으므로 이를 안정적 배열로 만들기 위한 최소의 연산은 스택 사이즈/2이다.

    return sum;

}


int main(){

    string s;
    int i = 1;

    while(getline(cin,s)){

        if(s[0] == '-'){ // -가 있는 경우에만 종료

            break; // 마지막 문장 받으면 종료
        }

        cout << i++ <<". " << getOutput(s) <<'\n';

    }

}
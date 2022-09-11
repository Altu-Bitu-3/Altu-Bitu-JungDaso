#include "iostream"
#include "stack"

using namespace std;


bool isBalanced(string &s){
    stack<char> st;
    for(int i = 0; i< s.length();i++){
        switch (s[i]) {
            case '(':
            case '[':
                st.push(s[i]);
                break;
            case ')' :

                if(st.empty() || st.top() != '('){
                    return false;
                }

                st.pop();
                break;
            case ']' :
                if(st.empty() || st.top() != '['){
                    return false;
                }
                st.pop();
                break;
        }
    }

    return  st.empty();
}
int main(){

    string s;

    while(getline(cin,s)){

        if(s == "."){
            break;
        }
        if(isBalanced(s)){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }


}
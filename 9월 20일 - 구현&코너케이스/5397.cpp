#include "iostream"
#include "vector"
#include "stack"
#include "algorithm"

using namespace std;

string getPassword(string input){

    stack<char> st, temp;
    string ans;
    int L = input.length();

    for (int i = 0; i < L; ++i) {

        if(input[i] == '<'){

            if(!st.empty()){

                temp.push(st.top());
                st.pop();
            }

            continue;
        }

        if(input[i] == '>'){

            if(!temp.empty()){

                st.push(temp.top());
                temp.pop();
            }

            continue;
        }

        if(input[i] == '-'){

            if(!st.empty())//안 비어있으면
                st.pop();

            continue;
        }

        st.push(input[i]);

    }



    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    string input;


    while(n--){
        cin >> input;
        cout << getPassword(input) << '\n';
    }

    return  0;


}

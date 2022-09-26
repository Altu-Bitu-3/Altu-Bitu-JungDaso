#include "iostream"
#include "vector"

using namespace std;
const int SIZE = 1e4;

vector<int> stack_vec(SIZE);
int top_pointer = -1;


void push(int x){
    stack_vec[++top_pointer] = x;
}

void pop(){
    top_pointer--;
}

int size(){
    return top_pointer + 1;
}

bool empty(){
    return top_pointer == -1;
}

int top(){
    return stack_vec[top_pointer];
}
bool full(){
    return  top_pointer == SIZE -1 ;
}
int main(){
    int n, x;
    string cmd;

    cin>>n;
    while(n--){
        cin >> cmd;

        if(cmd == "push"){
            cin >> x;
            if(!full()){
                push(x);
            }
            continue;
        }
        if(cmd == "pop"){
            if(empty()) {
            cout << "-1\n";

            } else{
                cout << top() << "\n";
                pop();
            }

            continue;
        }
        if(cmd == "size"){
            cout << size() << "\n";
            continue;
        }
        if(cmd=="empty"){
            cout << empty() << "\n";
            continue;
        }
        if(cmd == "top"){
            if(empty()){
                cout << "-1\n";
            }
            else{
                cout << top() << '\n';
            }
        }


    }
}
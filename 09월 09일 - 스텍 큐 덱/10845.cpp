#include "iostream"
#include "vector"
#include "queue"

using namespace std;


int front = 0,rear= 0;
const int SIZE = 1e4+1;
vector<int> queue_vec(SIZE);

bool full(){
    return (rear+1)%SIZE == front;
}

int push(int x){
    rear = (rear+1)%SIZE;

    queue_vec[rear] = x;
}

void pop(){
    front = (front+1)%SIZE;
}

int size(){

    int tmp =rear - front;
    if(tmp<0){
        tmp +=SIZE;
    }
    return tmp;
}

bool empty(){
    return  front == rear;

}

int frontOut() {
    return queue_vec[(front + 1) % SIZE];
}
int back(){
    return queue_vec[rear];
}

int main(){

    int n,x;
    string cmd;
    queue<int> q;

    cin >> n;
    while(n--){
        cin >> cmd;

        if(cmd=="push"){
            cin >> x;

            q.push(x);

            continue;
        }

        if(cmd=="pop"){
            if(q.empty()){
                cout << "-1\n";
            }else{
                cout << q.front()<< "\n";
                q.pop();
            }
            continue;
        }

        if(cmd=="size"){
            cout << q.size() <<'\n';
            continue;
        }

        if(cmd=="empty"){
            cout << q.empty() << '\n';
            continue;
        }

        if(cmd=="front"){
            if(q.empty()){
                cout << "-1\n";
            }else{
                cout << q.front() << "\n";

            }
            continue;
        }

        if(cmd=="back"){
            if(q.empty()){
                cout << "-1\n";
            }else{
                cout << q.back() << "\n";

            }
            continue;
        }
    }
    return  0;
}
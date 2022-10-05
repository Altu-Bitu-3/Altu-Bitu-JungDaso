#include "iostream"
#include "queue"

using namespace std;

struct cmp{
    bool operator()(const int &x1,const int &x2){

        if(abs(x2) != abs(x1)){
            return abs(x2) < abs(x1);
        }

        return  x2 < x1;
    }
};
int main(){
    int n,x;

    cin >>n;

    priority_queue<int, vector<int>, cmp> pq;
    while(n--){
        cin >> x;
        if(x==0){
            if(pq.empty()){
                cout << "0\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }

    }
}
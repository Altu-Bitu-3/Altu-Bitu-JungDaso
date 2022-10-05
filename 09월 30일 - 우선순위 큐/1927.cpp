#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(const int &x1,const int &x2){

        return  x2 < x1;
    }
};


int main(){


    cin.tie(NULL);

    int n;

    cin >> n;

    priority_queue<int,vector<int>,cmp> min_heap;

    int x;

    while(n--){

        cin >> x;

        if(x==0){

            if(min_heap.empty()) {
                cout << "0\n";
                continue;
            }

            cout << min_heap.top() << "\n";
            min_heap.pop();

            continue;
        }

        min_heap.push(x);

    }
}
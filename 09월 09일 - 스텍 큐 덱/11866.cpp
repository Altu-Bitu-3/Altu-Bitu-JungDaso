//
// Created by dasoya on 2022/09/12.
//
#include "iostream"
#include "queue"

using namespace std;

void getOutput(queue<int>& q, int k) {
    cout << '<';

    //k-1번 넘기고 팝

    while(q.size() != 1){

        int i = k-1;

        while(i--) { // k-1 번 동안 큐의 프론트를 맨 뒤로 보냄
            q.push(q.front());
            q.pop();
        }

        cout << q.front() << ", ";
        q.pop();

    }

    cout << q.front() << '>'; //마지막으로 남은 원소 출력
}

int main(){

    int n, k;

    cin >> n >> k;

    queue<int> q;

    //초기화
    for (int i = 1; i <= n; ++i) {

        q.push(i);
    }

    getOutput(q , k);



}
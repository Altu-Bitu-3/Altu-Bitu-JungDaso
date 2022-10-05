#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int func(priority_queue<int> box, vector<int> child){

    int m = child.size();

    for(int i = 0; i< m ; i++){

        if(box.top()<child[i]) // 불가능한 경우
            return 0;

        int temp = box.top() - child[i];

        box.pop();

        box.push(temp); // 남은 선물 상자 재활용

    }


    return 1;

}

int main(){

    int n,m;

    cin >> n >> m; // 상자 수 , 아이들의 수

    priority_queue<int> box; //가장 많은 선물이 든 선물 상자 부터 꺼낼 수 있음
    vector<int> child; // 순차적으로 아이들이 선물을 가져감

    //입력
    int input;

    while(n--){

        cin >> input;

        box.push(input);

    }

    while(m--){

        cin >> input;

        child.push_back(input);

    }

    //연산
    cout << func(box,child);

    return 0;
}
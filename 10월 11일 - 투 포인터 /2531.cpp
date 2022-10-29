#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//큐에 n이 들어있는 지 찾는 함수
bool queFind(queue<int> que,int n){

    while(!que.empty()){

       if(que.front()==n)
           return true;

       que.pop();
    }

    return  false;

}
int slicingWindow(vector<int> plates,int n,int d,int k,int c){

    queue<int> section;
    int section_ans = 0;


    //윈도우 초기화
    for (int i = 0; i < k; ++i) {

        if(!queFind(section,plates[i]))
            section_ans++;

        section.push(plates[i]);

    }

    int ans = section_ans;

    //이동
    for (int i = k;   ; ) {

        int temp = section.front();

        section.pop();
        //중복되는 접시가 없으면 종류가 감소됨.
        if(!queFind(section,temp))
            section_ans--;

        //슬라이싱 윈도우에 없는 접시가 들어오면 종류가 추가됨
        if(!queFind(section,plates[i]))
            section_ans++;

        section.push(plates[i]);


        //section 쿠폰이 있으면 0 을 더해줌.
        ans = max(ans,section_ans+!queFind(section,c));

        i = ++i%n; //인덱스가 회전해야 함

        if(i==k)
            break;

    }

    return ans;

}

int main(){

    int n,d,k,c;

    cin >> n >> d >>k >>c;
    vector<int> plates(n,0);

    for(int i=0;i<n;i++){
        cin >> plates[i];
    }

    cout << slicingWindow(plates,n,d,k,c);



}

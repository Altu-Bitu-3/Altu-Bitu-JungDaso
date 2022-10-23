#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

//가장 인접한 두 공유기 사이의 거리가 미드이도록 설치했을 때 설치된 공유기의 개수.
int cntRouter(int dist, vector<int> house){
    int cnt = 1;
    int cur = house[0];

    for (int i = 1; i < house.size() ; ++i) {
        if(house[i] - cur >= dist){
            cnt++;
            cur = house[i];
        }
    }

    return cnt;
}


//인접한 거리가 k이리 때 설치가능한 공유기의 최대 개수

int upperSearch(int left,int right,int target,vector<int> house){

    while(left<= right){
        //가장 인접한 두 공유기 사이의 거리가 mid일 때, 공유기 씨개를 설치할 수 있는가?
        int mid = (left+right) /2;
        int installed = cntRouter(mid,house); //처음엔 배열을 저장한다 생각했는데 mid 인덱스의 공유기 개수를 바로 구함.

        if(installed >= target){
            left = mid +1;
        }else{
            right = mid -1;
        }
    }

    return left-1;
}


int main(){
    //가능한 답을 구하고 이분탐색으롬 (최대&최소) 인덱스 반환
    int n,c;

    cin >> n >> c;

    vector<int> house(n,0);

    for (int i = 0; i < n; ++i) {

        cin >> house[i];

    }

    sort(house.begin(),house.end());

    //공유기의 거리가 인덱스이므로
    //left : 1
    //right : house[n-1] - house[0] 8
    cout << upperSearch(1,house[n-1]-house[0],c,house);
}



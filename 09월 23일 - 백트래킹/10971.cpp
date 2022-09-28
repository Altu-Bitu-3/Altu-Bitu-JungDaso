#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> W;
vector<bool> check;
vector<int> sum_arr; //경로의 비용을 모아둔 배열
vector<int> path; //현재 순환하고 있는 경로
int sum = 0;

//모든 경로의 비용을 구하고, 최솟값을 찾아서 출력.

void backtracking(int cnt){

    if(cnt==n&&W[path[n-1]][path[0]]!=0){

        for (int i = 1; i < n; ++i) {
            if(W[path[i- 1]][path[i]] == 0)
                return;

            sum += W[path[i- 1]][path[i]];
        }
        sum += W[path[n-1]][path[0]];

        sum_arr.push_back(sum);

        sum =0;

        return;
    }

    for(int i = 0; i<n;i++){

        if(W[path[cnt-1]][i] == 0){ // 길이 없을 때 건너뜀.
             continue;
        }


        if(!check[i]){

            path[cnt] = i;

            check[i] = true;
            backtracking(cnt+1);
            check[i] = false;
        }

    }
}

int main(){

    //입력
    cin >> n;

    W.resize(n, vector<int>(n,0));
    check.resize(n,false);
    path.resize(n,0);

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {
            cin >> W[i][j];
        }
    }


    //연산&출력
    backtracking(0);

    int ans =*min_element(sum_arr.begin(),sum_arr.end());
    cout << ans;
}

// 이차원 벡터 초기화 방법 참고 : https://www.techiedelight.com/ko/initialize-two-dimensional-vector-cpp/
#include <iostream>
#include <vector>

using namespace std;

int lis(int n,vector<int> &score){

    vector<int> dp(n,1);
    int dp_max= 1; // 마지막 score가 최대가 된다는 보장 x, 최댓값을 저장해 둠.


    for (int i = 0; i < n; ++i) {
        int max = 0;

        for (int j = 0; j < i; ++j) { // 자신의 이전 배열을 탐색
            if(score[j]>=score[i]) // 증가하는 수열이 만들어지지 않는다면
                continue;

            if(max<dp[j])
                max = dp[j];
        }

        dp[i] = max+1;

        if(dp_max<dp[i]){
            dp_max = dp[i];
        }

    }

    return dp_max;
}

int main(){

    int n;

    cin >> n;

    vector<int> score(n,0);

    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }

    cout << lis(n,score);

    return 0;
}
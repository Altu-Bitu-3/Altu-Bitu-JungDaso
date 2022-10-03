#include <iostream>
#include <vector>

using namespace std;

int maxScore(int n, vector<int> &score){

    vector<int> dp(n+1,0);

    if(n==1){
        return score[1];
    }
    if(n==2){
        return score[1]+score[2];
    }

    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    for (int i = 3; i <= n; ++i) {

        dp[i] = max(dp[i-2],dp[i-3]+score[i-1]) + score[i];

    }

    return dp[n];
}

int main(){

    int n;

    cin >> n;
    vector<int> score(n+1,0);

    for (int i = 1; i <= n; ++i) {
        cin >> score[i];
    }

    cout << maxScore(n,score);
    return 0;

}
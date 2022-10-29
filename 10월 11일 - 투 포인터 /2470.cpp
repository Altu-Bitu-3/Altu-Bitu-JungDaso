#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> ci;
const int INF = 2e10+1;

ci findLiquid(int left, int right,vector<int> &liquid){

    ci ans = {0,0};
    int min_diff = INF;

    //left와 right는 같으면 안됨. 따라서 포인터가 같아지면 그대로 end 답은 갱신 안됨.
    while(left<right){
        int mix=liquid[left]+liquid[right];
        if(mix==0){
            return {liquid[left],liquid[right]};
        }

        if(abs(mix)<min_diff){
            min_diff = abs(mix);
            ans = {liquid[left],liquid[right]};

        }

        if(mix >0){
            right--;
        }
        else{
            left++;
        }
    }

    return ans;
}

int main(){

    int n;

    cin >> n;
    vector<int> liquid(n,0);

    for (int i = 0; i < n; ++i) {
        cin >> liquid[i];
    }

    sort(liquid.begin(),liquid.end());
    ci ans = findLiquid(0,n-1,liquid);

    cout << ans.first <<' ' <<ans.second;

    return 0;
}
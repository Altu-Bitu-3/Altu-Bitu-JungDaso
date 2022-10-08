#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"
using namespace std;

typedef pair<int,int> ci;

bool cmp(ci &a,ci&b){

    if(a.second!=b.second)
        return a.second < b.second;

    return a.first < b.first;
}

int main(){

    int n;

    cin >> n;

    vector<pair<int,int>> arr(n,{0,0});

    for (int i = 0; i < n; ++i) {

        cin >> arr[i].first >> arr[i].second;


    }

    sort(arr.begin(),arr.end(),cmp);


    int ans = 1;
    int max = arr[0].second;

    for (int i = 1; i < n; ++i) {

        if(arr[i].first < max)
            continue;

        max = arr[i].second;
        ans++;
    }


    cout << ans;
    return 0;
}
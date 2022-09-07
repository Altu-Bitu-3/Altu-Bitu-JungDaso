//
// Created by dasoya on 2022/09/04.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct dot {
    int x, y;
};

bool cmp(const dot& a,const dot& b){

    if(a.y != b.y){
        return a.y < b.y;
    }

    if(a.x != b.x){
        return a.x <b.x;
    }
}

int main() {

    int n;
    cin >> n;

    vector<dot> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr.begin(),arr.end(),cmp);

    for(int i=0; i<n;i++){
        cout << arr[i].x << " "<< arr[i].y << "\n";
    }
}
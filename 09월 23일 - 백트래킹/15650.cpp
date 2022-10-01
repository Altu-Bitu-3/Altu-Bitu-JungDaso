//
// Created by dasoya on 24.09.22.
//
#include "iostream"
#include "vector"

using namespace std;
const int SIZE = 8;

int n,m;
vector<int> num(SIZE);


void backtracking(int cnt, int start){

    if(cnt==m){
        for (int i = 0; i <cnt ; ++i) {
            cout << num[i] << ' ';

        }
        cout << "\n";
        return;
    }

    for(int i=start; i<=n; i++){
            num[cnt] = i;
            backtracking(cnt+1,i+1);

    }
}

int main(){

    cin >> n >>m;

    backtracking(0,1);
}
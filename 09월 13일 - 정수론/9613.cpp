//
// Created by dasoya on 2022/09/13.
//
#include "iostream"
#include "vector"

using namespace std;

int gcd(int a,int b){

    if(b==0){
        return a;
    }

    return gcd(b, a%b);

}

long long getSum(int n, vector<int>& v){
    long long sum = 0;

    for(int i =0; i < n; i++){
        for(int j = i+1; j <n; j++){

            sum += gcd(min(v[i],v[j]),max(v[i],v[j]));
        }
    }

    return sum;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n ;
        cin >> n;

        vector<int> arr(n,0);
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }

        cout << getSum(n, arr) << "\n";
    }
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 오버 플로우에 주의해서 변수 선언.
unsigned long long cntCustomer(unsigned long long t,vector<long long> time){

    unsigned long long num = 0; //주어진 시간 t 안에서 처리할 수 있는 최대 고객수

    for (int i = 0; i < time.size(); ++i) {
        num += t/time[i];
    }

    return num;
}
unsigned long long binarySearch(unsigned long long left, unsigned long long right, int target,vector<long long> time){

    while(left<=right){

        unsigned long long mid = (left+right)/2;
        unsigned long long customer = cntCustomer(mid,time);


        if(customer>=target){

            right = mid-1;
        }
        else{
            left = mid +1;
        }

    }

    return left;

}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;

    cin >> n >> m;

    vector<long long> time(n,0);

    for (int i = 0; i < n; ++i) {

        cin >> time[i] ;
    }

    sort(time.begin(),time.end());

    //인덱스는 정해진 시간
    //최솟값은 time[0]
    //최댓값은 한줄에 m명이 다 서는 경우
    cout << binarySearch(time[0],time[0]*m,m,time);

}

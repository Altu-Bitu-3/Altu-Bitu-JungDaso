//
// Created by dasoya on 2022/09/07.
//
#include "iostream"
#include "map"

using namespace std;

int main() {

    int n;
    string input;
    map<string, int> in_car, out_car;
    map<int,string> in_car_n,out_car_n;
    int sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        in_car[input] = i;
        in_car_n[i] = input;
    }
    for (int i = 0; i < n; i++) { // 나보다 순위가 높았던 얘보다 무조건 앞에 있어야 함.
        cin >> input; //in에서 나보다 순위가 높은 애들 중에 하나라도 없으면 나는 추월한거임. 모두 있으면 추월 아님.

        out_car[input] = i;
        out_car_n[i] = input;

    }


    for (int i = 0; i < n; ++i) {//i는 나올 때의 내 숫자

        for (int j = 0; j < in_car[out_car_n[i]]+1; ++j) { // j는 나보다 먼저 들어간 차

            if(out_car[in_car_n[j]]>i){

               sum++;

               break;

            }

        }
    }

    cout << sum;

}
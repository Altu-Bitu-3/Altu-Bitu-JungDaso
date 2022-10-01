#include "iostream"
#include "vector"

using namespace std;
const int SIZE = 8;

int n,m; // 재귀 함수 사용 시 전역 변수로 선언.
vector<int> num(SIZE);
vector<bool> check(SIZE);

void backtracking(int cnt){

    if(cnt == m){
        for(int i =0; i<cnt ;i++){
            cout << num[i] << ' ';
        }
        cout << "\n";

        return ;
    }

    for(int i = 1; i<=n; i++) {//i가 고르려는 수


       if(!check[i]) {
           num[cnt] = i;
           check[i] = true;
           backtracking(cnt + 1);
           //다시 돌아 왔을 때
           check[i] = false;
       }


    }

}

int main(){

    cin >> n >> m;

    backtracking(0);



}
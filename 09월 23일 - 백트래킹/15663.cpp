#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 8;


int n, m;

vector<int> numbers(SIZE);//입력 되는 숫자 배열
vector<int> arr(SIZE); //출력 하는 배열
vector<bool> check(SIZE); // 중복 체크

void backtracking(int cnt){

    if(cnt == m){

            for (int i = 0; i < m; ++i) {
                cout << arr[i] << ' ';
            }

            cout << "\n";

        return ;
    }

    int last_num = 0;
    for(int i = 0; i < n; i++ )
    {
        if(numbers[i]==last_num) // 같은 숫자의 백트래킹을 막아준다.
            continue;

        if(!check[i]) { // 자기 자신이 중복해서 배열로 들어가는 것을 막아줌.
            arr[cnt] = numbers[i];
            check[i] = true;
            last_num = numbers[i];

            backtracking(cnt + 1);
            check[i] = false; // 초기화

      }
    }

}

int main(){

    cin >> n >> m; // 입력


    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];

    }

    sort(numbers.begin(), numbers.begin()+n);

    backtracking(0);

    return 0;
}

//https://cplusplus.com/reference/algorithm/sort/ sort 함수 사용법 참고.
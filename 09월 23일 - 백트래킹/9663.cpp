#include "iostream"
#include "vector"

using namespace std;
const int SIZE = 15;

int n,ans;
vector<bool> check_col(SIZE),check_left(SIZE*2),check_right(SIZE*2);

void backtracking(int row){

    if(row==n){
            ans++;
            return;
    }

    for (int i = 0; i < n; ++i) {
        if(!check_col[i]&&!check_left[row-i+n]&&!check_right[row+i]){
            check_right[row+i]=true;
            check_col[i] = true;
            check_left[row-i+n] = true;

            backtracking(row+1);

            check_right[row+i] = false;
            check_col[i] = false;
            check_left[row-i+n] =false;
        }

    }
}

int main(){


    cin >> n;

    backtracking(0);

    cout << ans;

}
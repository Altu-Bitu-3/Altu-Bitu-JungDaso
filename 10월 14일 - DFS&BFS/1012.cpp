#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef pair<int,int> ci;

int dfs(int m, int n , stack<ci> stk, vector<vector<bool>> matrix){


    int dr[] = {1,-1,0,0};
    int dc[] = {0,0,1,-1};
    int ans = 0; // 최소 배추 흰 지렁이 마리수

    while(!stk.empty()){

        auto [r,c] = stk.top();
        stk.pop();

        if(matrix[r][c]){
            ans++;
            matrix[r][c] = false;
        }

        for (int i = 0; i < 4; ++i) {

            int new_r = r+dr[i];
            int new_c = c+dc[i];

            if(new_r >= 0 && new_r <n&& new_c>=0&&new_c <m&&
                matrix[new_r][new_c]){

                stk.push({new_r,new_c});
                matrix[new_r][new_c] = false;
            }


        }

    }

    return ans;

}

int main(){

    int t, n, m , k,a,b;

    cin >> t;

    while(t--){

        cin >> m >> n >> k;
        vector<vector<bool>> matrix(n,vector<bool>(m,false));
        stack<ci> stk;

        //cnt = k;

        while(k--){

            cin >> b >> a;

            matrix[a][b]= true;
            stk.push({a,b});
        }

        cout << dfs(m,n,stk,matrix) << "\n";
    }

    return 0;

}

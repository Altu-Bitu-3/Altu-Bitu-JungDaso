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

        //배추가 있는지 검사할 때 처음 방문 했다면 필요한 지렁이 수를 늘림
        if(matrix[r][c]){
            ans++;
            matrix[r][c] = false;
        }

        // 인접한 배추를 검사함
        for (int i = 0; i < 4; ++i) {

            int new_r = r+dr[i];
            int new_c = c+dc[i];

            if(new_r >= 0 && new_r <n&& new_c>=0&&new_c <m&&
                matrix[new_r][new_c]){

                stk.push({new_r,new_c});
                //이후 방문한 곳은 다시 방문 하지 않도록 저장.
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

        while(k--){

            cin >> b >> a;

            matrix[a][b]= true;
            stk.push({a,b}); //배추가 있는 곳을 미리 스택에 넣어둠
        }

        cout << dfs(m,n,stk,matrix) << "\n";
    }

    return 0;

}

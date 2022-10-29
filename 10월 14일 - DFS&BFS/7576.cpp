#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ci;
int bfs(int m,int n,int cnt, vector<vector<int>> &matrix,queue<ci> &que){

    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,+1};

    int t = 0;

    vector<vector<bool>> visited(n, vector<bool>(m,false));

    while(!que.empty())
    {
        auto[r,c] = que.front();
        que.pop();

        t= matrix[r][c];

        for (int i=0 ; i<4;i++) {
            int new_r = r+dr[i];
            int new_c = c+dc[i];

            if(new_r >= 0 && new_r < n && new_c >=0
                && new_c < m && matrix[new_r][new_c]==0){

                que.push({new_r,new_c});
                matrix[new_r][new_c] = t+1;
                cnt--;
            }
        }
    }

    return (cnt == 0 ? t-1 : -1);

}

int main(){

    int m,n,input;

    cin >> m >> n;


    //행렬 초기화할 때 가로 세로 주의. 세로 먼저 반복, 가로 이후 반복임. 열의 개수 먼저 초기화, 이후 행의 개수 초기화
    vector<vector<int>> matrix(n,vector<int>(m,0));
    queue<ci> que;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            cin >> input;
            matrix[i][j]  = input;

            if(matrix[i][j]==1){
                que.push({i,j});
            } else if( matrix[i][j] == 0){
                cnt++;
            }
        }

    }

    cout << bfs(m,n,cnt,matrix,que);


    return 0;

}

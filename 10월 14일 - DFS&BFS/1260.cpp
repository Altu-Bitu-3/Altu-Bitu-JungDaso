#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<vector<bool>> adj_matrix;
vector<bool> visited_recur;
vector<int> order_recur;


//재귀함수로 dfs 전달
void dfsRecur(int n,int curr){
    if(visited_recur[curr]){
        return;
    }

    visited_recur[curr] = true;
    order_recur.push_back(curr);

    for(int next=1;next<=n;next++){
        if(adj_matrix[curr][next])
            dfsRecur(n,next);
    }
    return;
}

vector<int> bfs(int n,int v,vector<vector<bool>> &adj_matrix){
    vector<bool> visited(n+1,false);
    queue<int> que;
    vector<int> ans;

    que.push(v);
    visited[v] = true;


    while(!que.empty()){
        int curr = que.front();
        ans.push_back(curr);
        que.pop();

        //숫자가 작은 정점 부터
        for(int next=1;next<=n;next++){
            //간선이 없으면
            if(!adj_matrix[curr][next] || visited[next])
                continue;

            visited[next] = true; //큐에 넣을 때! 방문 체크
            que.push(next);


        }
    }

    return ans;

}




int main(){

    int n,m,v,a,b;
    cin >> n >>m >> v;

    adj_matrix.assign(n+1, vector<bool>(n+1,false));
    vector<bool> visited(n+1,false);
    visited_recur.assign(n+1, false);


    while(m--){
        cin >> a >> b;
        adj_matrix[a][b] = true;
        adj_matrix[b][a] = true;

    }

    dfsRecur(n,v);

    for(auto i :order_recur){
        cout << i<<' ';
    }

    cout<<"\n";

    auto ans = bfs(n,v,adj_matrix);
    for(auto i: ans){
        cout << i <<' ';
    }

    return 0;
}
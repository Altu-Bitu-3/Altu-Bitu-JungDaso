#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int dfs(int n,vector<vector<int>> &adj_list){
    int count = 0;
    stack<int> stk;
    vector<bool> visited(n+1,false);

    stk.push(1);
    visited[1] = true;

    while(!stk.empty()){

        int curr = stk.top();
        stk.pop();

        for(auto next :adj_list[curr]){
            if(visited[next]){
                continue;
            }

            visited[next] = true;
            stk.push(next);
            count++;
        }
    }

    return count;
}

int bfs(int n,vector<vector<int>> &adj_list){
    int count = 0;
    queue<int> que;
    vector<bool> visited(n+1,false);

    que.push(1);
    visited[1] = true;

    while(!que.empty()){

        int curr = que.front();
        que.pop();

        for(auto next :adj_list[curr]){
            if(visited[next]){
                continue;
            }

            visited[next] = true;
            que.push(next);
            count++;
        }
    }

    return count;
}
int main(){

    int n,m,a,b;

    cin >> n>>m;

    vector<vector<int>> adj_list(n+1,vector<int>());

    while(m--){
        cin >> a >>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    cout << bfs(n,adj_list);
    return 0;
}

//모든 노드 방문 하고자 할 때 두 방법 모두 상관 없음.

// 가중치가 주어지거나 특정 경로를 찾아야할 때는 DFS
// 두 노드 사이의 최단 거리를 찾을 때는 BFS(미로 찾기), 가장 가까운 노드 부터 방문




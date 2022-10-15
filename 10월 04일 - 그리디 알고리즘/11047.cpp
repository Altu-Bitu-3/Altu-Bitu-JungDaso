#include <iostream>
#include <vector>

using namespace std;

int func(int n, int k, vector<int> &coin){
    //이미 오름차순으로 정렬되어있음.
    int count = 0;
    int idx = n-1;

    while(k){

        count += k / coin[idx];
        k %= coin[idx];

        idx--;
    }

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;

    cin >> n >> k;

    vector<int> coin(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }

    cout << func(n,k,coin);

    return 0;
}
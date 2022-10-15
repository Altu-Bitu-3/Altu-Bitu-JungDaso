#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<int> p){

    int ans=0 ,r = 0;

    sort(p.begin(),p.end());

    for (int i = 0; i < p.size(); ++i) {

        ans += (r+p[i]);

        r += p[i];
    }


    return ans;
}
int main(){

    int n;

    cin >> n;

    vector<int> p(n,0);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    cout << calc(p);
}
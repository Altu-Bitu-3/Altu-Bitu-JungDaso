#include "iostream"
#include "vector"
#include "numeric"
#include "map"
#include "algorithm"
#include "cmath"
using namespace std;


int calMean(vector<int> v){

    double sum = accumulate(v.begin(),v.end(),0.0);

    return round(sum / v.size());

}

int calMid(vector<int> v){

    sort(v.begin(),v.end());

    return v[v.size()/2];
}

int calMost(vector<int> v){

    map<int,int> m;

    for(int i=0; i<v.size(); i++){
        m[v[i]]++;
    }

    int max = 0;
    vector<int> mostArr;

    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > max) {
           max = it->second;
           mostArr.clear();
           mostArr.push_back(it->first);
        }else if(it->second == max){
            mostArr.push_back(it->first);
        }
    }

    if(mostArr.size()==1){
        return mostArr[0];
    }
    else{ // 최빈값이 여러개 있을 때는

        sort(mostArr.begin(),mostArr.end());
        return mostArr[1];
    }


}

int calScope(vector<int> v){

    sort(v.begin(),v.end());

     return v[v.size()-1] - v[0];
}
int main(){

    int n;

    cin >> n;
    vector<int> v;

    int input;

    while(n--){
        cin >> input;
        v.push_back(input);
    }

    cout << calMean(v) << "\n";
    cout << calMid(v) << " \n";
    cout << calMost(v) << "\n";
    cout << calScope(v) << "\n";

}
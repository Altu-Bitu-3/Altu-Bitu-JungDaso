#include "iostream"
#include "map"
#include "algorithm"
#include "vector"

using namespace std;

bool cmp(const string& a, const string& b){

    return a > b;
}

int main(){

    int n;
    string name, input;
    map<string,int> m;
    vector<string> arr;

     cin >> n;
    while(n--){

        cin >> name >> input;

        if(input == "enter"){
            m[name] = 1;
        }
        else{
            m[name] = 0;
        }

    }

    for(auto& iter : m){

        if(iter.second == 1)
            arr.push_back(iter.first);

    }

    sort(arr.begin(),arr.end(),cmp);

    for(auto& iter : arr){
        cout << iter<< "\n";
    }
}
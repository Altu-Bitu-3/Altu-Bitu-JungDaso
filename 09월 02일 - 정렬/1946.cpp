#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> solved_arr;
    int a, b;

    for(int i=0; i<n;i++){

        int m ;
        cin >> m;

        vector<pair<int,int>> arr;

        for(int j=0; j<m;j++){
            cin >> a >> b;
            arr.push_back(pair<int,int>(a,b));
        };


        sort(arr.begin(),arr.end());

        int passed = 0;
        int max_b = arr[0].second;

        for(int k =0; k<m;k++){

             if(arr[k].second <= max_b){
                passed++;
                max_b= arr[k].second;
            }

        }

        solved_arr.push_back(passed);

    }

    for_each(solved_arr.begin(),solved_arr.end(),[](int n){cout << n <<"\n";});

}


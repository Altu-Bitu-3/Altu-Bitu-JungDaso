#include "map"
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
map<int,int> index_map;
bool cmp(const pair<int,int>& A, const pair<int,int>& B){

    if(A.first != B.first){
        return A.first > B.first;
        // 빈도 높은 순
    }
    return index_map[A.second] < index_map[B.second];
}
int main(){
    int n,c;
    map<int,int> quan;
    cin >> n >> c;

    int input ;

    for(int i =0; i<n;i++){

        cin >> input;
        quan[input]++;
        if(index_map[input] == 0){
            index_map[input] = i + 1;
        }
    }

    vector<pair<int,int>> arr;

    for(auto &iter : quan){
        arr.emplace_back(iter.second,iter.first);
    }

    sort(arr.begin(),arr.end(),cmp);


    for(int i = 0 ; i < arr.size() ; i++){ //요소의 개수 만큼

        for(int j = 0 ; j < arr[i].first ; j++){ // 빈도 수 만큼 반복

            cout << arr[i].second << ' ';
        }
    }

    return 0;


}
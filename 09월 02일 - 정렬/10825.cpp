//
// Created by dasoya on 2022/09/04.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


struct student {
    string name;
    int kor, eng, math;
};

bool cmp(student a, student b){

    if(a.kor == b.kor){
        return a.eng < b.eng;
    }
    else if(a.eng == b.eng){
        return a.math < b.math;
    }
    else if(a.math == b.math){
        return a.name < b.name;
    }
    return a.kor > b.kor;

}

bool cmpAdv(const student& a, const student& b){

    if(a.kor != b.kor){
        return a.kor > b.kor;
    }

    if(a.eng != b.eng){
        return a.eng < b.eng;
    }

    if(a.math != b.math){
        return a.math > b.math;
    }

    if(a.name != b.name){
        return a.name < b.name;
    }
}
int main() {

    int n;

    cin >> n;

    vector<student> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;

    }

    sort(arr.begin(),arr.end(),cmpAdv);

    for(int i = 0; i< n ; i++){
        cout << arr[i].name<<"\n";
    }
}
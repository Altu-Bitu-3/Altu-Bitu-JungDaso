#include <iostream>
#include <vector>



using namespace std;
typedef pair<int,int> ci;


ci maxVisitor(int n, int x, vector<int> &visitor){

    int section_visitor = 0;

    //슬라이딩 윈도우 초기화
    for(int i=0; i<x; i++){
        section_visitor += visitor[i];
    }

    int ans = section_visitor;
    int cnt = 1;
    for(int i =x ; i<n ; i++){
        section_visitor -= visitor[i-x];
        section_visitor += visitor[i];
        if(section_visitor > ans){
            ans = section_visitor;
            cnt = 1;
        }else if(section_visitor == ans){
            cnt ++;
        }

    }

    return {ans, cnt};

}

int main(){

    int n,x;

    cin >> n >>x;

    vector<int> visitor(n,0);

    for(int i=0; i<n;i++){
        cin >> visitor[i];
    }

    ci ans = maxVisitor(n,x,visitor);

    if(ans.first==0) {
        cout << "SAD\n";
        return 0;
    }

    cout << ans.first << "\n" << ans.second;

    return 0;

}

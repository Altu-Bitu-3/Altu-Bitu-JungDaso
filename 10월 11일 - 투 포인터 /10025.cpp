#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e6;

//슬라이딩 윈도우로 얼음들의 최대합 구함.
int maxIce(int k, int end_point, vector<int> position){
    int section = 2*k+1;

    int section_ice = 0;

    for(int i=0;i<section;i++){
        if(i>end_point) // 윈도우 영역이 양동이가 존재하는 끝 점보다 클 수도 있음.
            break;
        section_ice += position[i];
    }

    int ans = section_ice;
    for (int i = section; i <= end_point; ++i) {

        section_ice -=position[i-section_ice];
        section_ice += position[i];
        ans = max(ans, section_ice);
    }

    return  ans;




}
int main(){

    int n,k,g,x,end_point=0;

    cin >> n >>k;
    vector<int> position(SIZE+1,0);
    while(n--){
        cin >> g >>x;
        position[x] =g;
        end_point = max(end_point,x);
    }

    cout << maxIce(k,end_point,position);
}

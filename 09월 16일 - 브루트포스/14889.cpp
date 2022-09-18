#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
const int MAX_DIFF = 1000;
vector<vector<int>> power;

int sumPower(vector<int> team){
    int sum =0;
    int size = team.size();

    for (int i = 0; i < size; ++i) {

        for (int j = 1; j < size; ++j) {

            sum += power[team[i]][team[j]] + power[team[j]][team[i]];
        }
    }

    return sum;
}
int calcDiff(int n, vector<bool>& is_teamA){

    vector<int> teamA;
    vector<int> teamB;

    for(int i =0; i<n ; i++){
        if(is_teamA[i]){
            teamA.push_back(i);

        }

        else{
            teamB.push_back(i);
        }
    }

    int diff = sumPower(teamA)- sumPower(teamB);
    return abs(diff);
}

int findMinDiff(int n){

    vector<bool> is_teamA(n, true);

    for(int i=0; i<n/2;i++){
        is_teamA[i] = false;
    }

    int answer = MAX_DIFF;

    do{
        answer = min(answer,calcDiff(n, is_teamA));
    }while(next_permutation(is_teamA.begin()+1,is_teamA.end()));


    return  answer;
}

int main(){
    int n;

    cin >> n;
    power.assign(n, vector<int>(n,0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> power[i][j];

        }

    }

    cout << findMinDiff(n);
    return 0;
}
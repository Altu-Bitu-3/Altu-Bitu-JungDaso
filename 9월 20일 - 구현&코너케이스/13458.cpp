#include "iostream"
#include "vector"

using namespace std;

int B, C;
vector<int> students;

long long calc(int n){
   long long answer = n;

    for(int i = 0; i < n ; i ++){


        if(students[i] <= B)
            continue;

        students[i] -= B;

        answer += students[i]/C;

        if(students[i]%C !=0){
            answer++;
        }
    }

    return answer;
}
int main(){
    int n;
    cin >> n;

    int temp = n;
    int input;
    while(temp--){
        cin >> input;
        students.push_back(input);
    }

    cin >> B >> C;

    cout << calc(n);


}

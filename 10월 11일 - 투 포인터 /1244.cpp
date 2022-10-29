#include <iostream>
#include <vector>

using namespace std;

void maleFunc(int n, vector<int>& switches){ //벡터 호출은 포인터로 이루어져야 함!

    for(int i = n; i< switches.size();i+=n){
        switches[i] = !switches[i];
    }


}

void femaleFunc(int n, vector<int>& switches){

    switches[n] = !switches[n];
    int right = n+1, left = n-1;

    while(left >= 1 && right<switches.size()
    && switches[right]==switches[left]){ // 대칭 판별


        switches[right] = !switches[right];
        switches[left] = !switches[left];
        right++;
        left--;
    }
}


int main(){

    int n,m,a,b;


    cin >> n;
    vector<int> switches(n+1,0);


    for(int i =1; i<= n;i++){
        cin >> switches[i];
    }

    cin >> m;

    while(m--){

        cin >> a >> b; //a 성별 b 숫자

        if(a==1)
            maleFunc(b,switches);
        else femaleFunc(b,switches);

    }

    for(int i = 1; i<=n;i++){

        cout << switches[i] <<" ";

        if(!(i%20))
            cout << "\n";
    }

}

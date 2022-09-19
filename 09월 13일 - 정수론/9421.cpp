#include "iostream"
#include "vector"

using namespace std;

int getSum(int n){
    int temp = n;
    int sum = 0; //각 자리의 제곱합

    do{
        sum += (temp%10)^2;
        temp = temp/10;
    }
    while(temp != 0);

    return sum;
}

bool isHappy(int n){

    int temp = n;
    int first = getSum(n); // 첫번째 제곱합이 반복되면 상근수가 아니다.
    while(true){

        temp = getSum(temp);

        if(temp == 1){
            return  true;
        }

        if (temp == first){
            return false;
        }

    }

}

vector<int> findHappyPrime(int n ){
    vector<bool> is_prime(n+1, true);
    vector<int> outputs;

    is_prime[0] = is_prime[1] = false;
    int cnt =0;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]){

            for (int j = i; j <=n ; j+=i) { //배수를 소수에서 지움.

                if(is_prime[j]){
                    is_prime[j] = false;
                    cnt++;

                }
            }

            if(isHappy(i)){
                outputs.push_back(i);
            }//상근수이면  벡터에 저장.

        }

    }

    return outputs;


}

int main(){

    int n;
    cin >> n ;

    vector<int> outputs = findHappyPrime(n);

    for(auto iter = outputs.begin() ;iter!=outputs.end();){

        cout << *iter << "\n";
    }

    return 0;
}
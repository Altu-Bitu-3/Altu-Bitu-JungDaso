#include "iostream"
#include "vector"
#include <cmath>
#include "set"

using namespace std;

vector<bool> isPrime(int n){

    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i<=  sqrt(n) ; i++){

        if(is_prime[i]){

            for (int j = i*i; j <= n; j+=i) {
                is_prime[j] = false;
            }
        }

    }

    return is_prime;

}



int getSum(int n){
    int temp = n;
    int sum = 0; //각 자리의 제곱합

    do{
        sum += pow(temp%10,2);
        temp = temp/10;
    }
    while(temp != 0);

    return sum;
}

bool isHappy(int n){

    int temp = n;
    set<int> s; // 첫번째 제곱합이 반복되면 상근수가 아니다.
    while(true){

        temp = getSum(temp);

        if(temp == 1){
            return  true;
        }

        if (s.find(temp) != s.end()){
            return false;
        }

        s.insert(temp);

    }

}

vector<int> findHappyPrime(int n ){
    vector<bool> is_prime = isPrime(n);
    vector<int> outputs;

    for(int i=2;i<n;i++){
        if(is_prime[i]&&isHappy(i)){
            outputs.push_back(i);
        }
    }

    return outputs;


}

int main(){

    int n;
    cin >> n ;

    vector<int> outputs = findHappyPrime(n);

    for(auto iter = outputs.begin() ;iter!=outputs.end();iter++){

        cout << *iter << "\n";
    }

    return 0;
}
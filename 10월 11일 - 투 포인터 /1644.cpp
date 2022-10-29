#include <iostream>
#include <vector>

using namespace std;

//에라토스테네스의 체

vector<bool> isPrime(int n){

    vector<bool> is_prime(n+1,true);

    is_prime[0] = is_prime[1] = false;

    for(int i=2;i*i<=n;i++){
        if(!is_prime[i])
            continue;

        for(int j = i*i;j<=n;j+=i){
            is_prime[j] = false;
        }
    }

    return is_prime;

}

vector<int> primeList(int n, vector<bool> &is_prime){
    vector<int> prime_list;

    for(int i =2;i<=n;i++){
        if(is_prime[i]){ //i가 소수라면
            prime_list.push_back(i);
        }
    }
    prime_list.push_back(0);
    prime_list.push_back(0); //런타임 에러를 방지 하기 위해 미리 값을 채워줌.
    return prime_list;
}

int cntPrimeSum(vector<int> &prime_list,int left, int right,int target){
    int sum = prime_list[left];
    int ans =0, size = prime_list.size()-1;

    while(left <= right && right < size){


        if(sum == target){
            ans++;
            sum -= prime_list[left++];
            if(right+1 ==size)
                break;
            sum += prime_list[++right];

        }else if(sum < target){
            if(right+1 ==size)
                break;
            sum += prime_list[++right];
        }
        else{
            sum -= prime_list[--left];
        }
    }

    return ans;
}
int main(){

    int n;

    cin >> n;

    vector<bool> is_prime = isPrime(n);
    vector<int> prime_list = primeList(n,is_prime);

    cout << cntPrimeSum(prime_list,0,0,n);


    return 0;
}
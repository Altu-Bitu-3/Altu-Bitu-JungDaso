#include "iostream"
#include "vector"
using namespace std;

int findPrime(int n , int k){
    vector<bool> is_prime(n+1, true);

    is_prime[0] = is_prime[1] = false;
    int cnt =0;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]){

            for (int j = i; j <=n ; j+=i) { //배수를 소수에서 지움.

                if(is_prime[j]){
                    is_prime[j] = false;
                    cnt++;
                    if(cnt== k){
                        return j;
                    }
                }
            }

        }

    }

    return  -1;
}
int main(){

    int n, k ;
    cin >> n >> k;

    cout << findPrime(n,k);
    return 0;
}
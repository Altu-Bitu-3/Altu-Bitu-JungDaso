#include "iostream"

using namespace std;

int findConstructor(int n){

    int sum = 0;

    for(int i =1 ; i <n; i ++){

        int temp = i;

        sum = i;

        while(temp >0){
            sum += temp% 10;
            temp = temp/10;
        }

        if(sum ==n ){
            return i ;
        }
    }
    //생성자가 없는 경우
    return 0;
}

int main(){
    int n;

    cin >> n;

    cout << findConstructor(n);


    return 0;
}

#include "iostream"

using namespace std;


int calc(string input,int k){

    int hour = (input[0] -'0')*10 +input[1] - '0';
    int min = (input[3]-'0')*10+input[4] - '0';

    //통화가 끝나는 시간
    int e_min = (min +k)%60;
    int e_hour = (hour + (min+k)/60)%24;

    int fee = 0;

    if(hour < 7 && e_hour >= 7){ // 통화 중간에 7:00시를 지나는 경우

        fee += (60-min)* 5;
        fee+= e_min*10;
        return fee;
    }

    if(hour<19 && e_hour >= 19 ) // 통화 중간에 19:00시를 지나는 경우
    {
        fee += (60-min)* 10;
        fee+= e_min*5;
        return fee;
    }

    // 같은 요금제 시간대 에서 통화가 끝나는 경우
    if(7 <= hour && 19 > hour){ // 7:00 ~ 18:59분
        fee += k*10;

    }
    else{
        fee += k*5;

    }

    return fee;


}

int main(){

    int n ;
    int ans=0;
    cin >> n;

    while(n--){

        string input;
        int k;

        cin >> input >> k;
        ans += calc(input,k);

    }

    cout << ans;
}
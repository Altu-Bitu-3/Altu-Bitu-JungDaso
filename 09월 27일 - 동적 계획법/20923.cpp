#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef deque<int> di;

string check(di& gnd_do,di& gnd_su){

    if(!gnd_do.empty()&&gnd_do.back()==5){
        return "do";
    }

    if(!gnd_su.empty()&& gnd_su.back()==5){
        return "do";
    }

    if(!gnd_do.empty()&&!gnd_su.empty()&&gnd_do.back()+gnd_su.back()==5)
        return "su";


    return "\n";
}

string cardFliping(string index,di& dodo,di& gnd_do,di& su,di& gnd_su){

    string pusher = "\n";

    //도도 차례
    if(index=="do") {
        //도도 카드를 한장 꺼냄
        gnd_do.push_back(dodo.back());
        dodo.pop_back();

        //도도의 카드가 비었는 지 검사
        if (dodo.empty()) {
            return "su_win";
        }

        //종 치는 지 검사
        pusher = check(gnd_do, gnd_su);

        return pusher;
    }

    //수연 차례

        //수연이 카드를 한장 꺼냄
        gnd_su.push_back(su.back());
        su.pop_back();

        //수연의 카드가 비었는 지 검사
        if(su.empty()) {
            return "do_win";
        }

        pusher = check(gnd_do,gnd_su);

    return pusher;

}

void cardCleaning(di& card, di& gnd_me, di& gnd_you){

    // 상대방의 그라운드 패를 뒤집어서 넣어줌.
    while(!gnd_you.empty()){
        card.push_front(gnd_you.front());
        gnd_you.pop_front();
    }

    // 자신의 그라운드 패를 뒤집어서 넣어줌.
    while(!gnd_me.empty()){
        card.push_front(gnd_me.front());
        gnd_me.pop_front();
    }

    return;

}

string gameStart(int m, deque<int>& dodo, deque<int>&su){

    deque<int> gnd_do,gnd_su;
    string index = "do"; // 차례

    for (int i = 0; i < m; ++i) {

        string result = cardFliping(index,dodo,gnd_do,su,gnd_su);

        //턴 체인지
        if(index=="do") index = "su";
        else index = "do";

        //수연의 카드 수가 0이 된 경우
        if(result=="do_win")
            return "do";

        //도도의 카드 수가 0이 된 경우
        if(result=="su_win")
            return "su";

        //도도가 종을 친 경우
        if(result == "do"){
            cardCleaning(dodo,gnd_do,gnd_su);

            continue;
        }

        // 수연이 종을 친 경우
        if(result=="su"){
            cardCleaning(su,gnd_su,gnd_do);

           continue;

        }


    }

    // 게임 종료
    if(dodo.size()>su.size())

        return "do";

    if(dodo.size() < su.size())
        return "su";

    if(dodo.size()==su.size())
        return "dosu";


    return 0;

}

int main(){

    int n,m;

    cin >> n >> m;

    deque<int> dodo , su;

    int input1, input2;

    while(n--){

        cin >> input1 >> input2;
        dodo.push_back(input1);
        su.push_back(input2);
    }

    cout << gameStart(m,dodo, su);

    return 0;
}

// 문제 이해(턴 횟수 관련) 참조 https://www.acmicpc.net/board/view/64852

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int bf(vector<string> num, vector<int> strike, vector<int> ball){

    int ans =0;

    //가능한 숫자를 모두 답에 해당하는 지 검사.
    for(int k= 123 ; k<= 987 ; k++)
    {
        string temp = to_string(k); //현재 검사하려는 수

        //숫자가 겹치는 경우 제외
        if(temp[0]==temp[1] || temp[1] == temp[2] || temp[0] == temp[2])
            continue;

        //0이 포함 된 경우 제외
        if(temp[0]=='0'||temp[1]=='0'||temp[2]=='0')
            continue;

        bool flag = true;
        //답인지 검사, 스트라이크와 볼의 개수를 확인하고 주언진 개수와 동일해야 함
        for(int i=0; i< num.size();i++){

            string index = num[i]; // 민혁이가 부른 수
            int s=0,b=0;

            //스트라이크 개수와 볼 개수 계산
            for(int j=0;j<index.size();j++){
                if(index[j]==temp[j])
                    s++;
                if(index[j]==temp[(j+1)%3]||index[j]==temp[(j+2)%3])
                    b++;
            }

            //주어진 답안이 하나라도 안 맞는 경우
            if(s!=strike[i]||b!=ball[i])
                flag = false;

        }

        if(flag)
            ans++;


    }

    return ans;

}

int main(){

    int n;

    cin >> n;

    vector<string> num(n);
    vector<int> s(n,0),b(n,0);

    for(int i=0; i< n; i++)
    {
        cin >> num[i] >> s[i] >> b[i];
    }

    //브루트 포스
    cout << bf(num,s,b);


}
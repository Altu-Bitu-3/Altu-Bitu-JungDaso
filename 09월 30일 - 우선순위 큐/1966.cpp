#include <iostream>
#include <queue>

using namespace std;

int cal(int m, queue<int> queue, priority_queue<int> arr){

    int ans = 0; // 답 저장

    while(!arr.empty()){

        // 중요도가 높은 순서가 아닐 때
        if(queue.front() != arr.top()){

            //맨 뒤로 보냄
            int temp = queue.front();
            queue.push(temp);
            queue.pop();

            //m의 순서 역시 하나 줄음
            if(m!=0){
                m--;
                continue;
            }

            //현재 m이 맨뒤로 밀려나감.
            m = queue.size() -1 ;
            continue;

        }

        arr.pop();
        queue.pop();
        ans++;

        if(m==0) // m번째 숫자가 중요도가 가장 크고 나가는 순서가 제일 앞임
            break;

        m--; //m번째가 아닌 숫자이며 중요도가 큰 숫자가 나가서 m의 순서가 하나 줄음.
    }

    return ans;

}

int main(){

    int t ;

    cin >> t ;

    while(t--){

        int n,m;

        cin >> n >> m;

        int input;
        priority_queue<int> arr;
        queue<int> queue;

        for (int i = 0; i < n; ++i) {

            cin >> input;
            arr.push(input);
            queue.push(input);

        }

        cout << cal(m,queue,arr) << "\n";

    }


}
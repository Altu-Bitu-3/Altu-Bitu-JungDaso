#include <iostream> //입출력을 위한 헤더
#include <vector> // 벡터 사용을 위한 헤더

using namespace std; // std 라이브러리 사용

struct info { // 컨테이너 벨트 칸의 내구도와 로봇 존재 여부를 저장하는 구조체
    int power; //  내구도
    bool is_on; // 로봇 존재 여부
};

vector<info> belt;  //컨테이너 벨트 정보(내구도, 로봇 여부)를 저장하는 벡터 선언
int zero_power;     //내구도가 0인 벨트 칸의 개수, k가 되면 프로그램 종료

int minusPosition(int n, int pos) { //한칸 회전 시 올리는 위치와 내리는 위치의 인덱스 감소
    if (--pos >= 0) { // 위치를 1 감소 시키고 0 이상이라면
        return pos; // 그대로 포지션을 반환한다.
    }
    return n * 2 - 1; // 음수라면 -1칸이므로 마지막 칸을 반환한다.
}

void second(int n, int start, int end) {// 로봇의 이동을 진행함
    int cur = end; // 내리는 위치를 현재 위치에 저장, cur를 하나씩 감소하며 먼저 올라간 로봇 부터 검사
    while (cur != start) { //end - 1 부터 start 까지 검사
        cur = minusPosition(n, cur); // 현재 위치를 하나 줄임
        int next = (cur + 1) % (n * 2); //다음 위치
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) {
            //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
            belt[cur].is_on = false; // 현재 위치의 로봇을 제거
            belt[next].power--; // 로봇이 이동 했으므로 다음 위치의 내구도 감소
            if (next != end) { //내리는 위치 아닐 경우만
                belt[next].is_on = true; //로봇 옮기기
            }
            if (belt[next].power == 0) { // 로봇 이동 후 벨트의 내구도가 0이면
                zero_power++; //내구도가 0인 벨트를 저장하는 변수를 1 높임.
            }
        }
    }
}

void third(int start) { // 로봇을 올리는 과정을 진행하는 함수
    if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
        belt[start].is_on = true; // 로봇으 올림
        belt[start].power--; // 내구도 감소
        if (belt[start].power == 0) { // 로봇을 올리고 내구도가 0이되면
            zero_power++; // 변수에 저장
        }
    }
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 *
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 *
 * 해당 문제는 deque 자료구조를 사용해서도 구현 가능 (1번에서 회전하는 부분만 다르고 2번, 3번은 동일한 로직)
 */

int main() { //메인 함수
    ios_base::sync_with_stdio(false); //독립적 버퍼 사용으로 c++ 입출력 속도 향상
    cin.tie(NULL); // 입력과 출력의 버퍼를 분할해서 입출력 속도 향상.

    int n, k; // 컨베이어 벨트의 길이, 종료 기준

    //입력
    cin >> n >> k; //n,k 입력
    belt.assign(n * 2, {0, false});//벨트의 길이는 2N, 내구도와 로봇 존재여부를 초기화
    for (int i = 0; i < n * 2; i++) { //for 문을 이용해 벨트의 길이만큼 반복
        cin >> belt[i].power; // 각 칸의 내구도를 입력
    }

    //연산
    int start = 0;    //올리는 위치
    int end = n - 1;  //내리는 위치
    int step = 0;     //단계 수
    while (true) { //종료 조건이 만족하기 전까지 반복
        start = minusPosition(n, start); // 벨트 회전, 올리는 위치 한칸 감소
        end = minusPosition(n, end); // 벨트 회전, 내리는 위치 한칸 감소
        if (belt[end].is_on) { //벨트 회전 후, 로봇이 내리는 위치에 있다면 내리기
            belt[end].is_on = false;  // 로봇 내리기
        }
        second(n, start, end); // 2번째 과정을 위한 함수 호출
        third(start); // 3번째 과정을 위한 함수 호출
        step++; // 출력을 위한 단계 수 저장
        if (zero_power >= k) { // 내구도가 0인 컨테이너 벨트가 k개 이상 시 과정 종료
            break;// break로 while문을 빠져나옴
        }
    }

    //출력
    cout << step;
    return 0;// 종료
}
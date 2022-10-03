#include <iostream> //c++ 입출력을 위한 헤더
#include <vector> // vector 사용을 위한 헤더
#include <algorithm> // max 사용을 위한 알고리즘 헤더

using namespace std; // std 라이브러리 사용

/*
* 동적프로그래밍을 이용하여 값을 업데이트
* 더미 인덱스를 사용하여 예외 없이 한 번에 처리
* max(): 두 개 이상의 값을 비교할 때는 {}로 묶기
*/

int maxCandy(int n, int m, vector<vector<int>>dp) // 재귀함수 사용하여 계산
{
    // 동적 계획법으로 사탕의 개수 계산
    for (int i = 1; i <= n; i++) { // 가로 길이만큼 반복
        for (int j = 1; j <= m; j++) { // 세로 길이 만큼 반복
            dp[i][j] += max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }); // 가장 큰 값으로 업데이트
            // 준규가 갈 수 있는 방을 토대로 현재 위치를 도달할 수 있는 이전 위치의 방 중 가장 큰 값으로
            // 현재 위치의 값을 초기화해준다.
        }
    }
    return dp[n][m]; // 마지막 방까지 도달하며 얻은 최대 사탕 개수를 리턴
}

int main() //메인 함수
{
    // 입력
    int n, m; // 미로의 가로 길이, 세로 길이
    cin >> n >> m; // 입력
    vector<vector<int>> maze(n + 1, vector<int>(m + 1, 0)); // 1부터 인덱스를 사용하여 각각 길이보다 1 큰 이차원 벡터 선언, 0으로 초기화
    for (int i = 1; i <= n; i++) { // 가로 길이만큼 반복
        for (int j = 1; j <= m; j++) { // 세로 길이만큼 반복
            cin >> maze[i][j]; // 각 방의 사탕 개수를 입력
        }
    }
    // 연산 & 출력
    cout << maxCandy(n, m, maze);
    return 0; // 프로그램 종료
}

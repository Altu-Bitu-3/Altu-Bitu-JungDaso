#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool cmp(const int &a, const int &b) {

    return a > b;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<>());

    long long int sum = 0; // 헤맸던 부분. int의 최댓값과 합산한 변수의 최댓값을 생각할 필요가 있었음. 테스트할 때 최댓값으로 해보면 더 쉽게 오류를 찾을 수 있을 듯!
    for (int i = 0; i < n; i++) {

        if (arr[i] - i > 0)
            sum += arr[i] - i;
    }

    cout << sum;
}
#include "iostream"
#include "map"
#include "vector"

using namespace std;
typedef map<int,int> ci;

void add(ci& m1, ci& m2,vector<int>& sum,int n){
    int tmp = 0;

    for (int i = 0; i < n + 1; i++) {

        int rem = (m1[i] + m2[i] + tmp) % 10;//일의 자리 수 계산
        tmp = (m1[i] + m2[i] + tmp) / 10; //올림

        if (i == n && rem == 0)
            break;

        sum.insert(sum.begin(), rem); // 작은 자리 부터 계산하므로 벡터의 앞에 계산 값을 넣어줌
    }

}

int main() {
    string A, B;


    map<int, int> m1, m2;
    vector<int> sum;

    cin >> A >> B;

    if (A.length() < B.length()) { // 큰 자리를 가진 숫자가 A에 오게 만듦.
        string tmp = A;
        A = B;
        B = tmp;
    }

    for (int i = 0; i < A.length(); i++) { // 낮은 자리수 부터 저장.
        int index = A.length() - i - 1;
        m1[i] = A[index] - '0';


    }
    for (int i = 0; i < B.length(); i++) {
        int index = B.length() - i - 1;
        m2[i] = B[index] - '0';

    }

    int n = A.length(); // 큰 수의 최대 자릿 수
    add(m1,m2,sum,n);


    for (auto &iter: sum) {
        cout << iter;
    }

}
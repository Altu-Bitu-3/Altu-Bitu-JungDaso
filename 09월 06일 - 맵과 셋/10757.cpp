#include "iostream"
#include "map"
#include "vector"

using namespace std;

vector<int> add(string& a, string& b){
    int tmp = 0;
    int a_index = a.size()-1;
    int b_index = b.size()-1;

    vector<int> sum;

    while(a_index>=0 && b_index>=0){

        int num = (a[a_index--]-'0') +( b[b_index--]-'0') +tmp; //더한 값
        int rem = num % 10;
        tmp = num / 10; //올림

        sum.insert(sum.begin(),rem);
    }

    while (a_index >= 0) {
        int num = a[a_index--] - '0';

        num += tmp;
        tmp = num / 10;
        sum.insert(sum.begin(),num % 10);
    }

    // 남은 올림 확인
    if (tmp)
        sum.insert(sum.begin(),1);

    return sum;
}

int main() {

    string A, B;

    vector<int> sum;

    cin >> A >> B;

    if (A.length() < B.length()) { // 큰 자리를 가진 숫자가 A에 오게 만듦.
        swap(A,B);
    }

    sum = add(A,B);

    // 출력
    for (auto &iter: sum) {
        cout << iter;
    }

}
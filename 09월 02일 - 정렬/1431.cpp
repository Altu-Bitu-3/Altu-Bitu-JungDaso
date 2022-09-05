#include "iostream"
#include "vector"
#include "algorithm"
#include "cctype"


using namespace std;

int getSum(const string &arr) {

    int sum = 0;
    for (int i = 0; i < arr.length(); i++) {
        if (isdigit(arr[i])) //정수에 해당하는 문자만 true
            sum +=  arr[i] -'0'; // 아스키코드를 정수로
    }

    return sum;
}

bool cmp(const string &a, const string &b) {

    if (a.length() != b.length()) {
        return a.length() < b.length();
    }

    if(getSum(a) != getSum(b))
        return getSum(a) < getSum(b);

    return a < b;

}



int main() {

    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), cmp);

    for_each(arr.begin(),arr.end(),
             [](string n){cout << n <<"\n";});
}

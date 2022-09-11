#include "iostream"
#include "set"

using namespace std;

void calc(string a, int n, set<int> &s) {

    if (a == "add") {
        s.insert(n);

        return;
    } else if (a == "remove") {
        s.erase(n);
        return;
    } else if (a == "check") {
        cout << s.count(n) << "\n";
        return;
    } else if (a == "toggle") {
        if (s.count(n)) {
            s.erase(n);
        } else s.insert(n);

        return;
    }

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<int> s;
    set<int> all; // 매번 반복문을 통해 전체 집합을 넣어 주면 시간 초과이므로 미리 초기화 해둠.
    int i = 20;
    while (i) {
        all.insert(i--);
    }
    int n, input;
    string func;

    cin >> n;


    while (n--) {

        cin >> func;

        if (func != "all" && func != "empty") {

            cin >> input;
            calc(func, input, s);
        }
        if (func == "all") {

            s = all;
        } else if (func == "empty") {
            s.clear();

        }
    }

}



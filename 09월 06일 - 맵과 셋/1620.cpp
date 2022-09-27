#include "iostream"
#include "map"

using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string input;
    map<string, int> pocket_name;
    map<int, string> pocket_num;

    cin >> n >> m;

    for (int i = 1 ; i <= n; i++) {
        cin >> input;
        pocket_name[input] = i;
        pocket_num[i] = input;
    }

    while(m--){
        cin >> input;
        if(isdigit(input[0])){
            int number = stoi(input);
            cout<< pocket_num[number] << '\n';

        }
        else{
            cout << pocket_name[input] << '\n';
        }
    }



    return 0;
}

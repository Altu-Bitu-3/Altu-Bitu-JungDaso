#include "iostream"
#include "vector"

using namespace std;

vector<int> arr, sorted;

void merge(int left, int middle, int right){

    int p1 = left;
    int p2 = middle +1;
    int k = left;

    while(p1 <= middle && p2 <= right){

        if(arr[p1] < arr[p2]){
            sorted[k++] = arr[p1++];

        }
        else {
            sorted[k++] = arr[p2++];

        }
    }

    while(p1 <= middle){
        sorted[k++] = arr[p1++];
    }

    while(p2 <= right){
        sorted[k++] = arr[p2++];
    }

    for(int i= left; i <= right;i++ ){
        arr[i] = sorted[i];
    }
}

void mergeSort(int left, int right){

    if(left < right){
        int mid = (left + right) /2;
        mergeSort(left, mid);
        mergeSort(mid+1,right);

        merge(left, mid, right);

    }
}


int main(){

    int n;

    cin >> n;
    arr.assign(n,0);
    sorted.assign(n,0);

    for(int i =0; i<n ; i++){
        cin >> arr[i];
    }

    mergeSort(0,n-1);

    for(int i =0 ; i < n; i++){
        cout << arr[i] << "\n";
    }
}
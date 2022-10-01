#include "iostream"
#include "vector"
#include "queue"

using namespace std;

bool isEmpty(vector<int> &heap){

    return  heap.size() == 1;

}

void push(vector<int> &heap,int x){

    int idx = heap.size();

    heap.push_back(x);

    while(idx > 1 && heap[idx] > heap[idx/2]){
        swap(heap[idx],heap[idx/2]);
        idx /= 2;
    }

    return;

}

int pop(vector<int> &heap){


    int item = heap[1];
    heap[1] = heap[heap.size()-1];
    heap.pop_back();

    int size = heap.size();
    int parent =1 , child=2;

     while(child < size){

        if(child + 1 < size && heap[child+1] > heap[child]){

            child +=1;
        }

        if(heap[parent] < heap[child]){
            swap(heap[parent],heap[child]);
            parent = child;
            child = parent *2;
        }else{
            break;
        }
    }

    return item;

}

int main(){


    cin.tie(NULL);
    int n,x;

    cin >> n;

    priority_queue<int> queue;
    while(n--){
        cin >> x;

        if(x==0){

            if( queue.empty()){
                cout << "0\n";
            }
            else{
                cout <<queue.top() << "\n";
                queue.pop();
            }
        }
        else{
          queue.push(x);
        }
    }

    return 0;

}
#include <iostream>
#include <vector>
using namespace std;

struct maxHeap{

private:

    vector<int> mh;

    int parent(int pos){
        return (pos - 1) / 2;
    }

    int left(int pos){
        return pos * 2 + 1;
    }

    int right(int pos){
        return pos * 2 + 2;
    }

public:

    void insert(int x){
        mh.push_back(x);
        int current = mh.size() - 1;

        while(current != 0 and mh[parent(current)] < mh[current]){
            swap(mh[parent(current)], mh[current]);
            current = parent(current);
        }
    }

    int getMax(){
        return mh[0];
    }

    int extractMax(){
        int root  = mh[0];
        swap(mh[0], mh[mh.size() - 1]);             // Step 1: Замена
        mh.pop_back();                              // Step 2: Удаление последнего узла
        if(!mh.empty()) heapify(0);                 // Step 3: Просеивание
        return root;
    }

    void heapify(int current){
        int temp = left(current);                                           // Step 1
        if (temp > mh.size() - 1) return;
        
        if (right(current) < mh.size() and mh[right(current)] > mh[temp])
            temp = right(current);                                          // Step 2

        if (mh[current] < mh[temp]){
            swap(mh[current], mh[temp]);
            heapify(temp);                                                  // Step 3
        }
    }

    int size(){
        return mh.size() - 1;
    }

    void printTree(int current){
        cout << endl;
        cout << mh[current] << " -> ";
        if(left(current) >= mh.size()) return;
        cout << mh[left(current)];
        if(right(current) >= mh.size()) return;
        cout << ", " << mh[right(current)];
        printTree(left(current));
        printTree(right(current));
        return;
    }
    
    void print(){
        for(int i = 0; i < mh.size(); i++)
            cout << mh[i] << " ";
        cout << endl;
    }
};

int main(){

    int n; cin >> n;
    maxHeap heap;

    for(int i = 0; i < n; i++){
        int req; cin >> req;
        if(req == 0){
            int x; cin >> x;
            heap.insert(x);
        }
        else if(req == 1)
            cout << heap.extractMax() << endl;
    }
}
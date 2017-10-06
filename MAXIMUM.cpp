#include <iostream>

using namespace std;

struct Tuple {

    Tuple (){}
    Tuple (int e, int i){
        element = e;
        indexInIndexArray = i;
    }

    int element;
    long long indexInIndexArray;
};

class CHeap{

public:
    CHeap(long long k);
    ~CHeap();

    int addNewAndDeleteOld(int element);

    void heapify(long long i);

    int getMax(){
        return heapArray[0].element;
    }

private:
    Tuple * heapArray;

    long long * indexArray;
    long long first;
    long long heapSize;
    long long currentSize;

};

CHeap::CHeap(long long k) {
    currentSize = 0;
    heapSize = k;
    heapArray = new Tuple[heapSize];
    indexArray = new long long[heapSize];
    first = -1;
}

CHeap::~CHeap() {
    delete [] heapArray;
    delete [] indexArray;
}

int CHeap::addNewAndDeleteOld(int element) {

    long long i, parent;

    first = ( first + 1 ) % heapSize;

    if (currentSize < heapSize) {

        i = currentSize;
        indexArray[first] = currentSize;
        currentSize ++;

    } else {
        i = indexArray[first];
    }

    heapArray[i].element = element;
    heapArray[i].indexInIndexArray = first;

    parent = ( i - 1 ) / 2;

    while(parent >= 0 && i > 0)  {
        if(heapArray[i].element > heapArray[parent].element) {

            long long tempIndex = indexArray[heapArray[i].indexInIndexArray];
            indexArray[heapArray[i].indexInIndexArray] = indexArray[heapArray[parent].indexInIndexArray];
            indexArray[heapArray[parent].indexInIndexArray] = tempIndex;

            Tuple temp = heapArray[i];
            heapArray[i] = heapArray[parent];
            heapArray[parent] = temp;
        }
        i = parent;
        parent = (i-1)/2;
    }
    heapify(0);
}


void CHeap::heapify(long long i) {
    long long left, right;

    left = ( 2 * i ) + 1;
    right = ( 2 * i ) + 2;

    if(left < currentSize) {
        if(heapArray[i].element < heapArray[left].element) {

            long long tempIndex = indexArray[heapArray[i].indexInIndexArray];
            indexArray[heapArray[i].indexInIndexArray] = indexArray[heapArray[left].indexInIndexArray];
            indexArray[heapArray[left].indexInIndexArray] = tempIndex;

            Tuple temp = heapArray[i];
            heapArray[i] = heapArray[left];
            heapArray[left] = temp;

            heapify(left);
        }
    }

    if(right < currentSize) {
        if(heapArray[i].element< heapArray[right].element) {

            long long tempIndex = indexArray[heapArray[i].indexInIndexArray];
            indexArray[heapArray[i].indexInIndexArray] = indexArray[heapArray[right].indexInIndexArray];
            indexArray[heapArray[right].indexInIndexArray] = tempIndex;

            Tuple temp = heapArray[i];
            heapArray[i] = heapArray[right];
            heapArray[right] = temp;

            heapify(right);
        }
    }
}



int main (){

    long long n;
    long long k;

    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n ; ++i) {
        cin >> arr[i];
    }

    cin >> k;

    CHeap heap(k);

    for (long long j = 0; j < k ; ++j) {
          heap.addNewAndDeleteOld(arr[j]);
    }

    cout<<heap.getMax()<<" ";

    for (long long j = k; j < n ; ++j) {
        heap.addNewAndDeleteOld(arr[j]);
        cout<<heap.getMax()<<" ";
    }

    return 0;
}

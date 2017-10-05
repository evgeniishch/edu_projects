#include <iostream>
#include <vector>

using namespace std;

// -------------------- НОВЫЙ КОД -----------------------

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

    CHeap(long long k){

        currentSize = 0;
        heapSize = k;
        heapArray = new Tuple[heapSize];
        indexArray = new long long[heapSize];
        first = -1;

    }

    int addNewAndDeleteOld(int element) {

        long long i, parent; //индекс  нового элемента и родителя в массиве heapArray


        first = (first+1) % heapSize;

//        i = indexArray[first]; // возьмем из массива (индексов элементов в heapArray) индекс первого элемента

        if (currentSize < heapSize) {

            i = currentSize; // добавлям в конец если элементов меньше размера окна
            indexArray[first] = currentSize; //!!!

        } else {

            i = indexArray[first]; //добавляем на место первого элемента когда окно начинает сдвигаться

        }



        //добавим элемент в кучу ИЛИ заменим им тот, который раньше был first
        heapArray[i].element = element;
        heapArray[i].indexInIndexArray = first;

        parent = (i-1)/2;

        while(parent >= 0 && i > 0)  {
            if(heapArray[i].element > heapArray[parent].element) {

                //сначала поменям индексы элементов в IndexArray
                long long tempIndex = indexArray[heapArray[i].indexInIndexArray];
                indexArray[heapArray[i].indexInIndexArray] = indexArray[heapArray[parent].indexInIndexArray];
                indexArray[heapArray[parent].indexInIndexArray] = tempIndex;

                //затем поменям сами узлы в куче
                Tuple temp = heapArray[i];
                heapArray[i] = heapArray[parent];
                heapArray[parent] = temp;
            }

            i = parent;
            parent = (i-1)/2;
        }


        indexArray[first] = i;  //запомнили для элемента его номер в куче в массив IndexArray
//        first = (first + 1) % heapSize;

        //когда коретка полностью заполнится нам уже все равно
        if(currentSize < heapSize){
            currentSize++;
        }

        heapify(0); //упорядочим кучу

    }

    int getMax(){
        return heapArray[0].element;
    }

    void heapify(long long i) {
        long long left, right;
//        int temp;

        left = ( 2 * i ) + 1;
        right = ( 2 * i ) + 2;

        if(left < currentSize) {
            if(heapArray[i].element < heapArray[left].element) {

                //сначала поменям в IndexArray
                long long tempIndex = indexArray[heapArray[i].indexInIndexArray];
                indexArray[heapArray[i].indexInIndexArray] = indexArray[heapArray[left].indexInIndexArray];
                indexArray[heapArray[left].indexInIndexArray] = tempIndex;

                //затем поменям сами узлы в куче
                Tuple temp = heapArray[i];
                heapArray[i] = heapArray[left];
                heapArray[left] = temp;

                heapify(left);
            }
        }

        if(right < currentSize) {
            if(heapArray[i].element< heapArray[right].element) {

                //сначала поменям в IndexArray
                long long tempIndex = indexArray[heapArray[i].indexInIndexArray];
                indexArray[heapArray[i].indexInIndexArray] = indexArray[heapArray[right].indexInIndexArray];
                indexArray[heapArray[right].indexInIndexArray] = tempIndex;

                //затем поменям сами узлы в куче
                Tuple temp = heapArray[i];
                heapArray[i] = heapArray[right];
                heapArray[right] = temp;

                heapify(right);
            }
        }

    }
    void outHeap() {
        int i = 0;
        int k = 1;
        while(i < currentSize) {
            while((i < k) && (i < currentSize)) {
                cout << heapArray[i].element << " ";
                i++;
            }
            cout << endl;
            k = k * 2 + 1;
        }
        cout << '\n';
    }

    void printHeapArray(){
        for (int i = 0; i < heapSize ; ++i) {
            cout<<heapArray[i].element<<" ";
        }
    }

    void printIndexArray(){
        for (int i = 0; i < heapSize ; ++i) {
            cout<<indexArray[i]<<" ";
        }
    }

//private:
    Tuple * heapArray;

    long long * indexArray;
    long long first; // эти указатели для массива indexArray!!!

    long long heapSize;
    long long currentSize;

};

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

    heap.outHeap();cout<<endl;
    cout<<"first (индекс в массиве IndexArray: "<<heap.first<<endl;
    cout<<"heapArray: "; heap.printHeapArray(); cout<<endl;
    cout<<"indexArray: "; heap.printIndexArray(); cout<< endl<<endl;


    for (long long j = k; j < n ; ++j) {

        heap.addNewAndDeleteOld(arr[j]);

    }

    return 0;
}

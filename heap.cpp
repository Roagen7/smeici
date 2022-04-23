#include <iostream>

#define MAX_SIZE 65536
#define TYPE int


struct Heap {

    enum Type {
        MAX,
        MIN
    } type = MAX;

    int size = 0;
    int reserved = 1;

    TYPE* data = new TYPE[1];

};


void reserve(Heap* heap, int newReserved);

bool compare(Heap* heap, TYPE el1, TYPE el2);
bool lessThan(TYPE el1, TYPE el2);

int parent(int ix);
int left(int ix);
int right(int ix);

void put(Heap* heap, TYPE el);
TYPE get(Heap* heap);

void heapify(Heap* heap, int ix);
void buildHeap(Heap* heap);

void clearHeap(Heap* heap);
void swapType(Heap* heap);

void print(Heap* heap);

int main() {

    Heap heap;
    reserve(&heap,MAX_SIZE);


    put(&heap, 13);
    put(&heap, 10);
    put(&heap, 7);
    put(&heap, 6);
    put(&heap, 7);
    put(&heap, 3);
    put(&heap, 4);
    put(&heap, 2);
    put(&heap, 5);
    put(&heap, 1);


    print(&heap);

    get(&heap);
    print(&heap);
    get(&heap);

    print(&heap);
    swapType(&heap);
    print(&heap);


    return 0;
}


void reserve(Heap* heap, int newReserved){

    TYPE* newData = new TYPE[newReserved];

    int minReserved = heap->reserved <= newReserved ? heap->reserved : newReserved;

    for(int i = 0; i < minReserved;i++){

        newData[i] = heap->data[i];

    }

    delete[] heap->data;
    heap->data = newData;
    heap->reserved = newReserved;

}


bool compare(Heap* heap, TYPE el1, TYPE el2){

    if(heap->type == Heap::Type::MAX){

        return lessThan(el1,el2);


    }

    return lessThan(el2,el1);

}

bool lessThan(TYPE el1, TYPE el2){

    return el1 < el2;

}

int parent(int ix){

    return (ix - 1) / 2;

}

int left(int ix){

    return ix * 2 + 1;

}

int right(int ix){

    return ix * 2 + 2;

}

void print(Heap* heap){

    for(int i = 0; i < heap->size; i++){

        std::cout << heap->data[i] << " ";

    }

    std::cout << std::endl;



}


TYPE get(Heap* heap){

    TYPE val = heap->data[0];

    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    heapify(heap,0);

    return val;

}

void put(Heap* heap, TYPE el){

    if(heap->size == heap->reserved){

        reserve(heap,heap->reserved * 2);

    }


    heap->data[heap->size++] = el;

    int lowerIx = heap->size - 1;
    int upperIx = parent(heap->size - 1);

    while(lowerIx > 0){

        if(compare(heap,heap->data[lowerIx],heap->data[upperIx])){

            break;

        }

        std::swap(heap->data[upperIx],heap->data[lowerIx]);

        lowerIx = upperIx;
        upperIx = parent(lowerIx);

    }

}



void heapify(Heap* heap, int ix){

    int& val = heap->data[ix];
    int& valLeft = heap->data[left(ix)];
    int& valRight = heap->data[right(ix)];

    int maxIx = ix;


    if(compare(heap,val,valLeft) && left(ix) < heap->size){

        maxIx = left(ix);

    }

    if(compare(heap,val,valRight) && compare(heap,valLeft,valRight) && right(ix) < heap->size){

        maxIx = right(ix);

    }

    if(ix != maxIx){

        std::swap(heap->data[ix],heap->data[maxIx]);
        heapify(heap,maxIx);

    }


}


void buildHeap(Heap* heap){

    for(int j = heap->size / 2 - 1; j >= 0; j--){

        heapify(heap,j);

    }

}


void clearHeap(Heap* heap){

    heap->size = 0;

}


void swapType(Heap* heap){

    heap->type = heap->type == Heap::Type::MAX ? Heap::Type::MIN : Heap::Type::MAX;
    buildHeap(heap);

}
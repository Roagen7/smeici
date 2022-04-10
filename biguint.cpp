
#include <iostream>
#include <math.h>

#define VAL char
class List {

public:

    List() {

        head = { 0,nullptr, &tail };
        tail = { 0,&head, nullptr };

    }

    List(const List& other){

        head = { 0,nullptr, &tail };
        tail = { 0,&head, nullptr };

        for(int i = 0; i < other.len(); i++){

            Push(other[i]);

        }

    }

    void Push(VAL val) {

        Node* newNode = new Node;
        newNode->val = val;

        newNode->next = &tail;
        newNode->prev = tail.prev;


        tail.prev->next = newNode;
        tail.prev = newNode;

    }


    VAL Pop() {

        Node* toDelete = tail.prev;
        VAL valcpy = toDelete->val;

        tail.prev = toDelete->prev;
        toDelete->prev->next = &tail;

        delete toDelete;

        return valcpy;


    }


    ~List() {

        while (head.next->next != nullptr) {

            Pop();

        }

    }

    void operator=(const List& other){

        while(this->len() != 0){

            this->Pop();

        }


        for(int i = 0; i < other.len(); i++){

            this->Push(other[i]);

        }


    }


    VAL& operator[](int ix) {

        auto* current = &head;

        for (int i = 0; i <= ix; i++) {

            current = current->next;

        }


        return current->val;

    }

     const VAL& operator[](int ix) const {

        auto* current = &head;

        for (int i = 0; i <= ix; i++) {

            current = current->next;

        }


        return current->val;

    }

    friend const std::ostream& operator<<(std::ostream& os, const List& list){

        auto* current = list.head.next;

        while(current->next != nullptr){

            os << (int)current->val - '0';
            current = current->next;

        }

        return os;

    }



    int len() const{

        auto* current = head.next;
        int l = 0;

        while(current != nullptr){

            current = current->next;
            l++;

        }

        return l - 1;

    }


    friend bool operator>=(const List& l1, const List& l2){

        if(l1.len() > l2.len()){

            return true;

        } else if(l1.len() < l2.len()){

            return false;

        }

        for(int i = 0; i < l1.len(); i++){

            if(l1[i] > l2[i]){

                return true;

            } else if(l1[i] < l2[i]){

                return false;

            }

        }

        return true;

    }

    friend bool operator>(const List& l1, const List& l2){

        if(l1.len() > l2.len()){

            return true;

        } else if(l1.len() < l2.len()){

            return false;

        }

        for(int i = 0; i < l1.len(); i++){

            if(l1[i] > l2[i]){

                return true;

            } else if(l1[i] < l2[i]){

                return false;

            }

        }

        return false;

    }


    friend bool operator<=(const List& l1, const List& l2){

      return l2 >= l1;

    }

private:

    struct Node {

        VAL val;
        Node* prev = nullptr;
        Node* next = nullptr;

    } head, tail;


};


#define BigUInt List

int partition(BigUInt* arr, int left, int right){

    BigUInt* val = arr + left;

    left--;
    right++;

    while(true){

        while(true){

            left++;
            if(arr[left] >= *val) break;

        }

        while(true){

            right--;
            if(arr[right] <= *val) break;

        }

        if(left < right){

            BigUInt x = arr[left];
            arr[left] = arr[right];
            arr[right] = x;

        } else {

            break;

        }

    }

    return right;


}


void quicksort(BigUInt* arr, int left, int right){

    if(left < right){

        int pivot = partition(arr,left,right);
        quicksort(arr,left,pivot);
        quicksort(arr,pivot+1,right);

    }


}

void insertionsort(BigUInt* a, int n){

    for(int i = 1; i < n; i++){

        int j = i -1;

        BigUInt x = a[i];

        while(j >= 0 && a[j] > x){

            a[j+1] = a[j];
            j--;

        }

        a[j+1] = x;

    }

}


void selectionsort(BigUInt* a, int n){

    for(int i = 0; i < n; i++){

        int maxIx = i;
        BigUInt* maxVal = a + i;

        for(int j = i + 1; j < n; j++){

            if(*maxVal > a[j]){


                maxVal = a + j;
                maxIx = j;

            }
        }

        BigUInt swap = a[i];
        a[i] = a[maxIx];
        a[maxIx] = swap;

    }

}

void bubblesort(BigUInt* a, int n){

    for(int i = 0; i< n; i++){

        for(int j = i+1; j < n; j++){

            if(a[j-1] > a[j]){

                BigUInt swap = a[j-1];
                a[j-1] = a[j];
                a[j] = swap;

            }

        }

    }

}

void shellsort(BigUInt* a, int n){

    int m = log2(n);

    for(; m >= 1; m--){

        int k = pow(2,m)-1;

        for(int i = k; i < n; i++){

            BigUInt x = a[i];
            int j;

            for(j = i; j >= k && a[j-k] > x ;j -= k){

                a[j] = a[j-k];

            }

            a[j] = x;

        }

    }

}


void merge(BigUInt* a, int na, BigUInt* b, int nb){

    auto* dest = new BigUInt[na + nb];

    int i = 0, j = 0;

    int ix = 0;

    while(i < na && j < nb){

        if(b[j] > a[i]){

            dest[ix++] = a[i++];

        } else {

            dest[ix++] = b[j++];

        }
    }

    for(; i < na; i++){

        dest[ix++] = a[i];

    }

    for(; j < nb; j++){

        dest[ix++] = b[j];
    }

    for(int k = 0; k < na + nb; k++) {

        if (k < na) {

            a[k] = dest[k];

        } else {

            b[k - na] = dest[k];

        }

    }

    delete[] dest;

}


void mergesort(BigUInt* a, int n, int l){

    if( n == 1) {

        return;

    }

    int half = n/2;
    int nb = half * 2 < n ? n/2+1 : n/2;

    mergesort(a,half,l);
    mergesort(a,nb,l+n/2);


    merge(a+l,half,a + n/2 + l, nb);

}




int main(){


    int n;

    std::cin >> n;

    auto* arr = new BigUInt[n];

    char c = getchar();

    for(int i = 0; i < n; i++){

        char c = ' ';

        while(c != '\n'){

            c = getchar();

            if(c == '\n') break;

            (arr+i)->Push(c);

        }

    }

//    quicksort(arr,0,n-1);
//    insertionsort(arr,n);
//    selectionsort(arr,n);
//
//    bubblesort(arr,n);
//    shellsort(arr,n);

    mergesort(arr,n,0);

    for(int i = 0; i < n; i++){

        std::cout << arr[i];
        std::cout << " ";

    }

    delete[] arr;

}
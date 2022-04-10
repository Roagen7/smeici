#pragma once

inline int Left(int i){

    return 2 * i + 1;

}

inline int Right(int i){

    return 2 * (i + 1);

}


// O(lg n)
void Heapify(int* a, int n, int i){

    int max = i;

    if(Left(i) < n && a[Left(i)] > a[i]){

        max = Left(i);

    }

    if(Right(i) < n && a[Right(i)] > a[i] && a[Right(i)] > a[Left(i)]){

        max = Right(i);

    }

    if(max != i){

        std::swap(a[max],a[i]);
        Heapify(a,n,max);

    }

}


//nlgn
void BuildMaxHeap(int* a, int n){

    int start = n / 2 - 1;

    for(int i = start; i >= 0; i--){

        Heapify(a,n,i);

    }

}



void heapsort(int* a, int n){

    BuildMaxHeap(a,n);

    std::swap(a[0],a[n-1]);
    n--;
    for(;n >= 1; n--){

        Heapify(a,n,0);

        std::swap(a[0],a[n-1]);

    }



}
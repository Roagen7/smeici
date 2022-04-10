#pragma once

typedef unsigned int uint;

uint findMax(const uint* a, int n){

    uint max = a[0];

    for(int i = 1; i < n; i++){

        if(a[i] > max){

            max = a[i];

        }

    }

    return max;


}


void countingsort(uint* a, int n){

    uint M = findMax(a,n);
    int* counters = new int[M+1];

    for(int i = 0; i <= M; i++){

        counters[i] = 0;

    }

    for(int i = 0; i < n; i++){

        counters[a[i]]++;

    }

    int current = 0;

    for(int i = 0; i <= M; i++){

        for(int j = 0; j < counters[i]; j++){

            a[current++] = i;

        }

    }


}

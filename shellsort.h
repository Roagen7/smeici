#pragma once

#include <cmath>
#include <iostream>


void shellsort(int* a, int n){

    int m = log2(n);

    for(; m >= 1; m--){

        int k = pow(2,m)-1;

        for(int i = k; i < n; i++){

            int x = a[i];
            int j;

            for(j = i; j >= k && x < a[j-k];j -= k){

                a[j] = a[j-k];

            }

            a[j] = x;

        }

    }



}


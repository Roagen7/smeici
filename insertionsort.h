#pragma once

void insertionsort(int* a, int n){

    for(int i = 1; i < n; i++){

        int j = i - 1;

        int kv = a[i];

        while(j >= 0 && a[j] > kv){

            a[j+1] = a[j];
            j--;

        }

        a[j+1] = kv;

    }

}
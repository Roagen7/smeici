#pragma once

void merge(int* a, int na, int* b, int nb){

    int* dest = new int[na + nb];

    int i = 0, j = 0;

    int ix = 0;

    while(i < na && j < nb){

        if(a[i] < b[j]){

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






void mergesort(int* a, int n, int l){

    if( n == 1) {

        return;

    }

    int half = n/2;
    int nb = half * 2 < n ? n/2+1 : n/2;

    mergesort(a,half,l);
    mergesort(a,nb,l+n/2);


    merge(a+l,half,a + n/2 + l, nb);

}

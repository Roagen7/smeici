#pragma once

int partition(int* a, int left, int right){

    int x =a[left];

    left -= 1;
    right += 1;

    while(true){

        while(true){

            left++;
            if(a[left] >= x) break;

        }


        while(true){

            right--;
            if(a[right] <= x) break;

        }

        if(left < right){

            std::swap(a[right],a[left]);
        } else {

            break;
        }

    }

    return right;
}



void quicksort(int* a, int n, int left, int right){

    if(left < right){

        int pivot = partition(a,left,right);

        quicksort(a,n,left,pivot);
        quicksort(a,n,pivot+1,right);


    }

}
#pragma once

#include "Pair.h"
#include <cmath>

#define HTABLE_SIZE 10003


class HashTableOpen {

private:

    int size;
    Pair* data;

    unsigned long long eval(std::string wd);
    unsigned long long hash(const std::string& pair);

public:

    HashTableOpen(int size = HTABLE_SIZE);
    ~HashTableOpen();


    void add(const std::string key);
    Pair get(const std::string key);

    void remove(const std::string key);



};

unsigned long long HashTableOpen::eval(std::string wd) {

    unsigned long long ev = 0;

    for(int i = 0; i < wd.length(); i++){

        auto& c = wd[i];
        ev+= pow(255,i) * (unsigned char) c;

    }

    return ev;


}

unsigned long long HashTableOpen::hash(const std::string &key) {
    return eval(key) % size;
}

HashTableOpen::HashTableOpen(int size) : size(size){

    data = new Pair[size];

}

HashTableOpen::~HashTableOpen() {

    delete[] data;

}

void HashTableOpen::add(const std::string key) {


    unsigned long long hashVal = hash(key);

    for(int i = 0; i < size; i++){

        unsigned long long ix = (hashVal + i) % size;
        auto& el = data[ix];

        if(el.key == key){

            el.value++;
            return;

        }

        if(el.value == 0){

            el.key = key;
            el.value = 1;
            return;
        }

    }

    //ERROR

}

Pair HashTableOpen::get(const std::string key) {
    unsigned long long hashVal = hash(key);

    for(int i = 0; i < size; i++){

        unsigned long long ix = (hashVal + i) % size;
        auto& el = data[ix];

        if(el.value == 0){

            return {key,0};

        }


        if(el.key == key){


            return el;

        }

    }

    return {key, 0};

}

void HashTableOpen::remove(const std::string key) {

    unsigned long long hashVal = hash(key);

    for(int i = 0; i < size; i++){

        unsigned long long ix = (hashVal + i) % size;
        auto& el = data[ix];

        if(el.value == 0){

            return;

        }

        if(el.key == key){

            el.value = 0;
            return;

        }

    }

}

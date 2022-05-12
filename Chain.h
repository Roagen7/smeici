#pragma once

#define HTABLE_SIZE 10003

#include "List.h"
#include "Pair.h"

#include <cmath>


class HashTable {

private:

    int size;
    List<Pair> *data;


    unsigned long long eval(std::string wd);
    unsigned long long hash(const std::string& pair);

public:

    HashTable(int size = HTABLE_SIZE);
    ~HashTable();


    void add(const std::string key);
    Pair get(const std::string key);

    void remove(const std::string key);

};

HashTable::HashTable(int size): size(size), data(new List<Pair>[size]) {

}

unsigned long long HashTable::hash(const std::string& key) {
    return eval(key) % size;
}

unsigned long long HashTable::eval(std::string wd) {

    unsigned long long ev = 0;

    for(int i = 0; i < wd.length(); i++){

        auto& c = wd[i];
        ev+= pow(255,i) * (unsigned char) c;

    }

    return ev;

}

void HashTable::add(const std::string key) {

    unsigned long long hashVal = hash(key);

    auto& list = data[hashVal];

    for(int i = 0; i < list.len(); i++){

        auto& el = list[i];

        if(el.key == key){

            el.value++;
            return;
        }

    }

    list.Push({key, 1});

}

Pair HashTable::get(const std::string key) {

    unsigned long long hashVal = hash(key);

    auto& list = data[hashVal];

    for(int i = 0; i < list.len(); i++){

        auto& el = list[i];

        if(el.key == key){

            return el;

        }

    }

    return {key, 0};

}

void HashTable::remove(const std::string key) {

    unsigned long long hashVal = hash(key);

    auto& list = data[hashVal];

    for(int i = 0; i < list.len(); i++){

        auto& el = list[i];

        if(el.key == key){

            el.value = 0;

        }

    }

}

HashTable::~HashTable() {

    delete[] data;

}


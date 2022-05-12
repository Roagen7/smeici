#pragma once

template <typename T>
class List {

    public:

        List() {

            head = { T(),nullptr, &tail
            };
            tail = { T(),&head, nullptr
            };


        }

        List(const List& other){

            head = { T(),nullptr, &tail };
            tail = { T(),&head, nullptr };

            for(int i = 0; i < other.len(); i++){

                Push(other[i]);

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


        int len() const{

            auto* current = head.next;
            int l = 0;

            while(current != nullptr){

                current = current->next;
                l++;

            }

            return l - 1;

        }





        void Push(T val) {

            Node* newNode = new Node;
            newNode->val = val;

            newNode->next = &tail;
            newNode->prev = tail.prev;


            tail.prev->next = newNode;
            tail.prev = newNode;


        }


        T Pop() {

            Node* toDelete = tail.prev;
            T valcpy = toDelete->val;

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

        T& operator[](int ix) {

            auto* current = &head;

            for (int i = 0; i <= ix; i++) {

                current = current->next;


            }


            return current->val;


        }


    const T& operator[](int ix) const {

        const auto* current = &head;

        for (int i = 0; i <= ix; i++) {

            current = current->next;


        }

        return current->val;

    }

    private:

        struct Node {

            T val;
            Node* prev;
            Node* next;


        } head, tail;


};
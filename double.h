#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
    public:
        DoubleList() : List<T>() {}

        ~DoubleList(){
            // TODO
        }

        T front(){
            return head->data;
        }

        T back(){
            return tail->data;
        }

        void push_front(T data){
            Node<T>* nuevo= new Node<T>;
            nuevo->data = data;
            nuevo->next = head;
            head = nuevo;
        }

        void push_back(T data){
            Node<T>* nuevo= new Node<T>;
            nuevo->data = data;
            nuevo->prev = tail;
            tail = nuevo;
        }

        T pop_front(){
            if (head ==nullptr && tail== nullptr) exit(0);
            Node<T>* temp = head;
            int valor = temp->data;
            head = head->next;
            delete temp;
            temp= nullptr;
            return valor;
        }

        T pop_back(){
            if (head ==nullptr && tail== nullptr) exit(0);
            Node<T>* temp = tail;
            int valor = temp->data;
            tail = tail->prev;
            delete temp;
            temp= nullptr;
            return valor;
        }

        T insert(T data, int pos){
            if (pos==0){
                push_front(data);
            } else{
                Node<T>* nuevo= new Node<T>{data};
                Node<T>* temp= head;
                int i=0;
                while (i++<pos-1){
                    temp= temp->next;
                }
                nuevo->next = temp->next;
                temp->next = nuevo;
                return nuevo->data;
            }
            return 0;
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            Node<T>* iter = head;

            for (int i = 0; i < pos; i++){
                iter = iter->next;
            }

            return iter->data;
        }

        bool is_empty(){
            return (head ==nullptr);
        }

        int size(){
            int tamanio=0;
            Node<T>* nd = head;
            while (nd != nullptr){
                nd = nd->next;
                tamanio+=1;
            }
            return tamanio;
        }

        void clear(){
            while (head!=nullptr){
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void sort(){
            Node<T>* i, *j;
            for(i = head; i!= nullptr; i = i->next){
                for (j = i->next; j != nullptr ; j = j->next) {
                    if (i->data > j->data){
                        int temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
        }

        bool is_sorted(){
            Node<T>* temp = head;
            bool veri=true;
            if (size()==0){
                return veri;
            }else{
                for (int i = 0; i < size(); i++){
                    if (temp->next->data<temp->data){
                        veri = false;
                        break;
                    }
                }
            }
            return !veri;
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "DoubleList";
        }
};
#endif
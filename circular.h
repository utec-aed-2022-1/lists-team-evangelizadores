#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods

//IDEA: donde se pone el override? en la declaracion o en al definicion o en ambos.
template <typename T>
class CircularList : public List<T> {
    private:
        Node<T>* head;//sentinel
        int nodes; 
    public:
        CircularList() : List<T>() { }

        ~CircularList();

        T front() override;
        T back() override;
        void push_front(T data);
        void push_back(T data);
        T pop_front();
        T pop_back();
        T insert(T data, int pos);
        bool remove(int pos);
};

template<typename T>
CircularList<T>::~CircularList(){
    if(head != nullptr){
        Node<T>* temp1 = head;
        Node<T>* temp2 = head->next;
        while(temp1->next != head && temp2->next != head){
            temp1 = temp2;
            temp2 = temp2->next;
            delete temp1;
        }
        delete temp2;
        delete head;
    }
}

template<typename T>
T CircularList<T>:: front() override{
    return head->next->data;
}
template<typename T>
T CircularList<T>:: back() override{
    return head->prev->data;
}

template<typename T>
void CircularList<T>:: push_front(T data) override {
    Node<T>* nuevo = new Node();
    nuevo->data = data;

    nuevo->next = head->next;
    nuevo->prev = head;
    head->next->prev = nuevo;
    head->next = nuevo;

    ++this->nodes;
}

template<typename T>
void CircularList<T>:: push_back(T data) override {
    Node<T>* nuevo = new Node();
    nuevo->data = data;

    nuevo->prev = head->prev;
    nuevo->next = head;
    head->prev->next = nuevo;
    head->prev = nuevo;

    ++this->nodes;
}
//IDEA: Funcion con 1 elemento, no con 0 lanzar excepcion
template<typename T>
void CircularList<T>:: pop_front() override {
    Node<T>* temp = head->next->next;

    temp->prev = head;
    delete head->next;
    head->next = temp;

    --this->nodes;
}
//IDEA: Funcion con 1 elemento, no con 0 lanzar excepcion
template<typename T>
void CircularList<T>:: pop_back() override {
    Node<T>* temp = head->prev->prev;

    temp->next = head;
    delete head->prev;
    head->prev = temp;

    --this->nodes;
}

//IDEA: lanzar una excepcion si el pos es mayor que nodes. Que quiere que devuelva?
template<typename T>
T CircularList<T>:: insert(T data, int pos){
    Node<T>* temp = head;
    Node<T>* nuevo = new Node();
    int cont = 0;
    nuevo->data = data;

    while(cont < pos){
        temp = temp->next;
        ++cont;
    }

    nuevo->next = temp->next;
    nuevo->prev = temp;

    temp->next->prev = nuevo;
    temp->next = nuevo;
}

//IDEA: excepcion si tiene 0 valores. Que quiere que retorne?
template<typename T>
bool CircularList<T>:: remove(int pos){
    Node<T>* temp = head;
    int cont = 0;

    while(cont < pos){
        temp = temp->next;
        ++cont;
    }

    (temp->next->next)->prev = temp;
    delete temp->next;
    temp->next = (temp->next->next);
}

#endif
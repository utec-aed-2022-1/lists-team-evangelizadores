#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include <stdexcept>
#include "list.h"

using namespace std;

// TODO: Implement all methods

template <typename T>
class CircularList: public list<T> {
private:
    Node<T>* head;//sentinel
    int nodes;
public:
    CircularList(): List<T>(){
        head = new Node<T>();
        head->next = head;
        head->prev = head;
    }

    ~CircularList();

    T front() ;
    T back() ;
    void push_front(T data);
    void push_back(T data);
    T pop_front();
    T pop_back();
    void insert(T data, int pos);
    void remove(int pos);
    T& operator[](int);
    bool is_empty();
    int size();
    void clear();
    bool is_sorted();
    void sort();
    void reverse();
    std::string name();
};

template<typename T>
CircularList<T>::~CircularList(){
    clear();
}

template<typename T>
T CircularList<T>:: front() {
    if(head->next == head)
        exit(0);

    return head->next->data;
}
template<typename T>
T CircularList<T>:: back() {
    if(head->next == head)
        exit(0);

    return head->prev->data;
}

template<typename T>
void CircularList<T>:: push_front(T data)  {
    Node<T>* nuevo = new Node<T>();
    nuevo->data = data;

    nuevo->next = head->next;
    nuevo->prev = head;
    head->next->prev = nuevo;
    head->next = nuevo;

    ++(this->nodes);
}

template<typename T>
void CircularList<T>:: push_back(T data)  {
    Node<T>* nuevo = new Node<T>();
    nuevo->data = data;

    nuevo->prev = head->prev;
    nuevo->next = head;
    head->prev->next = nuevo;
    head->prev = nuevo;

    ++(this->nodes);
}

template<typename T>
T CircularList<T>:: pop_front()  {
    if(head->next == head)
        exit(0);


    T res = head->next->data;

    Node<T>* temp = head->next->next;

    temp->prev = head;
    delete head->next;
    head->next = temp;

    --(this->nodes);
    return res;
}
//IDEA: Funcion con 1 elemento, no con 0 lanzar excepcion
template<typename T>
T CircularList<T>:: pop_back()  {
    if(head->next == head)
        exit(0);

    T res = head->prev->data;
    Node<T>* temp = head->prev->prev;

    temp->next = head;
    delete head->prev;
    head->prev = temp;

    --(this->nodes);

    return res;
}

//IDEA: lanzar una excepcion si el pos es mayor que nodes. Que quiere que devuelva?
template<typename T>
void CircularList<T>:: insert(T data, int pos){
    if(nodes < pos)
        exit(0);


    Node<T>* temp = head;
    Node<T>* nuevo = new Node<T>();
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

    ++(this->nodes);
}

//IDEA: excepcion si tiene 0 valores. Que quiere que retorne?
template<typename T>
void CircularList<T>:: remove(int pos){
    if(nodes < pos)
        exit(0);

    Node<T>* temp = head;
    int cont = 0;

    while(cont < pos){
        temp = temp->next;
        ++cont;
    }

    (temp->next->next)->prev = temp;
    delete temp->next;
    temp->next = (temp->next->next);

    --(this->nodes);
}

//IDEA: Execpciones para asegurar una posicion coherente
template<typename T>
T& CircularList<T>:: operator[](int pos){
    if(nodes < pos || pos < 0)
        exit(0);

    Node<T>* temp = head->next;
    int cont = 0;

    while(cont < pos){
        temp = temp->next;
        ++cont;
    }
    return temp->data;
}

template<typename T>
bool CircularList<T>:: is_empty(){
    return nodes;
}

template<typename T>
int CircularList<T>:: size(){
    return nodes;
}

template<typename T>
void CircularList<T>:: clear(){
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

        head = nullptr;
        nodes = 0;
    }
}


template<typename T>
bool CircularList<T>:: is_sorted(){
    Node<T>* temp = head->next;
    while(temp->next != head){
        if(temp->data > temp->next->data){
            return false;
        }
        temp = temp->next;
    }
    return true;
}

/*
IDEA:
    Una manera seria recorrer la lista y cambiar los prev por next, La idea estaria en como lee un circulo
    puedes recorrerlo de manera horaria o antihoraria.
 */

//Se asume que tiene como minimo un elemento, realizar una excepcion.
template<typename T>
void CircularList<T>:: reverse(){
    if(head->next == head)
        exit(0);

    Node<T>* temp1 = head;
    Node<T>* temp2 = head->next->next;
    while(temp1->next != head && temp2 != head){

        temp2->prev->next = temp1;
        temp1->prev = temp2->prev;

        temp1 = temp2->prev;
        temp2 = temp2->next;
    }
}

template<typename T>
std::string CircularList<T>:: name(){
    return "CircularList";
}

template<typename T>
void CircularList<T>:: sort(){
    //falta implementar
}


#endif
#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            return this->head->data;
        }

        T back() {
            return this->tail->data;
        }

        void push_front(T value) {
            this->nodes++;
            Node<T>* frontadd = new Node<T>(value);
            frontadd->next = this->head;
            this->head->prev = frontadd;
            this->tail->next = frontadd;
            this->head = frontadd;
        }

        void push_back(T value) {
            this->nodes++;
            Node<T>* backadd = new Node<T>(value);
            backadd->prev = this->tail;
            this->tail->next = backadd;
            this->head->prev = backadd;

        }

        void pop_front() {
            this->nodes--;
            this->head = this->head->next;
            delete this->head->prev;
            this->head->prev = this->tail;
            this->tail->next = this->head;
            this->head->prev = this->tail;
        }

        void pop_back() {
            this->nodes--;
            this->tail->prev = this->tail;
            delete this->tail->next;
            this->tail->next = this->head;
            this->head->prev = this->tail;
        }

        T operator[](int index) {
            Node<T>* aux = this->head;
            for(int i = 0;i<index;i++){
                aux = aux->next;
            }
            return aux->data;
        }

        bool empty() {
            return this->nodes==0;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->head->prev = nullptr;
            this->tail->next = nullptr;
            this->head->killSelf();
            this->head = nullptr;
            this->tail = nullptr;
        }

        void sort() {
            Node<T>* aux = this->head;
            int valor;
            for(int i = 0;i<this->size();i++){
                while(aux->next != nullptr){
                    if(aux->data > aux->next->data){
                        valor = aux->data;
                        aux->data = aux->next->data;
                        aux->next->data = valor;
                        aux = aux->next;
                    }else{
                    aux = aux->next;
                }
                }
                aux = this->head;
            }
        }
    
        void reverse() {
            this->head->prev = nullptr;
            this->tail->next = nullptr;
            Node<T>* aux = this->head;

            while(aux !=nullptr){
                Node<T>* auxP = aux->next;
                aux->next=aux->prev;
                aux->prev=auxP;
                auxP=auxP->prev;
            }
            aux=this->head;
            this->head=this->tail;
            this->tail=aux;
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->head);   
        }

        void merge(CircularLinkedList<T> list) {
             while(list.size()!=0){
                push_back(list.front());
                list.pop_front();
            }
        }
};

#endif
#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            return (this->head)->data;
        }

        T back() {
            return (this->tail)->data;
        }

        void push_front(T value) {
            this->nodes++;
            Node<T>* frontadd = new Node<T>(value);
            frontadd->next = this->head;
            (this->head)->prev = frontadd;
            this->head = frontadd;
        }

        void push_back(T value) {
            this->nodes++;
            Node<T>* backadd = new Node<T>(value);
            backadd->prev = this->tail;
            // esto va a dar error en el primer caso
            (this->tail)->next = backadd;
            this->tail = backadd;
        }

        void pop_front() {
            this->nodes--;
            this->head = (this->head)->next;
            delete (this->head)->prev;
            (this->head)->prev = nullptr;
        }

        void pop_back() {
            this->nodes--;
            this->tail = (this->tail)->prev;
            delete (this->tail)->next;
            (this->tail)->next = nullptr;
        }

        T operator[](int index) {
            Node<T>* aux = this->head;
            for(int i = 0;i<index;i++){
                if(aux == nullptr){
                    throw out_of_range("Segmentation Fault");
                }
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
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head,this->tail);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(nullptr,this->tail);
        }

        void merge(LinkedList<T> list) {
            while(list.size()!=0){
                push_back(list.front());
                list.pop_front();
            }
        }
};

#endif
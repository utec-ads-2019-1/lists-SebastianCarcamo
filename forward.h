#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

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
            this->head = frontadd;
        }

        void push_back(T value) {
            this->nodes++;
            Node<T>* backadd = new Node<T>(value);
            backadd->next = this->head;
            this->tail = backadd;
        }

        void pop_front() {
            this->nodes--;
            Node<T>* aux = this->head;
            this->head = (this->head)->next;
            delete aux;
        }

        void pop_back() {
            this->nodes--;
            Node<T>* aux = this->head;
            while((aux->next)->next!=nullptr){
                aux = aux->next;
            }
            delete aux->next;
            aux->next = nullptr;
            this->tail = aux;
        }

        T operator[](int index) {
            Node<T>* aux = this->head;

            for(int i =0;i<index;i++){
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
            Node<T>* current = this->head;
            Node<T>* aux = nullptr;
            Node<T>* next = nullptr;

            while(current!=nullptr){
                next = current->next;
                current->next = aux;
                aux=current;
                current=next;
            }
            this->head = aux;
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            return ForwardIterator<T>(this->head);
        }

	    ForwardIterator<T> end() {
            return nullptr;
        }

        void merge(ForwardList<T> list) {
             while(list.size()!=0){
                push_back(list.front());
                list.pop_front();
            }
        }
};

#endif
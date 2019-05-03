#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
private:
    Node<T>* last;
    public:
        BidirectionalIterator() : Iterator<T>() {};
        
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator(Node<T> *node,Node<T>*last_): Iterator<T>(node){
            last = last_;
        };

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            this->current = other.current;
            return *this;
        }

        bool operator!=(BidirectionalIterator<T> other) {
            return this->current != other.current;
        }

        BidirectionalIterator<T> operator++() {
            this->current = this->current->next;
            return this->current;
        }

        BidirectionalIterator<T> operator--() {
            if(this->current == nullptr){
                this->current = last;
            }else{
                this->current = this->current->prev;
            }
            return *this;
        }

        T operator*() {
            // Falta el caso vacío
            return this->current->data;
        }
};

#endif
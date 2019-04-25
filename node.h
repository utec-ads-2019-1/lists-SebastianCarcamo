#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data_, Node<T>* next_, Node<T>* prev_){
    	data = data_;
    	next = next_;
    	prev = prev_;
    }

    Node(T data_){
    	data = data_;
    	next = nullptr;
    	prev= nullptr;
    }

    Node(T data_ , Node<T>* next_){
    	data = data_;
    	next = next_;
    	prev = nullptr;
    }


    void killSelf() {
    	if(next)
    		next->killSelf();
        delete this;
    }
};

#endif
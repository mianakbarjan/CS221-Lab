#include <iostream>
using namespace std;

template <class T>
class Node {
    public: 
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node (){
        next = prev = nullptr;
    }
    Node (T value){
        next = nullptr;
        data=value;
    }
    
};
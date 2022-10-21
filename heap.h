#include <string>
#include <sstream>
#include <iostream>
#include "exception.h"
#include "header.h"

using namespace std;

template <class T>
class Priority_Queue{
    private:
        T *data;
        int size;
        int count;

    public:
        Priority_Queue(int);
        ~Priority_Queue();

        bool empty() const;
        bool full() const;
        

        int parent(int) const;
        int left(int) const;
        int right(int) const;

        void swap(int, int);
        void pushDown(int);

        //TAREA//
        void push(T);
        void pop();
        T top();
        void empty();
        int sze() const; 

        string toString() const;
};

template <class T>
Priority_Queue<T>::Priority_Queue(int sze){
    size = sze;
    data = new T[size];
    count = 0;
}
template <class T>
Priority_Queue<T>::~Priority_Queue(){
    delete [] data;
    data = NULL;
    size = 0;
    count = 0;
}
template <class T>
bool Priority_Queue<T>::empty() const {
	return (count == 0);
}
template <class T>
bool Priority_Queue<T>::full() const {
	return (count == size);
}
template <class T>
int Priority_Queue<T>::parent(int pos) const{
    return (pos-1)/2;
}
template <class T>
int Priority_Queue<T>::left(int pos) const{
    return (pos * 2) + 1;
}
template <class T>
int Priority_Queue<T>::right(int pos) const{
    return (pos * 2) + 2;
}
template <class T>
void Priority_Queue<T>::swap(int i, int j){
    T aux = data[i];
    data[i] = data[j];
    data[j] = aux;
}
template <class T>
void Priority_Queue<T>::pushDown(int pos){
    int le = left(pos);
    int ri = right(pos);
    int min = pos;

    if (le < count && data[le] > data[min]){
        min = le;
    }
    if (ri < count && data[ri] > data[min]){
        min = ri;
    }

    if(min != pos){
        swap(pos, min);
        pushDown(min);
    }
}
//TAREA//
template <class T>
void Priority_Queue<T>::push(T val){
    int pos;
    if(full()){
        throw Overflow();
    }
    pos = count;
    count++;
    while(pos>0 && val > data[parent(pos)]){
        data[pos] = data[parent(pos)];
        pos = parent(pos);
    }
    data[pos] = val;
}

template <class T>
void Priority_Queue<T>::pop() {
	if (empty()){
		throw NoSuchElement();
	}
	data[0] = data[--count]; // data[0] = data[count]; count--;
	pushDown(0);
}
template <class T>
T Priority_Queue<T>::top(){
    return data[0];
}
template <class T>
void Priority_Queue<T>::empty() {
	count = 0;
}
template <class T>
int Priority_Queue<T>::sze() const{
    return count;
}


template <class T>
string Priority_Queue<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (uint i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
	aux << data[i];
	}
	aux << "]";
	return aux.str();
}
#include "heap.h"

int main(){
    Priority_Queue<int> Heap(10);
    Heap.push(10); 
    cout << Heap.toString();
    Heap.push(8); 
    cout << Heap.toString();
    Heap.push(1); 
    cout << Heap.toString();
    Heap.push(5); 
    cout << Heap.toString();
    Heap.push(13); 
    cout << Heap.toString();
    Heap.push(18);
    cout << Heap.toString();
    cout << endl << "TOP: " << Heap.top() << endl;
    Heap.empty();
    cout << Heap.toString() << endl;
    cout << Heap.sze() << endl;
}
/**
* ECS 60 -- Project 2
* Max PriorityQueue Class IMPLEMENTATION
* Author: Kevin Trujillo && Ella Queen
*
* Implemented as an array-based binary heap with the root node at index 1 of the array.
* The keys are non-negative integers
*/


#include "priorityqueue.h"
#include <iostream>

priorityqueue::priorityqueue(int max_Size) {
    heap_size = 1;
    harr = new int[max_Size];
    harr[0] = 10000000;

}

int priorityqueue::parent(int i) { 

    if (i == 2){
        return 1;
    }
    else{
        return (i)/2;
    }
     
}

// to get index of left child of node at index i
int priorityqueue::left(int i) { return (2*i + 0); }

// to get index of right child of node at index i
int priorityqueue::right(int i) { return (2*i + 1); }

bool priorityqueue::parentBool(int i) { //false if root
    if (i == 1) { //if parent is root
        return false;
    }
    else {
        return true;
    } 
}

// to get index of left child of node at index i
bool priorityqueue::leftBool(int i) { 
    if ((2*i + 0) > heap_size){ //no left child
        return false;
    }
    else {
        return true;
    }
}

// to get index of right child of node at index i
bool priorityqueue::rightBool(int i) {  
    if ((2*i + 1) > heap_size){ //no right child
        return false;
    }
    else{
        return true;
    }
}





//FUNCTIONS TO CHANGE THE PQ-----------------------------------

void priorityqueue::insert(int k){
    if(heap_size == max_Size){
        std::cout<< "PriorityQueue::insert called on full priority queue" << std::endl;
        return;
    }
    
    int i = heap_size ;
    harr[i] = k ;

    

    if (heap_size > 1){
        heapifyDown(1);
        //heapifyUp(heap_size) ;
    } 

    if (k > harr[1] || parentBool(i) == true){ //if max is being inserted 
        heapifyUp(i);
        //heapifyDown(1);
    } 

    heap_size++;

}

void priorityqueue::removeMax(){

    //std::cout << "heap_size before remove max: " << heap_size << std::endl;
    //std::cout << "heap size: " << heap_size << std::endl;
    for (int i = 1; i < heap_size; i++){
        harr[i] = harr[i + 1]; //move all the values over to replace the root node
    }

    //harr[1]=harr[heap_size];

    heap_size--;
    heapifyDown(1);
    

        //std::cout << "heap_size after remove max: " << heap_size << std::endl;
}


void priorityqueue::removeKey(int v) {


    //std::cout << "heap_size before remove key: " << heap_size << std::endl;
    
    bool found = false;
    for (int i = 1; i <= heap_size; i++){
        if(harr[i] == v) {
            found = true;

            if (i == heap_size){
                heap_size--;
                i--;
                return;
             }

            else {
                for (int j = i; j < heap_size; j++){
                harr[j] = harr[j + 1];
                }
                heap_size--;
                i--;

                if (leftBool(i) == true || rightBool(i) == true){
                    heapifyDown(i);
                }
                if (parentBool(i) == true){
                    heapifyUp(i);
                }
            }

            
            
        }
    }



    /*bool found = false ;
    for(int i = 1; i <= heap_size ; ++i){ //possible seg fault
        if (harr[i] == v ){
            found = true;
            if (i == heap_size){
                heap_size--;
                return;
             }
            for(int j = i ; j < heap_size; ++j){
                harr[j] = harr[j+1];
            }
            
               if (((i*2) <= heap_size && rightBool(i) == true) || (leftBool(i) == true && ((i*2)+1) <= heap_size)){
                    heapifyDown(1);
                }

                if (i > 1 && harr[i] > harr[i / 2] && i <= heap_size){
                    heapifyUp(i);
                }
                heap_size--;
                
        }
        //heapifyDown(1) ;
    //std::cout << "heap_size after remove key: " << heap_size << std::endl;
    }*/

    if(!found){
        std::cout<< "PriorityQueue::removeKey " << v <<  " not found" << std::endl;
    }

}

void priorityqueue::change(int k, int newK){

    bool found = false ;
    for(int i = 1; i <= heap_size ; ++i){ //possible seg fault
        if (harr[i] == k ){
            found = true;
            harr[i] = newK ;
            if (rightBool(i) == true || leftBool(i) == true){
                heapifyDown(1);
            }
            if (parentBool(i) == true){
                heapifyUp(i);
            }
        }
    }

    if(!found){
        std::cout<< "PriorityQueue::change key " << k <<  " not found" << std::endl;
        return;
    }



}

void priorityqueue::heapifyDown(int k) { //heapify Down

    int l = left(k);
    int r = right(k);
    int maximum = k;


    if (leftBool(k) == true && l < heap_size && l >= 0 &&harr[l] > harr[maximum]){ //changed this back to max
        maximum = l;
    }

    if (rightBool(k) == true&& r < heap_size && r >= 0 && harr[r] > harr[maximum]){
        maximum = r;
    }

    if (maximum != k){
        //std::swap(harr[k], harr[maximum]);
        //std::cout << "inside swap for heapify down" << std::endl;
        int temp = harr[k];
        harr[k] = harr[maximum];
        harr[maximum] = temp;

        heapifyDown(maximum);
    }
}


void priorityqueue::heapifyUp (int k){

    if(parentBool(k) == true){
        // If-Statment checks if node at index k and its parent violates the heap property
    if(harr[parent(k)] < harr[k] && k != 1){
        // if true, swaps the two 
        //std::swap(harr[k], harr[parent(k)]) ;
        //std::cout << "inside swap for heapify up" << std::endl;
       // std::cout << "paretn: " << parent(k) << std::endl;

        int temp = harr[k];
        harr[k] = harr[parent(k)];
        harr[parent(k)] = temp;

        // then recursivly calls heapifyUP passing the parent node
        heapifyUp(parent(k)) ;
    }
    }

    
    
}

int priorityqueue::get(int k) {
    return harr[k];

}

void priorityqueue::printJSON(){

}

/* COMMENTED OUT SO WE CAN USE PRIORITY QUEUEUEUEUE IN BUILDHEAP
int main(){
    priorityqueue pq(10);

    pq.insert(8);
    pq.insert(24);
    pq.insert(15);
    pq.insert(678);
    pq.insert(50);
    pq.insert(128);

    std::cout <<  pq.get(1) << std::endl;
    std::cout <<  pq.get(2) << std::endl;
    std::cout <<  pq.get(3) << std::endl;
    std::cout <<  pq.get(4) << std::endl;
    std::cout <<  pq.get(5) << std::endl;
    std::cout <<  pq.get(6) << std::endl << std::endl;

    pq.removeMax();

    std::cout <<  pq.get(1) << std::endl;
    std::cout <<  pq.get(2) << std::endl;
    std::cout <<  pq.get(3) << std::endl;
    std::cout <<  pq.get(4) << std::endl;
    std::cout <<  pq.get(5) << std::endl << std::endl;


    pq.removeKey(128);

    std::cout <<  pq.get(1) << std::endl;
    std::cout <<  pq.get(2) << std::endl;
    std::cout <<  pq.get(3) << std::endl;
    std::cout <<  pq.get(4) << std::endl;
    //std::cout <<  pq.get(5) << std::endl << std::endl;

    pq.change(15,60);

    std::cout << std::endl<< pq.get(1) << std::endl;
    std::cout <<  pq.get(2) << std::endl;
    std::cout <<  pq.get(3) << std::endl;
    std::cout <<  pq.get(4) << std::endl;

}

*/
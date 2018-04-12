/**lp
* ECS 60 -- Project 2
* Max PriorityQueue Class
* Author: Kevin Trujillo && Ella Queen
*
* Implemented as an array-based binary heap with the root node at index 1 of the array.
* The keys are non-negative integers
*
*/


#include <iostream>
#include <string>
#include <sstream>
#ifndef PROJ2PRIORITYQUEUE_PRIORITYQUEUE_H
#define PROJ2PRIORITYQUEUE_PRIORITYQUEUE_H


class priorityqueue {
public:


    int *harr; // pointer to array of elements in heap
    int max_Size; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap

    priorityqueue(int max_Size);


    /**
     *
     * @param i
     * @return
     */
    int parent(int i);
    int right(int i) ;
    int left(int i);

    /**
    *
    *
    */
    bool parentBool(int i);
    bool rightBool(int i) ;
    bool leftBool(int i);

    /**
     * Insert the key k into the priority queue. If the priority queue is full and insert is called,
     * print the following error and then exit: "PriorityQueue::insert called on full priority queue".
     * @param k
     */
    void insert(int k);

    /**
     * Remove the maximum key from the priority queue. If the priority queue is empty and removeMax is
     * called, print the following error and then exit: "PriorityQueue::removeMax called on an empty priority queue".
     */
    void removeMax() ;

    /**
     * Remove the key k from the priority queue. If this key does not exist in the priority queue, print
     * the following error and then exit (in this example, k = 45):
     * "PriorityQueue::removeKey key 45 not found".
     * @param k
     */
    void removeKey(int k);

    /**
     * Change the key k to the key newK. If this key does not exist in the priority queue, print
     * the following error and then exit (in this example, k = 63): "PriorityQueue::change key 63 not found".
     * @param k
     * @param newK
     */
    void change(int k, int newK) ;

    /**
     *
     * @param k
     */
    void heapifyDown(int k);

    /**
    * Recursive Heapify-Up Algorithm
    * @param k
    */
    void heapifyUp (int k);


    /**
     * Returns key value.
     *
     * @param k
     * @return
     */
    int get(int k);

    /**
     * 
     *
     * @param k
     * @return
     */
    void swap(int* x, int* y);

    /**
     * 
     *
     * @param k
     * @return
     */
    void printJSON();

    

};



#endif //PROJ2PRIORITYQUEUE_PRIORITYQUEUE_H
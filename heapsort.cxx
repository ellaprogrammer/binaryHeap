//
// Created by Ella Queen on 2/13/18.

//heapsortPQ should be making a new array - wait to do this until have JSON object
//

#include "json.hpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;

void heapifyPQ(int arr[], int n, int i)
{
    //starting at the root (i) **DO WE NEED TO START AT 1 AGAIN? if so i++
    int maxNum = i;
    int left = (2*i + 1);
    int right = (2*i + 2);

    //compare: left greater than root/current max?
    if (left < n && arr[left] > arr[maxNum])
        maxNum = left;

    //compare: is right greater than root/current max?
    if (right < n && arr[right] > arr[maxNum])
        maxNum = right;

    //make the swap so that the max is stored at the root
    if (maxNum != i)
    {
        std::swap(arr[i], arr[maxNum]);
        heapifyPQ(arr, n, maxNum);
    }
}

void heapsortPQ(int arr[], int n)
{
    //create a heap from an array with correct indexes
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyPQ(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        //take out each root and move to the end of the array
        std::swap(arr[0], arr[i]);

        //this recursively goes through each element in the heap
        heapifyPQ(arr, i, 0);
    }
}


int main(int argc, char** argv) {

nlohmann::json jsonObject ; //inputted json file
nlohmann::json sortedSolution ; // the new json file to store the solution
std::vector<int> sampleV;

int * sample;
int sampleNum = 1; //through sample
if (argc > 0){

        std::ifstream file;  
        std::string filename = argv[1];
        std::cout << filename << std::endl;

        file.open(argv[1]);
        if(file.is_open()){
                file >> jsonObject;
                //std::cout<<"in the if" <<std::endl;

        } 
        for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr){
             //std::cout<<"in the if" <<std::endl;
            
            if ((itr.key()) != "metadata"){
                 //std::cout<<"in the if" <<std::endl;
                int sampleSize = jsonObject["metadata"]["arraySize"];
                sample = new int[sampleSize];
                int i = 0;

                for(auto arrayItr = jsonObject[itr.key()].begin(); arrayItr != jsonObject[itr.key()].end(); ++arrayItr, ++i){  //through key values 
                    //store each value from the jsonObject array in sample at i

                    sample[i] = *arrayItr;
                }

                heapsortPQ(sample, sampleSize); //this makes the array a heap and sorts the heap
                sampleV.clear();
                for (int i = 0; i < sampleSize; ++i){ //check that that array is updated correctly
                    //std::cout << sample[i] << std::endl;

                    sampleV.push_back(sample[i]);
                    //std::cout << " " << sampleV[i] << std::endl;

                } 

                sortedSolution["Sample"+std::to_string(sampleNum)] = sampleV;

                //std::cout << "vector: " << sampleV << std::endl;
                //std::cout << "json: " << sortedSolution["Sample"+std::to_string(sampleNum)] << std::endl;          

                sampleNum += 1; 


            }

            sortedSolution["metadata"]["arraySize"] = jsonObject["metadata"]["arraySize"];
            sortedSolution["metadata"]["numSamples"] = jsonObject["metadata"]["numSamples"];
        }

        std::cout << sortedSolution.dump(2) << std::endl;
    }
    
/*
    //sample array
    int * A;
    A = new int [10];
    //print out sample array values

    A[0] = 400;
    A[1] = 70;
    A[2] = 3;
    A[3] = 88;
    A[4] = 400;
    A[5] = 70;
    A[6] = 3;
    A[7] = 88;
    A[8] = 400;
    A[9] = 70;

    for (int i = 0; i < 10; i++){
        //A[i] = i;
        std::cout << A[i] << std::endl;
    }
    printf("\n");


    //call heapSortPQ
    heapsortPQ(A, 10);

    //print out the array to see if the values
        //are in the right order
    for (int i = 0; i < 10; i++){
        std::cout << A[i] << std::endl;
    }

    delete A; //delete pointer to A - keep this as last line

*/

} 

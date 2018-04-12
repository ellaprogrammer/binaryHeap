/**
* ECS 60 -- Project 2
* BuildHeap Executable
* Author: Kevin Trujillo && Ella Queen
*
* This program does the following operations:
*	1) reads a JSON file of heap operations and keys
*	2) executes the heap operations from the JSON file
*	3) prints the priority queue as a JSON object to stdout (uses dump(2))
*/

#include "json.hpp"
#include "priorityqueue.cpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char** argv) {

	// Note: the inputed JSON file will have either (1) or (2):
	// 	1) a key-value pair: "key" and "operation"			
	// 	2) the operation "removeMax"
	// We could either preform each operation as we iterate through the JSON file OR,
	//  store the key-value pairs in a pair of vectors OR an array of pointers for the operatations.....

	// LETS FIRST DO OPERATION 1: read a json file

	nlohmann::json jsonObject ; 		// inputted json file
	nlohmann::json newJSON ; 	        // the new json file to store the solution
	int key, newKey = 0;
	int SIZE = 0; // size of pq in buildheap 

	// Biconditional checking to see if there is an input file passes to the program
	if(argc > 0){
		std::ifstream file;
		file.open(argv[1]);

		// Stores the contents of the inputed file into a JSON Object
		if(file.is_open()){
			file >> jsonObject ;
		}

		// Declares and instatiates a priorityQueue using the maxSize taken from the inputed JSON file
		int sizeOfPQ = jsonObject["metadata"]["maxHeapSize"];
		priorityqueue pq(sizeOfPQ) ;

		// These two loops iterate through each key-value pair in the passed JSON file
		for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr){ // iterates through each KEY
			if(itr.key() != "metadata"){
			for(auto arrayItr = jsonObject[itr.key()].begin(); arrayItr != jsonObject[itr.key()].end(); ++arrayItr){  // iterates through each KEY's VALUE
					

					// For keys: ----------------------
					if(arrayItr.key() == "key"){
						key = arrayItr.value() ;
					}
					if(arrayItr.key() == "newKey"){
						newKey = arrayItr.value() ;
					}

					// For operations: -----------------
					if(arrayItr.key() == "operation"){
						if(arrayItr.value() == "insert"){
							//std::cout<< "In insert IF:" << std::endl;
							pq.insert(key) ;
							++SIZE ;
						}			

						if(arrayItr.value() == "removeMax"){
							//std::cout<< "In removeMax IF:" << std::endl;
							pq.removeMax() ;
							--SIZE ;
						}

						if(arrayItr.value() == "change"){
							//std::cout<< "In change IF:" << std::endl;
							pq.change(key, newKey) ;
						}

						if(arrayItr.value() == "removeKey"){
							//std::cout<< "In removekey IF:" << std::endl;
							pq.removeKey(key) ;
							--SIZE ;
						}
				} // operation if
			} // first for-loop 
			
/*
				for(int i = 1 ; i <= SIZE ; ++i){
					std::cout<< pq.get(i) << std::endl;
				} */
			

			} // if metadata			
		} // second for-loop

	//std::cout << "---------" << std::endl;
	
	for(int i = 1 ; i <= SIZE ; ++i){
		//std::cout<< pq.get(i) << std::endl ;

		// Adding pq to a json file:
		
		newJSON[std::to_string(i)]["key"] =  pq.get(i);

		if(pq.leftBool(i) == true && pq.left(i) <= SIZE){
				newJSON[std::to_string(i)]["leftChild"] = std::to_string(pq.left(i));
			}

		if(pq.rightBool(i) == true && pq.right(i) <= SIZE){							
				newJSON[std::to_string(i)]["rightChild"] = std::to_string(pq.right(i));
			}
		
		if(i >= 1){
			
			if (pq.parentBool(i) == true){
				newJSON[std::to_string(i)]["parent"] = std::to_string(pq.parent(i)) ;
			}
			if(pq.leftBool(i) == true && pq.left(i) <= SIZE){
				newJSON[std::to_string(i)]["leftChild"] = std::to_string(pq.left(i));
			}

			if(pq.rightBool(i) == true && pq.right(i) <= SIZE){							
				newJSON[std::to_string(i)]["rightChild"] = std::to_string(pq.right(i));
			}

		}

		

	}

	// Add metadata:

	newJSON["metadata"]["maxHeapSize"] = jsonObject["metadata"]["maxHeapSize"];
	newJSON["metadata"]["max_size"] = jsonObject["metadata"]["maxHeapSize"];
	newJSON["metadata"]["numOperations"] = jsonObject["metadata"]["numOperations"];
	newJSON["metadata"]["size"] = SIZE ;


	} // end of if(argc > 0)

	std::cout<< newJSON.dump(2) <<std::endl;


} // end of main :-) -------------------------------------------------------------------------------------------------------------------------------

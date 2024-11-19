#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "header.h"


using namespace std;

//Function for linear search
int linearSearchFunction(vector<int> someVector, int value) {
	//Loops through the whole vector or until it finds the value we are looking for
	for (int i = 0; i < size(someVector); i++) {
		//If the value is found, return the value
		if (someVector.at(i) == value) {
			return i;
		}
		else {
			continue;
		}
	}
	//If the value isn't found, tell the user and return 0
	return -1;
}

//Function for binary search
int binarySearch(vector<int> someVector, int high, int low, int value) {
	//While the smallest number is less than or equal to the largest number, keep looping
	while (low <= high) {
		//Setting midpoint each time the loop triggers
		int mid = (high + low) / 2;

		//If mid value equals the value we are searching for, return the value and let the 
		//user know
		if (someVector.at(mid) == value) {
			return mid;
		}
		//If the value is larger than our mid value, set low to our mid value plus one
		if (someVector.at(mid) < value) {
			low = mid + 1;
		}
		//If the value we are searching for is less than the high value, set our new high value to 
		//mid minus once, ignoring the whole right side of the divided vector
		else {
			high = mid - 1;
		}
	}
	//If the value is not found, alert the user and return -1
	return -1;

}
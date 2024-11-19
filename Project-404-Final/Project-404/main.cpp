#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "header.h"
#include <random>

using namespace std;

int main() {

	int const ITERATIONS = 2000; // how many tests
	int const RANGE = 175000; //range of randomly generated numbers *** Make sure this matches input file

	srand(time(0));

	ofstream linearOutFile;
	ofstream binaryOutFile;
	ifstream inFile;

	vector<int> data;
	string tempString;
	int singleNumber;
	int numberToFind = 0;
	int result = 0;

	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<long long unsigned> distribution(0, RANGE);

	linearOutFile.open("linearOutFile.txt", std::ios::app); //std::ios::app flag to append to file
	binaryOutFile.open("binaryOutFile.txt", std::ios::app);
	inFile.open("input/input175000.txt");
	if (inFile.is_open()) {
		while (getline(inFile, tempString)) {
			stringstream ss(tempString);
			string tempNumber;
			while (getline(ss, tempNumber, ',')){
				data.push_back(stoi(tempNumber));
			}
		}
	}
	for (int i = 0; i < ITERATIONS; i++) {
		numberToFind = distribution(generator);
		cout << "Trying to find number " << numberToFind << "..." << endl;
		auto start = chrono::high_resolution_clock::now();
		result = linearSearchFunction(data, numberToFind);
		auto end = chrono::high_resolution_clock::now();
		cout << "--- Linear Search ---" << endl;
		if (result == -1) {
			cout << numberToFind << " not found in this data" << endl;
		}
		else {
			cout << "Value " << numberToFind << " found in this list of numbers" << " at index " << result << "." << endl;
		}
		
		chrono::duration<double, milli> duration1 = end - start;
		cout << "Time ran (In milliseconds): " << duration1.count() << " ms" << endl;
	
		int low = 0;
		int high = data.size() - 1;
		cout << "--- Binary Search ---" << endl;
		auto start2 = chrono::high_resolution_clock::now();
		result = binarySearch(data, high, low, numberToFind);
		auto end2 = chrono::high_resolution_clock::now();
		if (result == -1) {
			cout << numberToFind << " not found in this data" << endl;
		}
		else {
			cout << "Value " << numberToFind << " found in this list of numbers" << " at index " << result << "." << endl;
		}
		chrono::duration<double, milli> duration2 = end2 - start2;
		cout << "Time ran (In milliseconds): " << duration2.count() << " ms" << endl;
		cout << endl;
		linearOutFile << "\n" << data.size() << "," << duration1.count();
		binaryOutFile << "\n" << data.size() << "," << duration2.count();
	}


	return 0;
}
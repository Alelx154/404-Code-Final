#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include "header.h"


using namespace std;

int main() {

	ofstream outFile;
	ifstream inFile;

	vector<int> data;
	string tempString;
	int singleNumber;
	int numberToFind = 0;

	outFile.open("outputFile.txt");
	inFile.open("inputValues.txt");

	if (inFile.is_open()) {
		cout << "Enter a value to find" << endl;
		cin >> numberToFind;

		while (getline(inFile, tempString)) {
			stringstream ss(tempString);
			string tempNumber;
			while (getline(ss, tempNumber, ',')){
				data.push_back(stoi(tempNumber));
			}
		}
	}
	auto start = chrono::high_resolution_clock::now();
	linearSearchFunction(data, numberToFind);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration1 = end - start;
	std::cout << "Time ran (In milliseconds): " << duration1.count() << " ms" << std::endl;
	
	int low = data.at(0);
	int high = data.at(data.size() - 1);

	auto start2 = chrono::high_resolution_clock::now();
	binarySearch(data, high, low, numberToFind);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration2 = end2 - start2;
	std::cout << "Time ran (In milliseconds): " << duration2.count() << " ms" << std::endl;

	return 0;
}
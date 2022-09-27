/***************************
Wesly Maulsby
C++ Fall 2022
Lab 3
User and File Input/Output
Learn the basics of Input and Output with user input and file input
*****************************/

//include necessary libraries
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// creates the int values for the initial input
int value1;
int value2;
int value3;
int value4;
 
// creates the float values of the initial input minus the mean
float value1M;
float value2M;
float value3M;
float value4M;

// creates the float values of the initial inputs minus the mean squared
float value1Msq;
float value2Msq;
float value3Msq;
float value4Msq;

// creates the float value of the sum of the last 4 values squared
float allSQ;

// creates the float value of the last value divided by 4
float allSQdiv4;

// creates the floats to store mean and standard deviation
float mean;
float stanDev;

// function prototypes
void inputValues();
void meanCalc();
void stanDevCalc();
void outputMeanSTD();
void inputOutput2file();

// main function
int main()
{
	inputValues();
	meanCalc();
	stanDevCalc();
	outputMeanSTD();
	
	inputOutput2file();

	return 0;
}

// scans input file (inMeanStd.dat) and uses the values inside and outputs their mean and standard deviation to the output file (outMeanStd.dat)
void inputOutput2file()
{
	ifstream inFile;
	inFile.open("inMeanStd.dat");
	inFile >> value1;
	inFile >> value2;
	inFile >> value3;
	inFile >> value4;

	meanCalc();
	stanDevCalc();

	ofstream outFile;
	outFile.open("OutMeanStd.dat");
	outFile << "Mean: " << mean << "\n" << "Standard Deviation: " << stanDev;
}

// outputs the mean and standard deviation to the command window
void outputMeanSTD()
{
	cout << "The mean of these Values is: " << mean;
	cout << endl << "The standard deviation is: " << stanDev;
}

// calculates the standard deviation with the results of meanCalc() and inputValues()
void stanDevCalc()
{
	value1M = value1 - mean;
	value2M = value2 - mean;
	value3M = value3 - mean;
	value4M = value4 - mean;

	value1Msq = value1M * value1M;
	value2Msq = value2M * value2M;
	value3Msq = value3M * value3M;
	value4Msq = value4M * value4M;

	allSQ = value1Msq + value2Msq + value3Msq + value4Msq;

	allSQdiv4 = allSQ / 4;

	stanDev = sqrt(allSQdiv4);
}

// calculates the mean using the values from inputValues()
void meanCalc()
{
	mean = (value1 + value2 + value3 + value4) / 4.0;
	
}

// recieves input from the user that is used throughout the program
void inputValues()
{
	cout << "Input your first value: ";
	cin >> value1;

	cout << "Input your second value: ";
	cin >> value2;

	cout << "Input your third value: ";
	cin >> value3;

	cout << "Input your fourth value: ";
	cin >> value4;
}
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

ifstream Input; //File Input
ofstream Output; //File Output

const int arraySize = 32; //Standard size for array
int arrayAddress = 0; //Beginning of array address
int n = 0; //Counter

unsigned char Array[arraySize]; //Internal byte array


int main(int ArgumentA, char* ArgArray[])
{
	Input.open(ArgArray[1]); //Opens an command line argument array for input file
	while (true)
	{
		unsigned char c;
		Input.read((char *)Array, 16); //Used to get arguements from external source
		Array[c]; //Store in array
		cout << "0x" << setw(3) << (int)arrayAddress << "   "; //Used to output the starting 3 digits in hex
		arrayAddress += 16; //Increment the array by 16
		for (int i = 0; i <= arraySize; i++)
		{
			if (i % 16 == 0)
			{
				cout << hex << setw(2) << setfill('0') << (int)arrayAddress << "  "; //Output arrayAddress in hexadecimal
			}
		}
		cout << " " << endl;
		Input.close();
		return 0;
	}
}
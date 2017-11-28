#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<stdlib.h>


using namespace std;

ifstream Input; //File Input

const int arraySize = 150; //Standard size for array
int arrayAddress = 0; //Beginning of array address 
unsigned char Array[arraySize]; //Internal byte array

int main(int ArgumentA, char* ArgArray[])
{
	int counter = 0; //Used to count #of loops corresponding for # of instructions
	int i = 0; //Used to iterate through the array to determine what the instruction is
	Input.open(ArgArray[1]); //Opens an command line argument array for input file
	int counter2 = atoi(ArgArray[2]); //Number of instructions to read
	Input.read((char *)Array, (counter2 * 6)); //Used to get arguements from external source
	while (counter < counter2) //Using 3rd array argument to limit how many times the program runs
	{
		counter++; //Increment count of instructions being read
		cout << "0x" << setw(3) << (int)arrayAddress << "   "; //Outputs the 3 digit value in Hex
		if ((int)Array[i] == 0x00)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "HALT" << endl; //1 byte instruction HALT
			arrayAddress += 1;
			i += 1;
		}
		else if ((int)Array[i] == 0x10)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "NOP" << endl; //1 Byte instruction NOP
			i += 1;
			arrayAddress += 1;
		}
		if ((int)Array[i] == 0x90)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "RET" << endl; //1 Byte instruction RET
			i += 1;
			arrayAddress += 1;
		}
		else if ((int)Array[i] == 0x20)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "MOV" << endl; //2 byte instruction MOV
			i += 2;
			arrayAddress += 2;
		}
		else if ((int)Array[i] == 0x30)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "MOV" << endl; //6 byte instruction imediate MOV 
			i += 6;
			arrayAddress += 6;
		}
		else if ((int)Array[i] == 0x40)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "LDR " << endl; //2 byte instruction LDR
			i += 2;
			arrayAddress += 2;
		}
		else if ((int)Array[i] == 0x41)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "STR" << endl; // 2 byte instruction STR
			i += 2;
			arrayAddress += 2;
		}
		else if ((int)Array[i] == 0x60)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "ADD" << endl; //2 Byte Operator instruction ADD
			i += 2;
			arrayAddress += 2;
		}
		else if ((int)Array[i] == 0x61)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "SUB" << endl; //2 Byte Operator instruction SUB
			i += 2;
			arrayAddress += 2;
		}
		else if ((int)Array[i] == 0x62)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "AND" << endl; //2 Byte Operator instruction AND
			i += 2;
			arrayAddress += 2;
		}
		else if ((int)Array[i] == 0x63)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "EOR" << endl; //2 Byte Operator instruction EOR
			i += 2;
			arrayAddress += 2;
		}
		else if ((int)Array[i] == 0x70)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "EQ" << endl; //5 byte instruction EQ
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x71)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "NE" << endl; //5 byte instruction NE
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x72)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "CS/HS" << endl; //5 byte instruction CS/HS
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x73)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "CC/LO" << endl; //5 byte instruction CC/LO
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x74)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "MI" << endl; //5 byte instruction MI
			arrayAddress += 5;
			i += 5;
		}
		else if ((int)Array[i] == 0x75)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "PL" << endl; //5 byte instruction PL
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x76)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "VS" << endl; //5 byte instruction VS
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x77)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "VC" << endl; //5 byte instruction VC
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x78)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "HI" << endl; //5 byte instruction HI
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x79)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "LS" << endl; //5 byte instruction LS
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x7A)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "GE" << endl; //5 byte instruction GE
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x7B)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "LT" << endl; //5 byte instruction LT
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x7C)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "GT" << endl; //5 byte instruction GT
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x7D)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "LE" << endl; //5 byte instruction LE
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x7E)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "AL" << endl; //5 byte instruction AL
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0x80)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "CALL" << endl; //5 byte instruction CALL
			i += 5;
			arrayAddress += 5;
		}
		else if ((int)Array[i] == 0xA0)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "PUSH" << endl; //2 byte instruction PUSH
			i += 2;
			arrayAddress += 2;
		}
		else if ((int)Array[i] == 0xB0)
		{
			cout << hex << setw(2) << setfill('0') << (int)Array[i] << "  ";
			cout << "POP" << endl; //2 byte instruction POP
			i += 2;
			arrayAddress += 2;
		}
	}
	Input.close();
	return 0;
}
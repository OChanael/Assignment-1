#include "assignment1.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>

using namespace std; // simplify code

int main(int arc, char** argv)
{
	ofstream out; // outgoing information
	ifstream in; // incoming info

	out.open("OriChanael.out"); // opening output file
	if (out.is_open())
	{
		out << "Results:";
	}
	else
	{
		cout << "Cannot open file" << endl; // error message
	}
	while (true)
	{
		cout << "Please enter the file name of the .txt file you wish to use." << endl; // inputting .txt file
		string file_name;
		cin >> file_name;

		in.open(file_name.c_str()); // opens .txt file to begin reading

		NucleotideComputation n; // calling class 

		n.SetString(in); // performs file reading
		n.FileComps(out); // outputs basic math
		n.NucleotideProbability(out); // outputs probability computations
		n.GuassianDistribution(out); // outputs guassian distribution

		in.close(); // closes .out file

		bool again = true; // bool for while loop on new lists
		while (again)
		{
			cout << "Do you want to use another list? (Y/N)" << endl;
			string input;
			cin >> input;

			if ((input == "n") || (input == "N")) // if no new list
			{
				out.close(); // exits code
				return 0;
			}
			else if ((input == "y") || (input == "Y")) // returns to start
			{
				break;
			}
			else
			{
				cout << "Please enter a valid response." << endl; // error message
				continue;
			}
		}
	}
	return 0;
}

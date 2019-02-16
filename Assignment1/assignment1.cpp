#define _USE_MATH_DEFINES // required for M_PI to function
#include <math.h> // includes math computations
#include "assignment1.h" // connects to .h file with class and variables
#include <iostream> // required for streams
#include <string> // required for STL strings
#include <fstream> // required for streams
#include <stdlib.h> // required for rand and RAND_MAX functions



NucleotideComputation::NucleotideComputation() //constructor
{
	string nucleotides; // declaring base values for variables from .h file
	int count_line;
	float nucleotide_count = 0.0;
	float sum = 0.0;
	float mean = 0.0;
	float variance = 0.0;
	float std_dev = 0.0;
	float nucleotide_total = 0.0;
	float probA = 0;
	float probC = 0;
	float probT = 0;
	float probG = 0;
}

NucleotideComputation::~NucleotideComputation() //destructor
{

}
void NucleotideComputation::SetString(ifstream& inStream) // reading .txt file
{
		count_line = 0;
		char x;
		while (!inStream.eof()) // reading based on line skipping to count lines
		{
			if (x == '\n')
			{
				count_line++;
			}
			inStream.get(x);
			nucleotides += x;
			
		}
}
	//math start
void NucleotideComputation::FileComps(ofstream& outStream) // acessing FileComps function from .h file
{
	float nucleotide_count = 0;
	int count = 0;

	for (int i = 0; i < nucleotides.size(); ++i) //sum and mean
	{
		if (nucleotides[i] != '\n')
		{
			nucleotide_total += 1;
		}
		else 
		{
			count += 1;
			if (count == count_line) // calculating mean
			{
				sum = nucleotide_total;
				mean = sum / count_line;
				count = 0;
				break;
			}
		}
	}
	outStream << "\nSum: " << sum << endl; // printing sum to .out file
	outStream << "Mean: " << mean << endl; // printing mean to .out file

	for (int j = 0; j < nucleotides.size(); ++j) //variance and std_dev
	{
		if (nucleotides[j] != '\n') // adds to count until only \n is detected
		{
			nucleotide_count += 1;
		}
		else
		{
			variance += pow((nucleotide_count - mean), 2); // calculating variance
			nucleotide_count = 0;
			count += 1;
			if (count == count_line) // calculating std_dev
			{
				variance = variance / nucleotide_total;
				std_dev = sqrt(variance);
				break;
			}
		}
	}
	outStream << "Variance: " << variance << endl; // printing variance to .out file
	outStream << "Standard Deviation: " << std_dev << endl; // printing std_dev to .out file
}

void NucleotideComputation::NucleotideProbability(ofstream& outStream)
{
	float probAA = 0.0; // writing out variables and base value for nucleotide pairs
	float probAC = 0.0;
	float probAT = 0.0;
	float probAG = 0.0;

	float probCA = 0.0;
	float probCC = 0.0;
	float probCT = 0.0;
	float probCG = 0.0;

	float probTA = 0.0;
	float probTC = 0.0;
	float probTT = 0.0;
	float probTG = 0.0;

	float probGA = 0.0;
	float probGC = 0.0;
	float probGT = 0.0;
	float probGG = 0.0;

	for (int i = 0; i < nucleotides.size(); ++i) // starting probability computations
	{
		if ((nucleotides[i] == 'a') || (nucleotides[i] == 'A')) // a nucleotides start, checking for 'A' probability
		{
			probA += 1; 

			if (nucleotides[i + 1] != '\n') // checking if the strings are not odd numbered
			{
				nucleotide_count += 1;

				if ((nucleotides[i + 1] == 'a') || (nucleotides[i + 1] == 'A')) // AA pair
				{
					probAA += 1;
				}
				else if ((nucleotides[i + 1] == 'c') || (nucleotides[i + 1] == 'C')) // AC pair
				{
					probAC += 1;
				}
				else if ((nucleotides[i + 1] == 't') || (nucleotides[i + 1] == 'T')) // AT pair
				{
					probAT += 1;
				}
				else if ((nucleotides[i + 1] == 'g') || (nucleotides[i + 1] == 'G')) // AG pair
				{
					probAG += 1;
				}
			}
		}
		else if ((nucleotides[i] == 'c') || (nucleotides[i] == 'C')) // C nucleotides start
		{
			probC += 1;
			if (nucleotides[i + 1] != '\n')
			{
				nucleotide_count += 1;
				if ((nucleotides[i + 1] == 'a') || (nucleotides[i + 1] == 'A')) // CA pair
				{
					probCA += 1;
				}
				else if ((nucleotides[i + 1] == 'c') || (nucleotides[i + 1] == 'C')) // CC pair
				{
					probCC += 1;
				}
				else if ((nucleotides[i + 1] == 't') || (nucleotides[i + 1] == 'T')) // CT pair, rush B knives only
				{
					probCT += 1;
				}
				else if ((nucleotides[i + 1] == 'g') || (nucleotides[i + 1] == 'G')) // CG pair
				{
					probCG += 1;
				}
			}
		}
		else if ((nucleotides[i] == 't') || (nucleotides[i] == 'T')) // T nucleotides start
		{
			probT += 1;
			if (nucleotides[i + 1] != '\n')
			{
				nucleotide_count += 1;
				if ((nucleotides[i + 1] == 'a') || (nucleotides[i + 1] == 'A')) // TA pair
				{
					probTA += 1;
				}
				else if ((nucleotides[i + 1] == 'c') || (nucleotides[i + 1] == 'C')) // TC pair
				{
					probTC += 1;
				}
				else if ((nucleotides[i + 1] == 't') || (nucleotides[i + 1] == 'T')) // TT pair
				{
					probTT += 1;
				}
				else if ((nucleotides[i + 1] == 'g') || (nucleotides[i + 1] == 'G')) // TG pair
				{
					probTG += 1;
				}
			}
		}
		else if ((nucleotides[i] == 'g') || (nucleotides[i] == 'G')) // G nucleotides start
		{
			probG += 1;
			if (nucleotides[i + 1] != '\n') 
			{
				nucleotide_count += 1;
				if ((nucleotides[i + 1] == 'a') || (nucleotides[i + 1] == 'A')) // GA pair
				{
					probGA += 1;
				}
				else if ((nucleotides[i + 1] == 'c') || (nucleotides[i + 1] == 'C')) // GC pair
				{
					probGC += 1;
				}
				else if ((nucleotides[i + 1] == 't') || (nucleotides[i + 1] == 'T')) // GT pair
				{
					probGT += 1;
				}
				else if ((nucleotides[i + 1] == 'g') || (nucleotides[i + 1] == 'G')) // GG pair
				{
					probGG += 1;
				}
			}
		}
	}
	// converting to percentages
	probA = (probA / nucleotide_count) * 100; // single nucleotides
	probC = (probC / nucleotide_count) * 100;
	probT = (probT / nucleotide_count) * 100;
	probG = (probG / nucleotide_count) * 100;
	
	probAA = (probAA / nucleotide_count) * 100; // A nucleotide pairs
	probAC = (probAC / nucleotide_count) * 100;
	probAT = (probAT / nucleotide_count) * 100;
	probAG = (probAG / nucleotide_count) * 100;
	
	probCA = (probCA / nucleotide_count) * 100; // C nucleotide pairs
	probCC = (probCC / nucleotide_count) * 100;
	probCT = (probCT / nucleotide_count) * 100;
	probCG = (probCG / nucleotide_count) * 100;
	
	probTA = (probTA / nucleotide_count) * 100; // T nucleotide pairs
	probTC = (probTC / nucleotide_count) * 100;
	probTT = (probTT / nucleotide_count) * 100;
	probTG = (probTG / nucleotide_count) * 100;
	
	probGA = (probGA / nucleotide_count) * 100; // G nucleotide pairs
	probGC = (probGC / nucleotide_count) * 100;
	probGT = (probGT / nucleotide_count) * 100;
	probGG = (probGG / nucleotide_count) * 100;

	// print percentages to .out file
	outStream << "\nSingle Nucleotides:" << endl;
	outStream << "A: " << probA << "%" << endl;
	outStream << "C: " << probC << "%" << endl; 
	outStream << "T: " << probT << "%" << endl; 
	outStream << "G: " << probG << "%" << endl;
	outStream << "\nA Nucleotide Pairs:" << endl;
	outStream << "AA: " << probAA << "%" << endl; 
	outStream << "AC: " << probAC << "%" << endl;
	outStream << "AT: " << probAT << "%" << endl;
	outStream << "AG: " << probAG << "%" << endl;
	outStream << "\nC Nucleotide Pairs:" << endl; 
	outStream << "CA: " << probCA << "%" << endl; 
	outStream << "CC: " << probCC << "%" << endl; 
	outStream << "CT: " << probCT << "%" << endl; 
	outStream << "CG: " << probCG << "%" << endl;
	outStream << "\nT Nucleotide Pairs: " << endl; 
	outStream << "TA: " << probTA << "%" << endl; 
	outStream << "TC: " << probTC << "%" << endl; 
	outStream << "TT: " << probTT << "%" << endl; 
	outStream << "TG: " << probTG << "%" << endl;
	outStream << "\nG Nucleotide Pairs:" << endl; 
	outStream << "GA: " << probGA << "%" << endl; 
	outStream << "GC: " << probGC << "%" << endl; 
	outStream << "GT: " << probGT << "%" << endl; 
	outStream << "GG: " << probGG << "%" << endl;
	outStream << "\n";
}

void NucleotideComputation::GuassianDistribution(ofstream& outStream) // running guassian distribution for 1000 new lines
{
	double a = ((float)rand() / (RAND_MAX)); // setting up variables for equation
	double b = ((float)rand() / (RAND_MAX));

	double C = (sqrt(-2 * log(a)))*(cos(2*M_PI*b)); // equation from hint in instructions, thanks
	double D = (std_dev * C) + mean; // the other equation from hint in instructions

	for (int i = 0; i < 1000; ++i) // loop 1000 times
	{
		for (int j = 0; j < D; ++j) // for loop iterates size of D
		{
			double range = rand() % 100; // printing new strings based on probability values generated previously via a range
			if (range <= probA) 
			{
				outStream << "A";
			}
			else if (range <= (probC + probA)) 
			{
				outStream << "C";
			}
			else if (range <= (probT + probC + probA)) 
			{
				outStream << "T";
			}
			else if (range <= 100) 
			{
				outStream << "G";
			}
		}
		outStream << "\n"; // skipping line after new string is printed
	}
	probA = 0; // resetting values for if user wants to run another file
	probC = 0;
	probT = 0;
	probG = 0;
	std_dev = 0;
}

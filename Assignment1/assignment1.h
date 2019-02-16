#include <iostream>
#include <fstream>
#include <string>

using namespace std; // simplifies code

class NucleotideComputation 
{
private: // private variables for math comps
	string nucleotides;
	int count_line;
	float nucleotide_count;
	float sum;
	float mean;
	float variance;
	float std_dev;
	float nucleotide_total;
	float probA;
	float probC;
	float probT;
	float probG;

public:
	NucleotideComputation(); // for constructor
		~NucleotideComputation(); // for destructor

	void SetString(ifstream& inStream); //input from file
	void FileComps(ofstream& outStream); //math computation for sum, mean, variance, and std_dev
	void NucleotideProbability(ofstream& outStream); //probability of nucelotide types
	void GuassianDistribution(ofstream& outStream); //new sequences
};

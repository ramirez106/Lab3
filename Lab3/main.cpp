/*
	Carlos Ramirez
	C++ Fall 2022
	Due: September 28
	Lab 3 User and File I/O
	Write an interactive C++ program that computes and outputs the mean and
	population standard deviation of a set of four integers that are inputted by a file called
	“inMeanStd.dat” and the user (should handle both). Although the individual values are
	integers, the results are floating-point values. Be sure to use proper formatting and
	appropriate comments in your code. Provide appropriate prompts to the user. The
	output should be to the screen for the user inputted values and to a file called
	“outMeanStd.dat”. The programs output should be labeled clearly and formatted
	neatly. You must calculate the mean and standard deviation in separate functions.
*/

#include <iostream>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

float mean(int one, int two, int three, int four);
float sd(int one, int two, int three, int four, float mean);

int main()
{
	int one, two, three, four;

	ifstream infile;
	ofstream outfile;

	int fInput1, fInput2, fInput3, fInput4;

	string inputfile = "inMeanStd.dat";
	string outputfile = "outMeanStd.dat";

	infile.open(inputfile);
	outfile.open(outputfile);

	//brings the file input and puts it into integers
	infile >> fInput1 >> fInput2 >> fInput3 >> fInput4;

	//outputs directions to the screen
	cout << "Input four numbers, with a space inbetween each number" << endl;
	cin >> one >> two >> three >> four; //assigns integers to input

	/*displays the mean and standard deviation from the input and and input file
	on the screen, the first three lines refer to user input and the second three lines
	refer to the file input
	*/
	cout << "The mean of your numbers is:" << " " << mean(one, two, three, four) << endl;
	cout << "The standard deviation of your numbers is:" << " " << sd(one, two, three, four, mean(one, two, three, four)) << endl;
	cout << "\n" << "The numbers inputted by the files are:" << " " << fInput1 << "," << " " << fInput2 << "," << " " << fInput3 << "," << " " << fInput4 << endl;
	cout << "The mean of the input file is:" << " " << mean(fInput1, fInput2, fInput3, fInput4) << endl;
	cout << "The standard deviation of the file input is:" << " " << sd(fInput1, fInput2, fInput3, fInput4, mean(fInput1, fInput2, fInput3, fInput4)) << endl;

	// closes the input and output file
	infile.close();
	outfile.close();

	return 0;

}

//function definition of our mean
float mean(int one, int two, int three, int four)
{
	return float(one + two + three + four) / float(4);
}

//This is the function definition of standard deviation
float sd(int one, int two, int three, int four, float mean)
{
	return sqrt((pow((one - mean), 2) + pow((two - mean), 2) + pow((three - mean), 2) + pow((four - mean), 2)) / 4);
}
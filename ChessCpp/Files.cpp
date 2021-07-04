#include "Files.h"


bool fileWrite(string newLine)
{
	bool writing = false;

	// Open the file for writing always at the end of it.
	ofstream myfile("example.bin", ios::out | ios::app);		

	if (myfile.is_open())		// Write operations only done in case of succesful opening.
	{
		myfile << newLine << "\n";
		writing = true;
	}
	else
	{
		cout << "Unable to open file \n";
		writing = false;
	}

	// Close the file.
	myfile.close();

	return writing;
}


bool fileRead(string info)
{
	bool reading = false;
	string line;

	// Open the file for reading.
	ifstream myfile("example.bin", ios::in);

	if (myfile.is_open())		// Reading operations only done in case of succesful opening.
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		reading = true;
	}
	else
	{
		cout << "Unable to open file \n";
		reading = false;
	}

	// Close the file.
	myfile.close();

	return reading;
}
#include "Files.h"


bool fileWrite(std::string newLine)
{
	bool writing = false;

	// Open the file for writing always at the end of it.
	std::ofstream myfile("example.bin", std::ios::out | std::ios::app);

	if (myfile.is_open())		// Write operations only done in case of succesful opening.
	{
		myfile << newLine << "\n";
		writing = true;
	}
	else
	{
		std::cout << "Unable to open file \n";
		writing = false;
	}

	// Close the file.
	myfile.close();

	return writing;
}


bool fileRead(std::string info)
{
	bool reading = false;
	std::string line;

	// Open the file for reading.
	std::ifstream myfile("example.bin", std::ios::in);

	if (myfile.is_open())		// Reading operations only done in case of succesful opening.
	{
		while (getline(myfile, line))
		{
			std::cout << line << '\n';
		}
		reading = true;
	}
	else
	{
		std::cout << "Unable to open file \n";
		reading = false;
	}

	// Close the file.
	myfile.close();

	return reading;
}
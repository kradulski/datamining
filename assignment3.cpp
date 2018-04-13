#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<vector<int>> getTrainingData(char ** datafile);
vector<vector<int>> getTestData(char ** datafile);

int main(int argc, char** file)
{
	vector<vector<int>> trainingData;
	trainingData = getTrainingData(file);
	getTestData(file);

	int max = 0;
	int sum = 0;
	int j = 0;
	for (int i = 0; i < (int) trainingData.size(); ++i)
	{
		sum += trainingData[i][2];
		if (trainingData[i][2] > max)
			max = sum;
	}
	
	return 0;
}


//Puts the training data into a vector of vector ints
//Each "row" in the vector contains one label and it's attributes
//labels are stored in the 0th spot, +1 as 1, -1 as 0
//All numbers are parsed in order with the colons removed so attribute value pairs
//will be organized such as: vector[0] == label, vector[1] + vector[2] are
//attribute/value pair 1, etc..
vector<vector<int>> getTrainingData(char ** datafile)
{
	fstream train;
	vector<vector<int>> data;
	vector<int> row;
	string line;
	string tempString;
	train.open(datafile[1]);

	while (getline(train, line))
	{
		if (line[0] == '+')
			row.push_back(1);
		else
			row.push_back(0);
		int i = 3;
		while (i < (int) line.size())
		{
			while (line[i] != ':')
			{
				tempString += line[i];
				++i;
			}
			row.push_back(stoi(tempString));
			tempString.clear();
			++i;
			while (line[i] != ' ')
			{
				tempString += line[i];
				++i;
				if (i == (int) line.size())
					break; 
			}
			row.push_back(stoi(tempString));
			tempString.clear();
			++i;
		}
		data.push_back(row);
		row.clear();
	}

	train.close();
	train.clear();
	/*for (int i = 0; i < (int) data.size(); ++i)
	{
		for (int j = 0; j < (int) data[i].size(); ++j)
		{
			cout << data[i][j];
			cout << ' ';
		}
		cout << endl;
	}*/
	return data;
}

//Puts the training data into a vector of vector ints
//Each "row" in the vector contains one label and it's attributes
//labels are stored in the 0th spot, +1 as 1, -1 as 0
vector<vector<int>> getTestData(char ** datafile)
{
	fstream train;
	vector<vector<int>> data;
	vector<int> row;
	string line;
	string tempString;
	train.open(datafile[2]);

	while (getline(train, line))
	{
		if (line[0] == '+')
			row.push_back(1);
		else
			row.push_back(0);
		int i = 3;
		while (i < (int) line.size())
		{
			while (line[i] != ':')
			{
				tempString += line[i];
				++i;
			}
			row.push_back(stoi(tempString));
			tempString.clear();
			++i;
			while (line[i] != ' ')
			{
				tempString += line[i];
				++i;
				if (i == (int) line.size())
					break; 
			}
			row.push_back(stoi(tempString));
			tempString.clear();
			++i;
		}
		data.push_back(row);
		row.clear();
	}

	train.close();
	train.clear();
	/*for (int i = 0; i < (int) data.size(); ++i)
	{
		for (int j = 0; j < (int) data[i].size(); ++j)
		{
			cout << data[i][j];
			cout << ' ';
		}
		cout << endl;
	}*/
	return data;
}

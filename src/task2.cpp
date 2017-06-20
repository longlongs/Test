#include "iostream"
#include <ctime>
#include <time.h>
#include <vector>
#include "string"
#include "fstream" 
#include <omp.h>
using namespace std;
int Generator(void)
{
	srand((unsigned)time(0));
	//initialize default character set
	int set_size = 52;
	char *character_set = new char[set_size];
	for (int i = 0; i < 26; i++)
	{
		character_set[i] = i + 65;//initialize A-Z
		character_set[i+26] = i + 97;//initialize a-z
	}

	FILE *output_file = fopen("../file/output.txt", "w");
	FILE *summary_file = fopen("../file/Generator_summary.txt", "w");
	//create strings
	int key=-1;
	int min_length, max_length;
	double RAM = 1<<31;//twice the amount of RAM
	cout << "if you want to exit,please input -1,else input other key" << endl;
	cin >> key;
	time_t start, end;
	while (key != -1)
	{
		//user input
		cout << "please input the min length of strings" << endl;
		cin >> min_length;
		cout << "please input the max length of strings" << endl;
		cin >> max_length;
		if (min_length > max_length || min_length)
		{
			cout << "min length > max length or length > RAM*2" << endl;
			fclose(output_file);
			exit(0);
		}
		start = time(NULL);
		//create
		vector<int>character_length_arr;//save every character length
		vector<char*> string_arr;
		int area = max_length - min_length;
		int progress = 0;
		int string_count = 0;
//using openmp to 
#pragma omp parallel for
		for (int using_ram = 0; using_ram < RAM; string_count++)
		{
			int character_length = rand() % area + min_length;
			using_ram += character_length;
			character_length_arr.push_back(character_length);
			string_arr.push_back(new char[character_length]);
			for (int character_count = 0; character_count < character_length; character_count++)
			{
				string_arr[string_count][character_count] = character_set[rand() % set_size];
			}
		}
		//output
		for (int string_id = 0; string_id < string_count; string_id++)
		{
			for (int character_count = 0; character_count < character_length_arr[string_id]; character_count++)
			{
				fprintf(output_file, "%c", string_arr[string_id][character_count]);
			}
			fprintf(output_file, "\n");
		}
		end = time(NULL);
		fprintf(summary_file, "using time is :%ld\n",end-start);
		fprintf(summary_file, "using openmp for multi-threading\n");
		//user input
		cout << "if you want to exit,please input -1,else input other key" << endl;
		cin >> key;
	}
	fclose(output_file);
	return 0;
}
void  expensiveFunc()
{
	clock_t now = clock();

	while (clock() - now < 10);
}
int Processor(void)
{
	time_t start, end;
	string file_name;
	cout << "please input the file name" << endl;
	cin >> file_name;
	start = time(NULL);
	ifstream input_file(file_name);
	vector<vector<string>>string_arr(52);
	int string_count = 0;
	//load file
	while(!input_file.eof())
	{
		string str;
		input_file >> str;
		int ascii = (int)str[0];//sort the alphabetically
		if (ascii < 97)
		{
			string_arr.at(ascii - 65).push_back(str);//sort A-Z
		}
		else
		{
			string_arr.at(ascii - 71).push_back(str);//sort a-z
		}
		string_count++;
		cout.width(3);
		cout << "progress: " << string_count << endl;
		expensiveFunc();
	}
	//output
	FILE *output_file = fopen("../file/output.txt", "w");
	FILE *summary_file = fopen("../file/Processor_summary.txt", "w");
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < string_arr[i].size(); j++)
		{
			fprintf(output_file, "%s\n", string_arr.at(i).at(j).c_str());
			expensiveFunc();
		}	
	}
	end = time(NULL);
	fprintf(summary_file, "using time is :%ld\n", end - start);
	return 0;
}
int main(void)
{
	Generator();
	Processor();
}
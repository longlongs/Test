#include "iostream"
#include <ctime>
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
	//create strings
	int string_num=-1;
	int min_length, max_length;
	cout << "please input the number of strings,if you want to exit,please input -1" << endl;
	cin >> string_num;
	while (string_num != -1)
	{
		//user input
		cout << "please input the min length of strings" << endl;
		cin >> min_length;
		cout << "please input the max length of strings" << endl;
		cin >> max_length;
		if (min_length > max_length)
		{
			cout << "min length > max length" << endl;
			fclose(output_file);
			exit(0);
		}
		//create
		int *character_length_arr = new int[string_num];//save every character length
		char **string_arr = new char*[string_num];
		int area = max_length - min_length;
		for (int string_count = 0; string_count < string_num; string_count++)
		{
			int character_length = rand() % area + min_length;
			character_length_arr[string_count] = character_length;
			string_arr[string_count] = new char[character_length];
			for (int character_count = 0; character_count < character_length; character_count++)
			{
				string_arr[string_count][character_count] = character_set[rand() % set_size];
			}
		}
		//output
		fprintf(output_file, "%d\n", string_num);
		for (int string_count = 0; string_count < string_num; string_count++)
		{
			for (int character_count = 0; character_count < character_length_arr[string_count]; character_count++)
			{
				fprintf(output_file, "%c", string_arr[string_count][character_count]);
				cout<<string_arr[string_count][character_count];
			}
			fprintf(output_file, "\n");
			cout << endl;
		}
		//user input
		cout << "please input the number of strings,if you want to exit,please input -1" << endl;
		cin >> string_num;
	}
	fclose(output_file);
	return 0;
}
int Processor(void)
{
	FILE *input_file = fopen("../file/input.txt", "r");
	fseek(input_file, 0L, SEEK_END);
	int size = ftell(input_file);
	char *string_arr = new char[size];
	int string_count = 0;//save the number of  characters
	//load file
	for(int character_count = 0; character_count < size; character_count++)
	{
		fscanf(input_file, "%c", &string_arr[string_count]);
		string_count++;
	}

	//sort
	int sort_arr[52];
	memset(sort_arr, 0, sizeof(int) * 52);
	for (int character_count = 0; character_count < string_count; character_count++)
	{
		int ascii = (int)string_arr[character_count];//get the ascii of character
		if (ascii < 97)
		{
			sort_arr[ascii - 65]++;//sort A-Z
		}
		else
		{
			sort_arr[ascii - 71]++;//sort a-z
		}
		cout << "progress: " << character_count * 100 / string_count << "%" << endl;
	}

	//output
	FILE *output_file = fopen("../file/output.txt", "w");
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < sort_arr[i]; j++)
		{
			if (i < 26)
			{
				fprintf(output_file, "%c", j+65);
			}
			else
			{
				fprintf(output_file, "%c", j + 71);
			}
		}	
	}
	return 0;
}
int main(void)
{
	Generator();
	Processor();
}
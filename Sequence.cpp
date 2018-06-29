#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include"Sequence.h"

using namespace std;

Sequence::Sequence(string filename)
{
	ifstream infile;
	infile.open(filename.data());
	if (!infile)
	{
		cerr << "File could not be opened!" << endl;
		exit(EXIT_FAILURE);
	}
	char c;
	while (!infile.eof())
	{
		infile >> c;
		if (c != '\n')
		{
			file1 += c;
		}
	}
}
				
int Sequence::length()
{
	return file1.length();
	}

int Sequence::numberOf(char base)
{
	int sum = 0;
	for (int i = 0; i < file1.length(); i++)
	{
		if (file1[i] == base)
		{
			sum++;
		}
	}
	return sum;
	}

string Sequence::longestConsecutive()
{
	long long max = 0;
	long long current = 0;
	char letter;
	for (int i = 0; i < file1.length(); i++)
	{
		if (file1[i] == file1[i + 1])
		{
			current++;
		}
		else {
		if (current > max)
		{
			max = current; letter = file1[i];

		}
		if (current == max)
		{
			max = current;
		}
		current = 0;
	}	
	}
	string cst;
	for (int j = 0; j < max; j++)
	{
		cst += letter;
		
	}
	return cst;
}

int compare(char *p, char *q) 
{
	   int i = 0;
	   while (*p && (*p++ == *q++))
	      ++i;
    return i;

}

int pstrcmp(const void *p1, const void *p2) {
	return strcmp(*(char* const *)p1, *(char* const*)p2);
}
	char store[12000000], *store2[12000000];
string Sequence::longestRepeated() 
{

	string maxt;
	    int  n = 0;
		long long  i = 0;long long temp = 0;
	    long long maxlen = 0, maxi = 0;
	for(i = 0;i < file1.length();i++)
	{store2[n] = &store[n];
	store[n] = file1[i];	
	n++;
	}
	     store[n] = '\0';

	     qsort(store2, n, sizeof(char*), pstrcmp);
		 for (i = 0; i < n - 1; ++i) {
			 temp = compare(store2[i], store2[i + 1]);
			 if (temp > maxlen) {
				 maxlen = temp;
				 maxi = i;

			 }
		 }
				for (i = 0; i<maxlen; ++i)
					maxt += store2[maxi][i];
				return maxt;
	}

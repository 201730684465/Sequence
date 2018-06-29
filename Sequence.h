#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
class Sequence
{
public:
	Sequence(std::string filename);
	int length();
	int numberOf(char base);
	std::string longestConsecutive();
	std::string longestRepeated();
private:
	std::string file1;
	
};
#endif


#include<iostream>
#include"Sequence.h"
#include<string>

using namespace std;
int main()
{
	Sequence a("dna.txt");
	cout << "length:" << a.length() << endl;
	cout << "A:" << a.numberOf('A') <<endl;
	cout << "T:" << a.numberOf('T') << endl;
	cout << "C:" << a.numberOf('C') << endl;
	cout << "G:" << a.numberOf('G') <<endl;
	cout << a.longestConsecutive() << endl;
	cout << a.longestRepeated() << endl;
	return 0;
}

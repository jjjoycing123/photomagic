#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class LFSR {
	public:
		LFSR(string seed, int t);		//Constructor
		int step();
		int generate(int k);
		unsigned get_size_of_resgister() {return size_of_register;}
		~LFSR();

		friend ostream& operator<< (ostream& out, LFSR& l);

	private:
		string s;
		vector<bool> lfsr_vec;
		unsigned tap;
		unsigned int size_of_register;
};

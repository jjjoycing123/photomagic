#include "LFSR.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//Constructor definition. Need to do the XOR operation.
LFSR::LFSR(string seed, int t){
	tap = t;
	size_of_register = seed.size();

if(size_of_register <= 32){
	//Creates an int bit_string out of the string seed.
	for(unsigned int j = 0; j < size_of_register; j++){

		if(seed.at(j) == '1'){
			lfsr_vec.push_back(true);
		}
		else if(seed.at(j) == '0'){
			lfsr_vec.push_back(false);
		}
	}
 }
}

LFSR::~LFSR(){
}
//function step definition. Shifts the bit_string one position to the left.
int LFSR::step(){

		//If else statements to catch edge cases.
		if(size_of_register == 0){
			return -1;
		}
		else if(size_of_register > 32){
			return -1;
		}
		else if(tap > 1 && tap>= size_of_register){
			return -1;
		}

		//XOR variables
		bool first;
	  bool last = lfsr_vec.at(0);
  	unsigned size_of_bitstring = lfsr_vec.size();

		//Catch size 1 LFSR's
		if(size_of_bitstring == 1 && tap == 1){
			size_of_bitstring = 2;
			//XOR operation for size 1 bit strings
			first = lfsr_vec.at(size_of_bitstring - 1 - tap);
			last = (first ^ last);
			return last;
		}

		//XOR operation
  	first = lfsr_vec.at(size_of_bitstring - 1 - tap);
  	last = (first ^ last);

  	//Shift operation
  	for(unsigned i = 0; i < (size_of_bitstring - 1); i++){
  		lfsr_vec.at(i) = lfsr_vec.at(i+1);
  	}
  	lfsr_vec.at(size_of_bitstring - 1) = last;

  	return last;
}

int LFSR::generate(int k){
	if(size_of_register == 0){
		return -1;
	}
	else if(size_of_register > 32){
		return -1;
	}
	else if(tap > 1 && tap>= size_of_register){
		return -1;
	}

	int num_generated = 0;

	for(int i = 0; i < k; i++){
		num_generated*=2;
		num_generated+=this->step();
	}
	return num_generated;
}
ostream& operator<<(ostream& out, LFSR& l){

	//Catch edge cases
	if(l.size_of_register == 0){
		out << "Empty";
	}
	else if(l.size_of_register > 32){
		out << "Register too large";
	}
	else if(l.tap > 1 && l.tap>= l.size_of_register){
		out << "Tap is out of range";
		return out;
	}

	for(unsigned i = 0; i < l.lfsr_vec.size(); i++){
		if(l.lfsr_vec.at(i) == true){
			out << 1;
		}
		else if(l.lfsr_vec.at(i) == false){
			out << 0;
		}
	}
	return out;
}

#include "LFSR.hpp"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <bits/stdc++.h> 
//using namespace std;


int main(){

	

	LFSR example2("01101000010", 10);
	int num = example2.step();
	std::cout << example2 << " " << num << endl;


	/*
	LFSR example("01101000010", 8);
	
	
	 num = example.step();
	 std::cout << example << " " << num << endl;
	 num = example.step();
	 std::cout << example << " " << num << endl;
	 num = example.step();
	 std::cout << example << " " << num << endl;
	 num = example.step();
	 std::cout << example << " " << num << endl;
	 num = example.step();
	 std::cout << example << " " << num << endl;
	 num = example.step();
	 std::cout << example << " " << num << endl;
	 num = example.step();
	 std::cout << example << " " << num << endl;
	 num = example.step();
	 std::cout << example << " " << num << endl;
	 num = example.step();
	 std::cout << example << " " << num << endl;
	 num = example.step();
	 std::cout << example << " " << num << endl;
		
	*/

	//Generate example. 
	/*
	num = example.generate(5);
	cout << example << " " << num << endl;
	num = example.generate(5);
	cout << example << " " << num << endl;
	num = example.generate(5);
	cout << example << " " << num << endl;
	num = example.generate(5);
	cout << example << " " << num << endl;
	num = example.generate(5);
	cout << example << " " << num << endl;
	num = example.generate(5);
	cout << example << " " << num << endl;
	num = example.generate(5);
	cout << example << " " << num << endl;
	num = example.generate(5);
	cout << example << " " << num << endl;
	num = example.generate(5);
	cout << example << " " << num << endl;
	num = example.generate(5);
	cout << example << " " << num << endl;
	*/


	return 0;
}
// Multi Input
// 10.20.2021
// Amir Afunian

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// Takes decimal, hexadecimal, and octal integers as input and outputs as decimal
int main() {
	vector<int> store;
	vector<string> original;
	vector<string> basename;
	string base;
	string temp;
	int input;
	cout << "Enter integers along with their suffixes: ";
	getline(cin, temp);
	istringstream is{ temp };
	istringstream iss{ temp };
	while (iss >> base) original.push_back(base);
	for (int i = 0; i < original.size(); ++i) {
		if (original[i][0] == '0' && (original[i][1] == 'x' || original[i][1] == 'X'))
			basename.push_back("hexadecimal");
		else if (original[i][0] == '0') basename.push_back("octal");
		else basename.push_back("decimal");
	}
	is.unsetf(ios::dec);
	is.unsetf(ios::hex);
	is.unsetf(ios::oct);
	while (is >> input) {
		store.push_back(input);
	}
	for (int i = 0; i < store.size(); ++i) {
		cout << original[i] << ' ' << basename[i] << " converts to " << store[i] << " in decimal." << '\n';
	}

	return 0;
}
#include <iostream>
#include <set>
#include <string>
#include <hash_map>
using namespace std;

int main() {

	set<string> s;
	set<string>::iterator i;

	s.insert("Hello");
	s.insert("World");
	s.insert("Diary");

	for (i = s.lower_bound("Diary"); i != s.upper_bound("World"); i++)
		cout << *i << endl;

	return 0;
}
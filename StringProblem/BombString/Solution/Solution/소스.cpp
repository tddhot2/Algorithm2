#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	vector<string> vec;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		vec.push_back(str);
	}

	char ans_char;
	int ans_size;

	for (int i = 0; i < n; i++) {
		string reverse_str = vec[i];

		for (int i = 0; i < reverse_str.size() / 2; i++) {
			char temp = reverse_str.at(i);
			reverse_str[i] = reverse_str[reverse_str.size() - 1 - i];
			reverse_str[reverse_str.size() - 1 - i] = temp;
		}

		for (int j = 0; j < n; j++) {
			if (reverse_str.compare(vec[j]) == 0) {
				ans_size = vec[j].size();
				ans_char = vec[j].at(vec[j].size() / 2);
			}
		}
	}

	if (n == 1)
		cout << vec[0].size() << " " << vec[0].at(vec[0].size() / 2) << endl;
	else
		cout << ans_size << " " << ans_char << endl;

	return 0;
}
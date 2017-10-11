#include <iostream>
#include <vector>
using namespace std;

// 스티커 배열
vector<int> vec;

int Solution(int start, int now,int sum) {
	if ((now + 2) % vec.size() != start)
		Solution(start, now + 2, sum + vec[now]);

	if ((now + 2) % vec.size() != start)
		Solution(start, now + 2, sum + vec[now]);
}

int main() {
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(4);
}
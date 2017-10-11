#include<string>
#include<vector>
#include<iostream>
using namespace std;

// 암호를 해독한 문자열을 저장할 변수
string answer = "";

// 매개인자로 전달되는 암호문을 라이브러리의 처음부터 끝까지 문자열 비교를 통해 answer에 해독한 대문자를 추가
void check_library(vector<string> library, string alphabet) {
	int j;
	for (j = 0; j<library.size(); j++) {
		// 라이브러리에서 암호문을 추출한다.
		string compare = "";

		// 라이브러리에서 암호문 추출하여 비교한다.
		for (int k = 2; k<library[j].size(); k++) {
			compare += library[j].at(k);
		}

		// 라이브러리의 암호문과 비교하여 0일 경우, answer에 추가
		if (alphabet.compare(compare) == 0) {
			answer += library[j].at(0);
			break;
		}
	}

	if (j == library.size())
		answer += "?";
}

class Solution {
public:
	string solution(vector<string> library, string message) {

		string alphabet = "";
		// message 전체 문자열 중 띄워쓰기 전까지의 값을 string에 저장
		for (int i = 0; i<message.length(); i++) {

			if (message.at(i) == ' ') {
				// 띄어쓰기를 만났으면 해당 값 전까지 alphbet을 library에서 찾고,
				// 있으면 answer에 추가, 없으면 ?를 추가
				check_library(library, alphabet);

				// 검사 완료후 다음 암호문을 받기위해 문자열 초기화
				alphabet = "";
			}
			else {
				alphabet += message.at(i);
			}
		}

		//마지막은 한번더 붙여줘서 검사
		check_library(library, alphabet);

		return answer;
	}
};
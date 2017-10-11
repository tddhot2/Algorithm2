#include<string>
#include<vector>
#include<iostream>
using namespace std;

// ��ȣ�� �ص��� ���ڿ��� ������ ����
string answer = "";

// �Ű����ڷ� ���޵Ǵ� ��ȣ���� ���̺귯���� ó������ ������ ���ڿ� �񱳸� ���� answer�� �ص��� �빮�ڸ� �߰�
void check_library(vector<string> library, string alphabet) {
	int j;
	for (j = 0; j<library.size(); j++) {
		// ���̺귯������ ��ȣ���� �����Ѵ�.
		string compare = "";

		// ���̺귯������ ��ȣ�� �����Ͽ� ���Ѵ�.
		for (int k = 2; k<library[j].size(); k++) {
			compare += library[j].at(k);
		}

		// ���̺귯���� ��ȣ���� ���Ͽ� 0�� ���, answer�� �߰�
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
		// message ��ü ���ڿ� �� ������� �������� ���� string�� ����
		for (int i = 0; i<message.length(); i++) {

			if (message.at(i) == ' ') {
				// ���⸦ �������� �ش� �� ������ alphbet�� library���� ã��,
				// ������ answer�� �߰�, ������ ?�� �߰�
				check_library(library, alphabet);

				// �˻� �Ϸ��� ���� ��ȣ���� �ޱ����� ���ڿ� �ʱ�ȭ
				alphabet = "";
			}
			else {
				alphabet += message.at(i);
			}
		}

		//�������� �ѹ��� �ٿ��༭ �˻�
		check_library(library, alphabet);

		return answer;
	}
};
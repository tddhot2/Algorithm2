#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Answer;


int main(int argc, char** argv)
{
	int T, test_case;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;

		// �ش� �׽�Ʈ���̽��� ���ڿ�
		string str;
		cin >> str;

		int temp = 0;

		int idx = 0;
		int before_idx = 0;

		while (idx != str.size()) {
			if ((str[idx] == '('&&str[idx + 1] == ')') || (str[idx] == '{'&&str[idx + 1] == '}') || (str[idx] == '['&&str[idx + 1] == ']')) {
				temp += 2;
				str.erase(idx, 2);
				idx = before_idx;
				cout << "��ȣ �¾� : " << temp << endl;
			}
			else {
				cout << "��ȣ Ʋ�� ��������� temp : " << temp << endl;
				if (Answer < temp)
					Answer = temp;
				temp = 0;
				before_idx = idx++;
			}
			cout << str << endl;
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
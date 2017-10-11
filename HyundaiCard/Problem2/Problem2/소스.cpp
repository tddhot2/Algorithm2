#include<vector>
#include<iostream>
using namespace std;

// ���ְ� �Ұ����� �ҷ� ����� ��
#define INF 1001

// Memoization Array
int dp[50][1000][2];

// �ִ� ������ ���������� �����
int MaxVolume;

// �־��� ���� ������ ����
int NumberOfSongs;

// ������ � �������� ��, �ִ밪 �񱳸� ���� ����
int ans = -1;

// �� ����� ���������� �����Ͽ� ���ȣ�� �Ű����� ������ ����
vector<int> songs;

int DynamicPrograming(int now, int volume) {

	// now-1���� ���޵� volume�� �ִ� ������ �Ѱų�, 0 �̸��� ��� �� �̻� ����� ���� �� �ʿ� ����
	if (volume > MaxVolume || volume < 0) {
		return INF;
	}

	if (now == NumberOfSongs) {
		if (ans<volume) {
			ans = volume;
		}
		return volume;
	}

	// �ø��ų� �����ų� �� ���� ����� ��
	// �ش� ��� ������ ���̴� ���
	if (dp[now][volume][0] != -1) {
		return dp[now][volume][0];
	}
	else {
		dp[now][volume][0] = DynamicPrograming(now + 1, volume + songs[now]);
	}

	// �ش� ��� ������ ���ߴ� ���
	if (dp[now][volume][1] != -1) {
		return dp[now][volume][1];
	}
	else {
		dp[now][volume][1] = DynamicPrograming(now + 1, volume - songs[now]);
	}
}

class Solution {
public:
	int solution(vector<int> volumes, int beginVolume, int maxVolume) {
		// Initialzing dp array
		for (int i = 0; i<50; i++) {
			for (int j = 0; j<1000; j++) {
				for (int k = 0; k<2; k++) {
					dp[i][j][k] = -1;
				}
			}
		}

		// �������� ����
		MaxVolume = maxVolume;
		NumberOfSongs = volumes.size();
		for (int i = 0; i<volumes.size(); i++) {
			songs.push_back(volumes[i]);
		}

		DynamicPrograming(0, beginVolume);
		return ans;
	}
};
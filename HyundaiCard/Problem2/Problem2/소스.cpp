#include<vector>
#include<iostream>
using namespace std;

// 연주가 불가능한 불륨 경우의 수
#define INF 1001

// Memoization Array
int dp[50][1000][2];

// 최대 볼륨을 전역변수로 재대입
int MaxVolume;

// 주어진 곡의 개수를 대입
int NumberOfSongs;

// 마지막 곡에 도착했을 때, 최대값 비교를 위한 변수
int ans = -1;

// 곡 목록을 전역변수로 선언하여 재귀호출 매개인자 전달을 줄임
vector<int> songs;

int DynamicPrograming(int now, int volume) {

	// now-1에서 전달된 volume이 최대 볼륨을 넘거나, 0 미만일 경우 더 이상 경우의 수를 볼 필요 없음
	if (volume > MaxVolume || volume < 0) {
		return INF;
	}

	if (now == NumberOfSongs) {
		if (ans<volume) {
			ans = volume;
		}
		return volume;
	}

	// 올리거나 내리거나 두 가지 경우의 수
	// 해당 곡에서 볼륨을 높이는 경우
	if (dp[now][volume][0] != -1) {
		return dp[now][volume][0];
	}
	else {
		dp[now][volume][0] = DynamicPrograming(now + 1, volume + songs[now]);
	}

	// 해당 곡에서 볼륨을 낮추는 경우
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

		// 전역변수 대입
		MaxVolume = maxVolume;
		NumberOfSongs = volumes.size();
		for (int i = 0; i<volumes.size(); i++) {
			songs.push_back(volumes[i]);
		}

		DynamicPrograming(0, beginVolume);
		return ans;
	}
};
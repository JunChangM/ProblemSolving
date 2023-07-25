#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	int N;
	cin >> N;
	cin.ignore();

	vector<pair<int, int>> temp;

	for (int i = 0; i < 26; i++) {
		temp.push_back({ i,0 });
	}

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		int t = 1;
		for (int k = str.size() - 1; k >= 0; k--) {
			temp[str[k] - 'A'].second += t;
			t *= 10;
		}

	}

	sort(temp.begin(), temp.end(), comp);

	int answer = 0;
	int maxnum = 9;
	for (int i = 0; i < 10; i++) {
		int a = temp[i].second;
		answer += a * maxnum--;
	}

	cout << answer;

	return 0;
	
}


/*
단어 수학 N개의 단어 (1 <= N <= 10)
1. 등장하는 알파벳 10개에 대하여 모두 대입을 해본다. =>  (완전탐색)
공간 : 최대 길이 8자리 * 10개의 단어 => 80 byte의 공간 
시간 : 10! = 3,628,800 * 80 = 3억 => 3초로 시간 초과가 될 것 같지만 들어온다.
=> 재귀를 이용해 모든 경우를 확인하고 가장 큰 값을 고르면 해결 가능하다.

2. Greedy
알파벳 개수가 정해지면, 그 개수만큼 큰 수에서 사용한다.

3. 가중치를 이용한다.
A=12314;
B=12313;
A기 더 가중치가 높으니까 9
*/

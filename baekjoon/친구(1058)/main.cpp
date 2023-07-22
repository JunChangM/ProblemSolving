#include <iostream>
#include <vector>


using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> map;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		map.push_back(temp);
	}

	int m = 0;
	for (int i = 0; i < N; i++) {
		vector<int> person(N, 0);
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'Y') {
				person[j] = 1;
				for (int k = 0; k < N; k++) {
					if (map[j][k] == 'Y') {
						person[k] = 1;
					}
				}
			}
		}

		int s = 0;
		for (int j : person) {
			s += j;
		}

		if (s > m) {
			m = s;
		}

	}
	if (m > 0) m -= 1; // A -> B -> A 를 통해서 들어온 자기 자신 제거
	cout << m << endl;

}

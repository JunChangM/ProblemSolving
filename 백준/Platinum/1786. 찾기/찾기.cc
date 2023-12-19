#include <iostream>
#include <string>
#include <vector>
using namespace std;
string text;
string p;
vector<int> v;

// https://mocha-bro.tistory.com/61
vector<int> makeTable() {
	int pSize = p.length();
	vector<int> table(pSize, 0); // 접두사와 접미사가 일차하는 최대 길이
	int j = 0; // 접두사, i가 접미사
	for (int i = 1; i < pSize; i++) {
		// 앞에 같은 값이 존재했으나, 이후 패턴이 맞지 않으면 j-1번째의 값으로 돌아감
		// 접두사와 접미사가 갖지 않으니 접두사가 다시 한칸 후진
		while (j > 0 && p[i] != p[j]) {
			j = table[j - 1];
		}

		if (p[i] == p[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	getline(cin, text);
	getline(cin, p);
	int j = 0, leng = text.length(), pleng = p.size();
	vector<int> table = makeTable();
	for (int i = 0; i < leng; i++) {
		while (j > 0 && text[i] != p[j]) {
			j = table[j - 1];
		}
		if (text[i] == p[j]) {
			j++;
			if (j == pleng) {
				v.push_back(i - j + 2);
				j = table[j - 1];
			}
		}
	}
	
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}

	return 0;
}

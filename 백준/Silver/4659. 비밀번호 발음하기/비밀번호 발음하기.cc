#include <iostream>
#include <string.h>
using namespace std;
string str;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (cin >> str && str.compare("end") != 0) {
		int flag1 = 0, flag2 = 0, flag3 = 0;
		for (int i = 0; i < str.size(); i++) {
			if (flag1 == 0) {
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') flag1 = 1;
			}
			if (flag2 == 0 && i != 0) {
				if (str[i] != 'e' && str[i] != 'o' && str[i - 1] == str[i]) {
					flag2 = 1;
					break;
				}
			}
			if (flag3 == 0 && i > 1) {
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
					if (str[i - 1] == 'a' || str[i - 1] == 'e' || str[i - 1] == 'i' || str[i - 1] == 'o' || str[i - 1] == 'u') {
						if (str[i - 2] == 'a' || str[i - 2] == 'e' || str[i - 2] == 'i' || str[i - 2] == 'o' || str[i - 2] == 'u') {
							flag3 = 1;
							break;
						}
					}
				}
				if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
					if (str[i - 1] != 'a' && str[i - 1] != 'e' && str[i - 1] != 'i' && str[i - 1] != 'o' && str[i - 1] != 'u') {
						if (str[i - 2] != 'a' && str[i - 2] != 'e' && str[i - 2] != 'i' && str[i - 2] != 'o' && str[i - 2] != 'u') {
							flag3 = 1;
							break;
						}
					}
				}
			}
		}
		if (flag1 == 1 && flag2 == 0 && flag3 == 0) cout << '<' << str << '>' << " is acceptable.\n";
		else cout << '<' << str << '>' << " is not acceptable.\n";
	}
	
	return 0;
}	
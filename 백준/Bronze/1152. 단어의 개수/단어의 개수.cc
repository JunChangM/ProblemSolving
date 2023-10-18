#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    getline(cin, str);
    int count = 0;
    bool space = false;
    if (!str.empty()) {
        count = 1;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                count++;
        }
        if (str[0] == ' ')
            count--;
        if (str[str.length() - 1] == ' ')
            count--;
    }
    cout << count;
    return 0;
}
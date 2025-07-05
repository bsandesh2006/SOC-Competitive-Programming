#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;
    int n = input.length();

    stack<int> openPos;
    vector<int> validLen(n, 0);
    int longest = 0, count = 0;

    for (int i = 0; i < n; ++i) {
        if (input[i] == '(') {
            openPos.push(i);
        } else if (input[i] == ')') {
            if (!openPos.empty()) {
                int openIndex = openPos.top();
                openPos.pop();
                validLen[i] = i - openIndex + 1;
                if (openIndex > 0) validLen[i] += validLen[openIndex - 1];

                if (validLen[i] > longest) {
                    longest = validLen[i];
                    count = 1;
                } else if (validLen[i] == longest) {
                    count++;
                }
            }
        }
    }

    if (longest == 0) count = 1;
    cout << longest << " " << count << endl;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Round-half-to-even manually (banker’s rounding)
double round_half_even(double x) {
    double y = floor(x * 1e6 + 0.5);
    // check for tie (.5 case)
    if (fabs(x * 1e6 + 0.5 - y - 0.5) < 1e-8) {
        if (fmod(y, 2) != 0) y -= 1;  // if odd, round down to even
    }
    return y / 1e6;
}

int main() {
    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) cin >> r[i];

    double expected = 0.0;
    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            int ra = r[a], rb = r[b];
            double sum = 0;
            for (int x = 1; x <= ra; ++x) {
                sum += min(x - 1, rb);
            }
            expected += sum / (ra * rb);
        }
    }

    cout << fixed << setprecision(6) << round_half_even(expected) << endl;
}

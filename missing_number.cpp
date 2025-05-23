#include <iostream>
#include <vector>
using namespace std;

long long find_missing_num(long long n , vector<long long> nums){
    long long total = 0;
    for (auto& num : nums) {
        total += num;
    }

    long long expected_sum = (n * (n + 1)) / 2;
    return expected_sum - total;
}

int main() {
    long long n;
    cin >> n;

    vector<long long> nums(n - 1);
    for (long long i = 0; i < n - 1; i++) {
        cin >> nums[i];
    }

    long long missing_num = find_missing_num(n, nums);
    cout << missing_num << endl;
    return 0;
}

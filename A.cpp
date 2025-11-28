#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 20;

void numOfDivs() {
    // numbers of divisors for every elements in an array
    vector<int> num_of_divisors(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            num_of_divisors[j]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << i << " - " << num_of_divisors[i] << endl;
    }
    cout << endl;
}

void sumOfDivs() {
    // sum of divisors for every elements in an array
    vector<int> sum_of_divisors(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            sum_of_divisors[j] += i;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << i << " - " << sum_of_divisors[i] << endl;
    }
    cout << endl;
}

void spfOfArray() {
    // spf for every elements in an array
    vector<int> spf(N + 1);
    for (int i = 2; i <= N; i++) spf[i] = i;

    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            spf[j] = min(spf[j], i);
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << i << " - " << spf[i] << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif

    // numOfDivs();
    // sumOfDivs();
    // spfOfArray();

    return 0;
}

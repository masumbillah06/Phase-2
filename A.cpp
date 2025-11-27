#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

void all_about_divisors() {
    int n; cin >> n;
    vector<int> divisors;
    vector<int> prime_divisors;
    map<int, int> primeDivFreq;

    // all divisors of N 
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) divisors.push_back(i);
            else {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    cout << "Divisors of N are: ";
    for (auto it: divisors) cout << it << ' ';
    cout << endl;    


    // all prime divisors of N 
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                prime_divisors.push_back(i);
                primeDivFreq[i]++;
            }
        }
    }
    if (n > 1) {
        prime_divisors.push_back(n);
        primeDivFreq[n]++;
    }

    cout << "Prime divisors of N are: ";
    for (int& it : prime_divisors) cout << it << ' ';
    cout << endl;


    // number of divisors of N
    int num_of_divisors = 1;
    for (auto [a, b] : primeDivFreq) {
        num_of_divisors *= (b + 1);
    }
    cout << "Number of divisors of N: " << num_of_divisors << endl;


    // sum of divisors of N 
    int sum_of_devisors = 1;
    for (auto [a, b] : primeDivFreq) {
        int sum = 0;
        for (int i = 0; i <= b; i++) {
            sum += (int)pow(a, i);
        }
        sum_of_devisors *= sum;
    }
    cout << "Sum of divisors of N: " << sum_of_devisors << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    all_about_divisors();
    return 0;
}

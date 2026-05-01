#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            // Mark all multiples of i as not prime
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes.push_back(i);

    return primes;
}

int main() {
    int n = 100;

    vector<int> primes = sieve(n);

    cout << "Primes up to " << n << ":\n";
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i];
        if (i != primes.size() - 1) cout << ", ";
    }
    cout << "\n\nTotal count: " << primes.size() << "\n";

    // Check specific numbers
    vector<int> check = {7, 15, 23, 49, 97};
    cout << "\nPrime check:\n";
    vector<bool> isPrime(n + 1, false);
    for (int p : primes) isPrime[p] = true;
    for (int x : check)
        cout << x << " -> " << (isPrime[x] ? "Prime" : "Not prime") << "\n";

    return 0;
}
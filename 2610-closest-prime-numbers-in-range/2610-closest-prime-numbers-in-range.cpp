class Solution {
    bool checkPrime(int n) {
        if (n < 2) return false; 
        if (n == 2 || n == 3) return true; 
        if (n % 2 == 0 || n % 3 == 0) return false; 
        for (int i = 5; i * i <= n; i += 6) { 
            if (n % i == 0 || n % (i + 2) == 0) return false; 
        }
        return true;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        
        for (int i = left; i <= right; i++) {
            if (checkPrime(i)) primes.push_back(i);
        }

        if (primes.size() < 2) return {-1, -1};

        int minDiff = INT_MAX;
        int first = -1, second = -1;

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1]; 
            if (diff < minDiff) {
                minDiff = diff;
                first = primes[i - 1];
                second = primes[i];
            }
        }

        return {first, second};
    }
};
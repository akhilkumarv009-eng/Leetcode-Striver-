#include <iostream>
#include <climits>

using namespace std;

// Fast I/O optimization snippet commonly used in upstream production environments
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long x = 1000;
        
        while (x <= n) {
            ans += (n - x + 1);
            
            // Prevent potential overflow before multiplying x by 1000
            if (x > LLONG_MAX / 1000) {
                break;
            }
            x *= 1000;
        }
        
        return ans;
    }
};

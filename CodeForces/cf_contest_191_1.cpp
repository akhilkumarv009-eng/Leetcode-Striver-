#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        long long n, x, y, z;
        cin >> n >> x >> y >> z;
        
        // Option 1: No AI
        long long t1 = (n + (x + y) - 1) / (x + y);
        
        // Option 2: Use AI
        long long t2;
        
        // If finished during setup
        if (x * z >= n) {
            t2 = (n + x - 1) / x;
        } else {
            long long remaining = n - x * z;
            long long extra = (remaining + (x + 10*y) - 1) / (x + 10*y);
            t2 = z + extra;
        }
        
        cout << min(t1, t2) << endl;
    }
    
    return 0;
}
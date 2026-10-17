class Solution {
public:
    bool isPowerOfTwo(int n) {
        while( n>= 1)
        {
            if(n==1)return true;
            if(n%2 == 0)
            {
                n=n/2;
            }
            else
            {
                return false;
            }

        }
        return false;
    }
};
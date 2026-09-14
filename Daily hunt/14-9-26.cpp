#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    int left = max(rec1[0], rec2[0]);
    int right = min(rec1[2], rec2[2]);

    int bottom = max(rec1[1], rec2[1]);
    int top = min(rec1[3], rec2[3]);

    return left < right && bottom < top;
}

int main() {
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};

    cout << isRectangleOverlap(rec1, rec2);

    return 0;
}
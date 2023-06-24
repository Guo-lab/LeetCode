// You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), 
// where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

// Return true if the circle and rectangle are overlapped otherwise return false. 
// In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.


#include <bits/stdc++.h>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (pow((i - xCenter), 2) + pow((j - yCenter), 2) <= pow(radius, 2))
                    return true;
            }
        }
        return false;
    }
};

// radius = 2
// the xCenter = 102
// yCenter = 50
// the x1 = 0
// y1 = 0
// the x2 = 100
// y2 = 100
// 预期结果
// true

Or just compare dist and radius * radius

    long long dist = 0;
    if (xCenter < x1 || xCenter > x2) {
        dist += min(pow(x1 - xCenter, 2), pow(x2 - xCenter, 2));
    }
    if (yCenter < y1 || yCenter > y2) {
        dist += min(pow(y1 - yCenter, 2), pow(y2 - yCenter, 2));
    }

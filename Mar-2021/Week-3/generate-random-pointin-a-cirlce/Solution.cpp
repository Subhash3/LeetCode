#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    double cx, cy, r;

public:
    Solution(double radius, double x_center, double y_center)
    {
        this->cx = x_center;
        this->cy = y_center;
        this->r = radius;
    }

    vector<double> randPoint()
    {
        double hypotenuse, adjacent, opposite, angle;

        angle = (double)rand() / RAND_MAX * 2 * M_PI;
        hypotenuse = sqrt((double)rand() / RAND_MAX) * r;
        adjacent = cos(angle) * hypotenuse;
        opposite = sin(angle) * hypotenuse;

        return vector<double>{cx + adjacent, cy + opposite};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
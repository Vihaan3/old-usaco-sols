#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool covered(int x, int y, int x1, int y1, int x2, int y2) {
    // returns true if (x, y) is covered by the rectangle bounded by (x1, y1) and (x2, y2)
    // returns false otherwise
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int main() {
 

    // read in the locations of the corners of the rectangles
    int x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    // count how many corners of the billboard are covered
    int cornerCover = 0;
    if (covered(x1, y1, x3, y3, x4, y4)) cornerCover++;
    if (covered(x1, y2, x3, y3, x4, y4)) cornerCover++;
    if (covered(x2, y1, x3, y3, x4, y4)) cornerCover++;
    if (covered(x2, y2, x3, y3, x4, y4)) cornerCover++;

    // if fewer than 2 corners are covered, the whole rectangle must be covered
    if (cornerCover < 2) {
        std::cout << (x2 - x1) * (y2 - y1) << endl;
    }
    // if all 4 corners are covered, then nothing needs to be covered
    else if (cornerCover == 4) {
        std::cout << 0 << endl;
    }
    else {
        // we only need to cover some portion of the rectangle
        // find the intersection of the two rectangles
        int xL = max(x1, x3);
        int xR = min(x2, x4);
        int yL = max(y1, y3);
        int yR = min(y2, y4);

        // subtract away the area of the intersection
        std::cout << (x2 - x1) * (y2 - y1) - (xR - xL) * (yR - yL) << endl;
    }

   

    return 0;
}
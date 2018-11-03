#include <string>

using namespace std;

struct Cordinate {
    int x;
    int y;
    Cordinate(): x(0), y(0) {}
};

class Solution {
private:
    // O(1)
    void movedown(Cordinate& c) {c.x -= 1;}
    void moveup(Cordinate& c) {c.x += 1;}
    void moveleft(Cordinate& c) {c.y -= 1;}
    void moveright(Cordinate& c) {c.y += 1;}
public:
    Solution() {}
    bool judgeCircle(string moves);
};
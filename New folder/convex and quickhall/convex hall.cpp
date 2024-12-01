#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Structure for points (x, y coordinates)
struct pt {
    double x, y;

    // Overloading equality operator to compare two points
    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
};

// Function to calculate orientation of three points
// Returns:
// -1 -> Clockwise
// +1 -> Counterclockwise
// 0  -> Collinear
int orientation(pt a, pt b, pt c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1;  // Clockwise
    if (v > 0) return +1;  // Counterclockwise
    return 0;               // Collinear
}

// Check if three points make a clockwise turn
bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}

// Check if three points are collinear
bool collinear(pt a, pt b, pt c) {
    return orientation(a, b, c) == 0;
}

// Function to calculate the convex hull using Graham Scan Algorithm
void convex_hull(vector<pt>& a, bool include_collinear = false) {
    // Find the point with the lowest y-coordinate (and then lowest x if there are ties)
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });

    // Sort points based on polar angle with respect to p0
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y) < (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
        return o < 0;
    });

    // If collinear points are included, reverse the order of collinear points
    if (include_collinear) {
        int i = (int)a.size() - 1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin() + i + 1, a.end());
    }

    // Build the convex hull using the sorted points
    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size() - 2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    // Remove last point if it duplicates the first point in a non-collinear case
    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;  // The result is the convex hull
}

// Main function
int main() {
    freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 6\\input.txt","r",stdin);
    freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 6\\output.txt","w",stdout);
    int n;
    cin >> n;  // Number of points

    vector<pt> points(n);

    // Input points (x, y coordinates)
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Compute the convex hull
    convex_hull(points, true);

    // Output the convex hull points
    cout << "Convex Hull:" << endl;
    for (auto& p : points) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}

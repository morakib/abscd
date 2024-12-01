#include <bits/stdc++.h>
using namespace std;

// Define a pair of integers for points
#define iPair pair<int, int>

// Stores the result (points of convex hull)
set<iPair> hull;

// Function to determine the side of a point p with respect to the line passing through p1 and p2
int findSide(iPair p1, iPair p2, iPair p) {
    int val = (p.second - p1.second) * (p2.first - p1.first) - 
              (p2.second - p1.second) * (p.first - p1.first);

    if (val > 0) return 1;  // Point is on the left side
    if (val < 0) return -1; // Point is on the right side
    return 0;               // Point is on the line
}

// Returns the perpendicular distance of point p from the line joining p1 and p2
int lineDist(iPair p1, iPair p2, iPair p) {
    return abs((p.second - p1.second) * (p2.first - p1.first) - 
               (p2.second - p1.second) * (p.first - p1.first));
}

// Recursive function to find the points on the convex hull on one side of the line
void quickHull(iPair a[], int n, iPair p1, iPair p2, int side) {
    int ind = -1;
    int max_dist = 0;

    // Find the point farthest from the line on the specified side
    for (int i = 0; i < n; i++) {
        int temp = lineDist(p1, p2, a[i]);
        if (findSide(p1, p2, a[i]) == side && temp > max_dist) {
            ind = i;
            max_dist = temp;
        }
    }

    // If no point is found, add the endpoints of the line to the hull
    if (ind == -1) {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    // Recur for the two segments created by the farthest point
    quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}

// Function to print the convex hull
void printHull(iPair a[], int n) {
    if (n < 3) {
        cout << "Convex hull is not possible with fewer than 3 points." << endl;
        return;
    }

    // Find the points with minimum and maximum x-coordinates
    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first < a[min_x].first)
            min_x = i;
        if (a[i].first > a[max_x].first)
            max_x = i;
    }

    // Find points on one side of the line
    quickHull(a, n, a[min_x], a[max_x], 1);

    // Find points on the other side of the line
    quickHull(a, n, a[min_x], a[max_x], -1);

    // Print the convex hull
    cout << "The points in the Convex Hull are:" << endl;
    for (auto& point : hull) {
        cout << "(" << point.first << ", " << point.second << ")" << endl;
    }
}

// Driver code
int main() {
        freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 6\\input.txt","r",stdin);
    freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 6\\output.txt","w",stdout);
    int n;
    cin >> n;

    if (n < 3) {
        cout << "Convex hull is not possible with fewer than 3 points." << endl;
        return 0;
    }

    iPair a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    printHull(a, n);
    return 0;
}

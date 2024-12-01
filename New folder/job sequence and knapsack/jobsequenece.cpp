#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 5\\input.txt", "r", stdin);

    int n;
    cin >> n;

    int p[n], d[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<tuple<int, int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back(make_tuple(p[i], d[i], i));
    }

    sort(jobs.rbegin(), jobs.rend());

    int max_deadline = *max_element(d, d + n);


    vector<int> time_slots(max_deadline + 1, -1); 
    int total_profit = 0;

    for (int i = 0; i < n; i++) {
        int profit = get<0>(jobs[i]);
        int deadline = get<1>(jobs[i]);
        for (int j = min(max_deadline, deadline); j > 0; j--) {
            if (time_slots[j] == -1) {
                time_slots[j] = get<2>(jobs[i]);
                total_profit += profit;
                break;
            }
        }
    }

    cout << "Maximum Profit: " << total_profit << endl;

    cout << "Jobs selected: ";
    for (int i = 1; i <= max_deadline; i++) {
        if (time_slots[i] != -1) {
            cout << time_slots[i] + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
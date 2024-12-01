#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 5\\knapsackinput.txt", "r", stdin);
    
    int n, m = 20;
    cin >> n;
    int w[n], b[n];
    double wb[n];
    
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        wb[i] = (double)b[i] / w[i];
    }

    vector<pair<double, int>> ratio;
    for (int i = 0; i < n; i++) {
        ratio.push_back({wb[i], i});
    }

    
    sort(ratio.rbegin(), ratio.rend());

    stack<int> s;

    for (auto &entry : ratio) {
        s.push(entry.second);
    }

    vector<int> stack_order;
    while (!s.empty()) {
        stack_order.push_back(s.top());
        s.pop();
    }

    int soln[n] = {}; 
    float benefit = 0;
    
    while (m != 0 && !stack_order.empty()) {
        int index = stack_order.back();
        stack_order.pop_back();

        if (m >= w[index]) {
            m -= w[index];
            soln[index] = w[index]; 
            benefit += b[index];    
        } else {
            benefit += wb[index] * m;
            soln[index] = m;
            m = 0;
        }
    }

    cout << "Optimal Solution: ";
    for (int i = 0; i < n; i++) {
        cout << soln[i] << " ";
    }
    cout << endl;
    
    cout << "Benefit is = " << benefit << endl;

    return 0;
}
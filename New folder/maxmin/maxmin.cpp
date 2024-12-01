#include <bits/stdc++.h>
#include <chrono>
using namespace std;

vector<long long> Num;

void generateRandomNumbers(int n) {
    for (int i = 0; i < n; i++) {
        int num = rand() % n + 1;
        Num.push_back(num);
    }
}

pair<int, int> bruteForceMaxMin(const vector<long long>& arr) {
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for (int num : arr) {
        if (num > maxVal) maxVal = num;
        if (num < minVal) minVal = num;
    }
    return {maxVal, minVal};
}

pair<int, int> maxMinDivideConquer(const vector<long long>& arr, int low, int high) {
    if (high - low + 1 <= 1000) {
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        for (int i = low; i <= high; i++) {
            if (arr[i] > maxVal) maxVal = arr[i];
            if (arr[i] < minVal) minVal = arr[i];
        }
        return {maxVal, minVal};
    }

    int mid = (low + high) / 2;
    auto leftPair = maxMinDivideConquer(arr, low, mid);
    auto rightPair = maxMinDivideConquer(arr, mid + 1, high);

    int maxVal = max(leftPair.first, rightPair.first);
    int minVal = min(leftPair.second, rightPair.second);

    return {maxVal, minVal};
}

int main() {
    freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 9\\input.txt","r",stdin);
    freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 9\\output.txt","w",stdout);
    srand(time(0)); // Seed random number generator

    cout << "Enter size of the array: ";
    int n;
    cin >> n;

    generateRandomNumbers(n);

    // Brute-force approach
    auto start = chrono::high_resolution_clock::now();
    auto bruteForceResult = bruteForceMaxMin(Num);
    auto end = chrono::high_resolution_clock::now();
    double timeTakenBruteForce = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // Divide-and-Conquer approach
    auto start1 = chrono::high_resolution_clock::now();
    auto divideConquerResult = maxMinDivideConquer(Num, 0, Num.size() - 1);
    auto end1 = chrono::high_resolution_clock::now();
    double timeTakenDivideConquer = chrono::duration_cast<chrono::duration<double>>(end1 - start1).count();

    // Output results
    cout << "Brute-Force Approach:\n";
    cout << "Max: " << bruteForceResult.first << ", Min: " << bruteForceResult.second << "\n";
    cout << "Time taken: " << timeTakenBruteForce << " seconds\n";

    cout << "\nDivide-and-Conquer Approach:\n";
    cout << "Max: " << divideConquerResult.first << ", Min: " << divideConquerResult.second << "\n";
    cout << "Time taken: " << timeTakenDivideConquer << " seconds\n";

    return 0;
}

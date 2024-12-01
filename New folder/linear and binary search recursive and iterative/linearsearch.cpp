#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>a, int size, int x) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int linear_search(vector<int>a, int ind, int value){
    for(int i=0;i<a.size();i++){
        if(a[i]==10000000000){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("time.txt","a",stdout);
    int n,value; cin>>n>>value;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    int ans=linear_search(a,0,value);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(15);
    cout << " sec" << endl;

    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    int ans=binarySearch(a,0,value);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(15);
    cout << " sec" << endl;
}
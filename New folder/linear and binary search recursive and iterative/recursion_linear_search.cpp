#include<bits/stdc++.h>
#include<chrono>
using namespace std;
int binarySearch(vector<int>a, int low, int high, int x)
{
    if(low>high)return -1;
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return binarySearch(a, low, mid - 1, x);
        return binarySearch(a, mid + 1, high, x);
    }
}
int linear_search(vector<int>a, int ind, int value){
    if(ind==a.size()){
        return -1;
    }
    if(a[ind]==100000000){
        return ind;
    }else{
        int neww=linear_search(a,ind+1,value);
        return neww;
    }
    
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
}
#include<bits/stdc++.h>
using namespace std;
vector<int> mergingtwoarray(vector<int>arr1, vector<int>arr2){
    int n=arr1.size();
    int m=arr2.size();
    vector<int>arr(m+n);

    int i=0,j=0,k=0;
    while(i<n and j<m){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
        }else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n){
        arr[k]=arr1[i];
        i++;k++;
    }
    while(j<m){
        arr[k]=arr2[j];
        j++;k++;
    }
    return arr;
}
vector<int> mergesort(vector<int>arrnew,int lo,int hi){
    if(lo==hi){
        vector<int>base(1);
        base[0]=arrnew[lo];
        return base;
    }
    int mid=lo+(hi-lo)/2;
    vector<int>sorted1starray=mergesort(arrnew,lo,mid);
    vector<int>sorted2ndarray=mergesort(arrnew,mid+1,hi);
    vector<int>ans=mergingtwoarray(sorted1starray,sorted2ndarray);
    return ans;
}
void printingmergesort(vector<int>ar){
    int n=ar.size();
    vector<int>ans;
    ans=mergesort(ar,0,n-1);
    for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
   }cout<<endl;
}
int main(){
    freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 8\\input.txt","r",stdin);
    freopen("C:\\Users\\pritt\\OneDrive\\Documents\\all pdf\\2.2 semester\\algorithm lab\\day 8\\output.txt","w",stdout);
    int n; cin>>n;
    vector<int>arr(n),ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printingmergesort(arr);
   

}
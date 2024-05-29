#include <bits/stdc++.h>
using namespace std;


int main()
{    int n;
     cout<<"enter size of array: ";
     cin>>n;
     int arr[n];
     cout<<"enter elements: "<<endl;
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     int l=0;
     int r=n-1;
     while (l < r)
    {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
        l++;
        r--;
    }
     cout<<"after array reversal: "<<endl;
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
}

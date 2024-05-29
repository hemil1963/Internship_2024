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


    cout << "Sum of given array is "
         << accumulate(arr, arr + n, 0);
    return 0;
}

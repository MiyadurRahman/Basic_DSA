#include <iostream>
using namespace std;
int binarySearch(int arr[],int n,int target){
int low=0;
int high=n-1;
while(low<=high){
    int mid=(low+high)/2;
if(arr[mid]==target){
    return mid;
}
else if(arr[mid]<target){
low=mid+1;
}
else{
    high=mid-1;
}

}
return -1;




}
int main(){
    int n;
    cout<<"size of array: "<<endl;
    cin>>n;
int arr[n];
cout<<"enter elements of array: "<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];

}
int target;
cout<<"target element to search: "<<endl;
cin>>target;
cout<<"found in index";
int result=binarySearch(arr,n,target);
cout<<result;






}
#include <iostream>
using namespace std;
int linearsearch(int arr[],int n,int target){
for(int i=0;i<n;i++){
    if(arr[i]==target){
        cout<<"element found at index: ";
        return i;
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
int result=linearsearch(arr,n,target);
cout<<result;






}
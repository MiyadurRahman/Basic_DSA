#include <iostream>
using namespace std;
void bubblesort(int arr[],int n){

    for(int boundary=n-2;boundary>=0;boundary--)
    {
        for(int i=0;i<=boundary;i++){
            if(arr[i]<arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            }
        }
    }
}
int main(){
    int arr[]={120,340,290,450,210};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"array after bubble sort is :"<<endl;
    bubblesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}//spring2025 problem

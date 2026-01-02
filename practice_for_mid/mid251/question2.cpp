#include <stdio.h>
int binarySearch(int arr[],int n,int target){
int low=0;
int high=n-1;
int result=-1;
int count=0;
while(low<=high){
    int mid=(low+high)/2;
if(arr[mid]==target){
    count++;
    high=mid-1;
    
}
else if(arr[mid]<target){
low=mid+1;
}
else{
    high=mid-1;
}

}
return count;
}
int binarySearch2(int arr[],int n,int target){
int low=0;
int high=n-1;

int count=0;
while(low<=high){
    int mid=(low+high)/2;
if(arr[mid]==target){
       count++;
    low=mid+1;
 
}
else if(arr[mid]<target){
low=mid+1;
}
else{
    high=mid-1;
}

}
return count;


}
int main(){
    int arr[]={1,2,4,4,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int count1=binarySearch2(arr,size,4);
    int count2=binarySearch(arr,size,4);
    int occurence=count1+count2;
    printf("%d",occurence);



}
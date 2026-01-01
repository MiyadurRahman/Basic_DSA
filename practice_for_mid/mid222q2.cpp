#include <stdio.h>
int search_pair(int arr[],int N,int a,int b){
   int count=0;
    for(int i=0;i<N;i++){
        if(arr[i]==a){
            count++;
        }
        if(arr[i]==b && a!=b){
            count++;
        }
        
    }
return count;
}
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
 for(int i=0;i<N;i++){
 scanf("%d",&arr[i]);

 }
    int A,B;
    printf("enter a:");
    scanf("%d",&A);
    printf("enter b:");
    scanf("%d",&B);
    int count=search_pair(arr,N,A,B);
    if(count==1){
        printf("only me");


    }
    else if(count==2){
        printf("pair matched");
    }
    else{
        printf("better luck next time");
    }
}
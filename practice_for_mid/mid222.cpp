#include <stdio.h>
void take_input(int arr[],int N){
for(int i=0;i<N;i++){
    scanf("%d",&arr[i]);
}


}
void print_array(float arr[],int N){
for(int i=0;i<N;i++){
    printf("%f ",arr[i]);
}

}
void Sorted_array(float arr[],int N){
for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++ ){
       if(arr[i]>arr[j]){
         float temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;

       }
     }
}
}


int main (){
int N;
scanf("%d",&N);
int weight[N];
int height[N];
printf("enter weight: ");
take_input(weight,N);
printf("enter height input:");
take_input(height,N);
float BMI[N];
for(int i=0;i<N;i++){
    if(height[i] !=0){
  BMI[i]=(float) weight[i]/height[i];
    }
    else BMI[i]=0;

}
print_array(BMI,N);
printf("\n");
printf("the sorted Bmi:\n ");
Sorted_array(BMI,N);
print_array(BMI,N);




}
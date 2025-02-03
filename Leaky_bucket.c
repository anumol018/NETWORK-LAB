#include<stdio.h>

int main(){
   int incomming, outgoing , buck_size,n,store=0;
   printf("Enter the bucket size , outgoing rate and number of input :");
   scanf("%d %d %d", &buck_size, &outgoing, &n);
   while(n!=0){
     printf("Enter the incomming packet size:");
     scanf("%d",&incomming);
     printf("incomming packet size %d\n",incomming);
    
     // Check if the bucket has enough space
     if (incomming <= (buck_size-store)){
       store+=incomming;   // Add incoming packets to the store
       printf("bucket buffer size: %d out of %d\n",store, buck_size);
     }
     else{
       // If incoming packets can't fit in the bucket, drop them
       printf("dropped %d no of packets \n",incomming -(buck_size-store));
       store=buck_size;
       printf("bucket buffer size: %d out of %d \n",store, buck_size);
     }
     
     if(store>=outgoing){
       store-=outgoing; // Remove outgoing packets from the buffer
     }
     if(store<0){
       store=0;  //Reset store to 0 if it becomes negative
     } 
     printf("after outgoing, there are %d out of %d packets left in buffer\n", store, buck_size);
     printf("\n");
     n--;
   }
}

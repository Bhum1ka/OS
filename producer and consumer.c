#include<stdio.h>
int main()
{
	int producer,consumer,in=0,out=0,buff,buffer[10],choice;
	buff=10;
	while(choice!=3){
		printf("\n1.produre \t 2.consumer \t 3.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: if(((in+1)%buff)==out){
				       printf("Buffer is full");
				   }
				   else{
				   	    printf("Enter your value");
				   	    scanf("%d",&producer);
				   	    buffer[in]=producer;
				   	    in=(in%buff)+1;
				   }
				break;
			case 2: if(in==out){
				        printf("Buffer is empty");
				    }
				    else{
				    	consumer=buffer[out];
				    	printf("consumed value is %d",consumer);
				        out=(out+1)%buff;
					}
			break;
		}
	}
}


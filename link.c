#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
	int data;
	struct linked_list *next;
}node;



int main()
{
	node *start,*ptr,*temp;
	int i,j,n,no,c;
	printf("Enter Number Of Modes:");
	scanf("%d",&n);
	printf("\nEnter Node Number 1:");
	start=(node*)malloc(sizeof(node));
	scanf("%d",&start->data);
	temp=start;
	for(i=1;i<n;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		printf("\nEnter Node Number %d",i+1);
		temp->next=ptr;
		temp=ptr;
	}
	temp->next=NULL;
	do(j)
	{
		printf("Enter your Choise\n:");
		printf("\n1.INSERTION\n2.DELETION\n3.TRAVERSE\n4.EXIT\n\n:");
		scanf("%d",&j);
		{
			
		case 1:
		printf("Enter The Number To BE Inserted:");
		scanf("%d",&c);
		printf("Enter 1 To Inserted At The Begning\n:");
		printf("Enter 2 To Inserted At The End\n:");
		printf("Enter 1 To Inserted At The Specified Location\n:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			insbeg(&start,no);
			break;
			case 2:
			insend(&start,no);
			break;
			case 3:
			insafter(&start,no);
			break;
			default:
			printf("\nInvalid Choise");
			break;
		}
		break;
		case 2:
			printf("\nEnter The Number To Be Deleted:");
			scanf("%d",&no);
			del(&start,no);
			break;
			case 3:
			traverse(start);
			break;
			case 4:
			exit(0)
			default:
				printf("\ninvalid Input:");
				break;
			}
		}while(1);
		return 0;
	}
	


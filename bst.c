#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
	int data;
	struct bst *left,*right;
}node;

void traverse_inorder(node *r)
{
	if(r!=NULL){
     traverse_inorder(r->left);
     printf("%d\t",r->data);
     traverse_inorder(r->right);
	}
}
   	
void insert(node **r,int num)
{
	node *temp,*ptr;
	temp=*r;
	if(temp==NULL)	
	{	   	
	       ptr=(node*)malloc(sizeof(node));
            ptr->data=num;
	        ptr->left=NULL;
	        ptr->right=NULL;
		 *r=ptr;
	 }
	else{
		if(num>temp->data)
		{
			if(temp->right==NULL){
		   	ptr=(node*)malloc(sizeof(node));
            ptr->data=num;
	        ptr->left=NULL;
	        ptr->right=NULL;
				temp->right=ptr;
		   return;
	       }
		else{
		       temp=temp->right;
		       insert(&temp,num);
		     }
		   }
		   else{
             if(temp->left==NULL){
		   	ptr=(node*)malloc(sizeof(node));
            ptr->data=num;
             ptr->left=NULL;
	        ptr->right=NULL;
				temp->left=ptr;
		   return;
	       }
		else{
		       temp=temp->left;
		       insert(&temp,num);
		   }
	   }
   }
}

int search_bst(node *r,int num){
	if(r==NULL)
	{	   	
	    return 0;
	 }
	else{
		if(r->data==num)
		   return 1;
		else{
		     if(num>r->data)
		     {
				return search_bst(r->right,num);
		     }
		   else{
            return search_bst(r->left,num);
		   }
	   }
   }
}
void delete(node **r,int num){
	node *temp,*parent,*x,*xsucc;
	int f=0;
	temp=*r;
	if(temp==NULL)
	return;
	search_bst(num,&parent,&x,&xsucc,&f);
	if(f=0)
	{
		printf("\nthe node is not found");
		return;
	}

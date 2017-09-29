#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
	int data;
	struct bst *left,*right;
}node;

void traverse_inorder(node *q)
{
	if(q!=NULL){
     traverse_inorder(q->left);
     printf("%d\t",q->data);
     traverse_inorder(q->right);
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
		if(num>temp->data){
                 insert(&temp->right,num);
           }
         else{
			   insert(&temp->left,num);
			}
		}
   }
   
int search_bst(node *q,int num){
	if(q==NULL)
	{	   	
	    return 0;
	 }
	else{
		if(q->data==num)
		   return 1;
		else{
		     if(num>q->data)
		     {
				return search_bst(q->right,num);
		     }
		   else{
            return search_bst(q->left,num);
		   }
	   }
   }
}

void search_node(node **x,node *root,node **parent,int num,int *f)
{
	node *temp;
	temp=root;
	 if(temp==NULL)
	   return;

		while(temp!=NULL)
		{
			if(temp->data==num)
	    {
			*f=1;
			*x=temp;
			return;
		}
		*parent=temp;
			if(num>temp->data)
			    temp=temp->right;
			 else
			    temp=temp->left;
		}
   }
   
void delete(node **q,int num){
	node *temp,*parent,*xsucc,*x;
	int f=0;
	parent=NULL;x=NULL;xsucc=NULL;
	temp=*q;
	search_node(&x,temp,&parent,num,&f);
	if(f==0)
	{	   	
	    printf("\n The Element %d is not found",num);
	    return;
	 }
	 //x has no child
	 if(x->left==NULL && x->right==NULL)
	 {
		 if(x->data >parent->data)
		    parent->right=NULL;
		 else
		    parent->left=NULL;
		 
	 }
	 //x has left child
	else if(x->left!=NULL && x->right==NULL)
	{
		if(x->data >parent->data)
		    parent->right=x->left;
		 else
		    parent->left=x->left;
	}
	//x has right child
	else if(x->right!=NULL && x->left==NULL)
	{
		if(x->data >parent->data)
		    parent->right=x->right;
		 else
		    parent->left=x->right;
		 
	}
	//x has both child
	else if(x->left!=NULL && x->right!=NULL)
    {
		parent=x;
		xsucc=x->right;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		if(xsucc->data >parent->data)
		    parent->right=NULL;
		 else
		    parent->left=NULL;
		  x->data=xsucc->data;
		  x=xsucc;
	}
	 free(x);
}

int main()
{
	node *root;
	root=NULL;
	int ch,no;
	do
	{
		printf("\n\t**MENU**\n1.INSERT\n2.DELETE\n3.SEARCH\n4.TRAVERSE\n5.EXIT\n");
		printf("ENTER YOUR CHOICE");
	    scanf("%d",&ch);
	    switch(ch)
	    {
			case 1:printf("ENTER THE VALUE");
				   scanf("%d",&no);
				   insert(&root,no);
				   break;
	       case 2:printf("ENTER THE VALUE");
				  scanf("%d",&no);	
				  delete(&root,no);
				  break;
		   case 3:search_bst(root,no);
				  break;
		   case 4:traverse_inorder(root);
				  break;
		   case 5:exit(0);
				  break;
		   default:printf("INVALID CHOICE");
	   }
   }
   while(1);
   return 0;
}

					
	

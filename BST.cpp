#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root = NULL;
void insert(int d){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL){
		root = temp;
	}else{
		struct node* p,*q;
		p = root;
		while(p != NULL){
			if(d < p->data){
				q = p;
				p = p->left;
		    }else{
		    	q = p;
		    	p = p->right;
			}
		}
		if(q->data > d){
			q->left = temp;
		}else{
			q->right = temp;
		}
	}
	printf("%d inserted successfully in BST\n\n",d);
}
void infix(struct node* n){
	if(n == NULL){
		return;
	}
	infix(n->left);
	printf("%d  ",n->data);
	infix(n->right);
}
void prefix(struct node* n){
	if(n == NULL){
		return;
	}
	printf("%d  ",n->data);
	prefix(n->left);
	prefix(n->right);
}
void postfix(struct node* n){
	if(n == NULL){
		return;
	}
	postfix(n->left);
	postfix(n->right);
	printf("%d  ",n->data);
}
int main(){
	int c,d;
	printf("Binary Search Tree\n");
	while(1){
		printf("1. Insert\n");
		printf("2. Inorder Traverse\n");
		printf("3. Preorder Traverse\n");
		printf("4. Postorder Traverse\n");
		printf("5. Exit\n\n");
		printf("Enter your choice\n");
		scanf("%d",&c);
		switch(c){
			case 1 : printf("Enter the item you want to insert\n");
			         scanf("%d",&d);
			         insert(d);
			         break;
			         
			case 2 : printf("Inorder Traversal is :\n");
			         infix(root);
			         printf("\n\n");
			         break;
			         
			case 3 : printf("Preorder Traversal is :\n");
			         prefix(root);
			         printf("\n\n");
			         break;
			         
			case 4 : printf("Postorder Traversal is :\n");
			         postfix(root);
			         printf("\n\n");
			         break;
			         
			case 5 : exit(1);
			         break;
			         
			default : printf("You have enter a wrong choice\n\n");
			          break;
		}
	}
	return 0;
}

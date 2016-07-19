#include <stdio.h>  
#include <stdlib.h>  

//구조체 정의  
struct tnode  
{   
	struct tnode *left;  
	struct tnode *right;  
	int data;  
};  

//루트 생성 
tnode *root = (tnode *)malloc(sizeof(tnode));  

//함수 선언 
tnode *treeSearch(tnode *t, int x); 
tnode *tree_parent_Search(tnode *t, int x);
tnode *treeInsert(tnode *t, int x);  
tnode *treeDelete(tnode *t,tnode *r,tnode *p); 
tnode *deleteNode(tnode *r); 
tnode *rotate(int key); 

void postorder(tnode *ptr);  

int treeHeight(tnode *ptr);  


int main()  
{  
	root->data = NULL;  
	root = NULL;  
	
	int num;  
	scanf("%d",&num);     

	bool first=false;  

	//입력 받기 + 삽입,삭제,회전  
	int type,key;  
	for(int i=0; i<num;i++)  
	{  
		scanf("%d %d",&type,&key);  

		
		//삽입
			if(type==1)
				if(treeSearch(root,key) == NULL)
					root = treeInsert(root,key);

		//삭제		
		if(type==2) 
		{ 
			//트리 삭제
			if(treeSearch(root,key) != NULL) 
				treeDelete(root,treeSearch(root,key),tree_parent_Search(root,key)); 
		} 



		//회전 
		if(type==3) 
			root = rotate(key); 
			

	}
	
	//후위순회 출력  
	postorder(root);  

	return 0;  
}  


//검색 함수 
tnode *treeSearch(tnode *t, int x) 
{ 
	if(t == NULL || t->data == x) 
		return t; 
	if(x < t->data) 
		return treeSearch(t->left,x); 
	else
		return treeSearch(t->right,x); 
} 


//부모검색 함수 
tnode *tree_parent_Search(tnode *t, int x) 
{ 

	if(t!=NULL)
		if(t->left!=NULL)
			if(t->left->data == x)
				return t; 
	if(t!=NULL)
		if(t->right!=NULL)
			if(t->right->data == x)
			{
				return t;
			}

	if(t == NULL)
		return NULL;

	if(x == root->data)
		return NULL;


	if(x < t->data) 
		return tree_parent_Search(t->left,x); 
	else
		return tree_parent_Search(t->right,x); 
}



//삽입 함수 
tnode *treeInsert(tnode *t, int x)  
{  	
	if(t == NULL)  
	{  
		tnode *node = (tnode *)malloc(sizeof(tnode));  
		node->data=x;  
		node->left=NULL;  
		node->right=NULL; 

		return node;  
	}  

	if(x < t->data)  
	{  
		t->left = treeInsert(t->left,x);  
		return t;  
	}  
	else
	{  
		t->right = treeInsert(t->right,x);  
		return t;  
	}  
} 


//삭제함수 
tnode *treeDelete(tnode *t,tnode *r,tnode *p) 
{ 
	if(r==t) 
	{
		root = deleteNode(t);
	}

	else if(r == p->left) 
	{
		p->left = deleteNode(r); 
	}
	else
	{
		p->right = deleteNode(r);
	}


	return r;    
} 

tnode *deleteNode(tnode *r) 
{ 
	if(r->left == NULL && r->right == NULL) 
		return NULL; 
	else if(r->left == NULL && r->right != NULL) 
		return r->right; 
	else if(r->left != NULL && r->right == NULL) 
		return r->left; 

	else
	{ 
		tnode *s = (tnode *)malloc(sizeof(tnode));  
		tnode *parent = (tnode *)malloc(sizeof(tnode));  


		s = r->right; 
		while(s->left != NULL) 
		{ 
			parent = s; 
			s = s->left; 
		} 

		r->data = s->data; 

		if(s == r->right) 
		{
			r->right = s->right;
		}


		else
		{
		
			parent->left = s->right; 
		}
		return r; 
	} 
} 


//회전함수 
tnode *rotate(int key) 
{ 
	if(treeSearch(root,key) != NULL &&  (treeSearch(root,key)->left != NULL || treeSearch(root,key)->right != NULL))  // 입력으로 주어진 키 값이 트리에 존재하지 않는 경우와 왼쪽 , 오른쪽 서브 트리 둘다 없는경우 해당 회전 연산 무시 
	{ 
		tnode *a = (tnode *)malloc(sizeof(tnode));  
		tnode *b = (tnode *)malloc(sizeof(tnode));  
		tnode *c = (tnode *)malloc(sizeof(tnode));  

		//if( X의 왼쪽 서브트리의 높이 > X의 오른쪽 서브트리의 높이 ) 
		if(treeHeight(treeSearch(root,key)->left) > treeHeight(treeSearch(root,key)->right)) 
		{ 
			//a를 기준으로 LL 회전; 

			a = treeSearch(root,key); 
			b = a->left; 


			int tt=0;
			if(a!=root)
			{
				c=tree_parent_Search(root,a->data);


				if(c->right == a)
					tt=0;
				else
					tt=1;
			}

			a->left = b->right;//b의 오른쪽 자식을 a의 왼쪽 자식으로 만듦. 		

			b->right = a; //a를 b의 오른쪽 자식노드로 만듦    




			////////b와 a의 부모와의 관계
			if(a!=root)
			{
				if(tt==0)
					c->right = b;       //부모 고려해주기. 
				else
					c->left = b;
			}
			
			if(a == root)//root가 바뀌었을 경우 
				root = b; 

			return root; 

		} 
		else if(treeHeight(treeSearch(root,key)->left) < treeHeight(treeSearch(root,key)->right)) 
		{ 
			///a를 기준으로 RR 회전; 
			a = treeSearch(root,key); 
			b = a->right; 

			int tt=0;

			if(a!=root)
			{
				c=tree_parent_Search(root,a->data);



				if(c->right == a)
					tt=0;
				else
					tt=1;
			}


			a->right = b->left;//b의 왼쪽자식을 a의 오른쪽 자식으로 만듦. 

			b->left = a; //a를 b의 왼쪽 자식노드로 만듦    


			////////b와 a의 부모와의 관계 
			if(a!=root)
			{
				if(tt==0)
					c->right = b;       //부모 고려해주기. 
				else
					c->left = b;
			}

			if(a == root) //root가 바뀌었을 경우 
				root = b; 

			return root; 

		} 

	} 
	// 양쪽 서브 트리의 높이가 같은 경우 아무 작업 안함! 

	return root; 
} 


// 후위 순회   
void postorder(tnode *ptr)  
{  
	if(ptr)  
	{ 
		postorder(ptr->left);  
		postorder(ptr->right);  

		printf(" %d ", ptr->data);  

		//높이 출력  
		printf("%d\n",treeHeight(ptr));  
	}  
}  

//노드의 높이 구하기.
int treeHeight(tnode *ptr)  
{  
	int height=0;  

	if(ptr==NULL)//ptr이 존재하지 않으면 높이 -1 
		return -1; 

	if(ptr->left != NULL || ptr->right != NULL)  
	{  
		if(ptr->left == NULL)  
		{  
			height = 1 + treeHeight(ptr->right);  
		}  
		else if( ptr->right == NULL)  
		{             
			height = 1 + treeHeight(ptr->left) ;  
		}  

		else if(treeHeight(ptr->left) > treeHeight(ptr->right))  
		{             
			height = 1 + treeHeight(ptr->left) ;  

		}  
		else
		{             
			height = 1 + treeHeight(ptr->right);  
		}  
	}  
	return height;  
}  

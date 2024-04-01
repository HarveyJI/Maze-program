#include<iostream>
using namespace std;

/*쳲�����_�ݹ� 
int Fib(int n){
	if(n==1||n==2){
		return 0;
	}
	if(n==3){
		return 1;
	}else{
		return Fib(n-1)+Fib(n-2)+Fib(n-3);
	}
	
}

int main(){
	int n;
	cin>>n;
	cout<<Fib(n);
	return 0;
}*/  
typedef struct LinkedQueueNode{       //������ 
	int data;
	LinkedQueueNode *next;
}LinkedQueueNode;

typedef struct LQueue{
	LinkedQueueNode *front;
	LinkedQueueNode *rear; 
}LQueue,*LinkedQueue;

LinkedQueue Init_LinkedQueue(){      //��ʼ�� 
	LinkedQueue Q;
	Q=new LQueue; 
	LinkedQueueNode *head;
	head=new LinkedQueueNode;
	if(head!=NULL&&Q!=NULL){
		head->next==NULL;
		Q->front=head;
		Q->rear=head; 
	}
	return Q;
}

int LinkedQueue_Empty(LinkedQueue Q){     //�п� 
	if(Q->front==Q->rear){
		return 1;	
	}else{
		return 0;
	}
}

int Enter_LinkedQueue(LinkedQueue Q,int x){      //��� 
	LinkedQueueNode *node;
	node=new LinkedQueueNode;
	if(node==NULL){
	return 0;	
	}
	node->data=x;
	node->next=NULL;
	Q->rear->next=node;
	Q->rear=node; 
	return 1;
} 

int Delete_LinkedQueue(LinkedQueue Q,int& x){    //���� 
	LinkedQueueNode *node;
	if(!LinkedQueue_Empty(Q)){
		node=Q->front->next;
		x=node->data;
		Q->front->next=node->next;
		if(node==Q->rear){
			Q->rear=Q->front;
		}
		delete(node);
		return 1;
	}else{
		return 0;
	}
} 

int GetFront_LinkedQueue(LinkedQueue Q,int &x){     //��ȡ��ͷ 
	if(!LinkedQueue_Empty(Q)){
		x=Q->front->next->data;
		return 1;
	}else{
		return 0;
	}
}
/*쳲�����_���� */

void Fib(int n){
	LinkedQueue Q;
	int a1,a2,a3,a4,a5;
	Q=Init_LinkedQueue(); 
	Enter_LinkedQueue(Q,0);
	Enter_LinkedQueue(Q,0);
	Enter_LinkedQueue(Q,1);  
	for(int i=1;i<=n-3;i++){	
	Delete_LinkedQueue(Q,a1);      //ȡ��ǰ3��,�����ǰ2��������� 
	Delete_LinkedQueue(Q,a2);
	Delete_LinkedQueue(Q,a3);
	Enter_LinkedQueue(Q,a2);    
	Enter_LinkedQueue(Q,a3);       
	Enter_LinkedQueue(Q,a1+a2+a3);
	}
	 	
	while(Q->rear!=Q->front->next){      //��������,ֱ�����һ��,��Ϊ������ 
	Delete_LinkedQueue(Q,a4);
	}
	GetFront_LinkedQueue(Q,a5);      //��ȡ��� 
	if(n>=3){
	cout<<"쳲�������"<<n<<"��Ϊ:"<<a5;	       //��� 
	}else{
	cout<<"쳲�������"<<n<<"��Ϊ:"<<0;
	}
} 

int main(){
	int n;
	cin>>n; 
	Fib(n);		
	return 0;
}

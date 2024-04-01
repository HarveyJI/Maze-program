#include<iostream>
using namespace std;
const int MAXSIZE=1024;
typedef struct SequenQueue{     //顺序队列---循环队列 
	int data[MAXSIZE];
	int front;
	int rear;
}SequenQueue;

SequenQueue* Init_SequenQueue(){
	SequenQueue *Q;
	Q=new SequenQueue;
	if(Q!=NULL){
		Q->front=0;
		Q->rear=0;
	}
	return Q;
}

int SequenQueue_Empty(SequenQueue *Q){     //判空 
	if(Q->front==Q->rear){
		return 1;
	}else{
		return 0;
	}
}

int SequenQueue_Full(SequenQueue *Q){      //判满 
	if((Q->rear+1)%MAXSIZE==Q->front){
		return 1;
	}else{
		return 0;
	}
} 

int SequenQueue_Length(SequenQueue *Q){            //求长度 
	return ((Q->rear-Q->front+MAXSIZE)%MAXSIZE);
} 

int Enter_SequenQueue(SequenQueue *Q,int x){       //入队
	if(!SequenQueue_Full(Q)){
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%MAXSIZE;
		return 1;
	}else{
		return 0;
	} 
}

int Delete_SequenQueue(SequenQueue *Q,int &x){       //出队 
	if(!SequenQueue_Empty(Q)){
	x=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return 1;
	}else{
		return 0;
	}
}

int GetFront_SequenQueue(SequenQueue *Q,int &x){      //获取对头元素 
	if(!SequenQueue_Empty(Q)){
	x=Q->data[Q->front];
	return 1;
	}else{
	return 0;
	}
} 

void YHTriangle(int n){
	SequenQueue *Q;
	Q=Init_SequenQueue();
	int a1,a2;
	for(int i=1;i<=n-1;i++){
		cout<<"  ";
	}
	cout<<1<<endl;
	Enter_SequenQueue(Q,1);           //入队第2行1 1 
	Enter_SequenQueue(Q,1);
	for(int i=2;i<=n;i++){
		for(int k=1;k<=n-i;k++){
		cout<<"  ";	
		}
		Enter_SequenQueue(Q,1);      //压入第i+1行第一个 1 
		int k=0;
		for(int j=0;j<=i-2;j++){
		Delete_SequenQueue(Q,a1);     //出队第i行第一个元素 
		cout<<a1;
		if(a1<10){
			cout<<"   ";
		}else if(a1<100){
			cout<<"  ";
		}else{
		cout<<" ";	
		} 
		GetFront_SequenQueue(Q,a2);    //依次`取第i行元素(n>=2) 
		Enter_SequenQueue(Q,a1+a2);	    
		}
		Delete_SequenQueue(Q,a2);       //加的值再入队 
		cout<<a2<<endl;
		Enter_SequenQueue(Q,1);        // 入队第i+1行最后一个 1 
	}		
}


int main(){
	int n;
	cin>>n;
	YHTriangle(n);	
} 

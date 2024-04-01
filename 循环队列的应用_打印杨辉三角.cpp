#include<iostream>
using namespace std;
const int MAXSIZE=1024;
typedef struct SequenQueue{     //˳�����---ѭ������ 
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

int SequenQueue_Empty(SequenQueue *Q){     //�п� 
	if(Q->front==Q->rear){
		return 1;
	}else{
		return 0;
	}
}

int SequenQueue_Full(SequenQueue *Q){      //���� 
	if((Q->rear+1)%MAXSIZE==Q->front){
		return 1;
	}else{
		return 0;
	}
} 

int SequenQueue_Length(SequenQueue *Q){            //�󳤶� 
	return ((Q->rear-Q->front+MAXSIZE)%MAXSIZE);
} 

int Enter_SequenQueue(SequenQueue *Q,int x){       //���
	if(!SequenQueue_Full(Q)){
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%MAXSIZE;
		return 1;
	}else{
		return 0;
	} 
}

int Delete_SequenQueue(SequenQueue *Q,int &x){       //���� 
	if(!SequenQueue_Empty(Q)){
	x=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return 1;
	}else{
		return 0;
	}
}

int GetFront_SequenQueue(SequenQueue *Q,int &x){      //��ȡ��ͷԪ�� 
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
	Enter_SequenQueue(Q,1);           //��ӵ�2��1 1 
	Enter_SequenQueue(Q,1);
	for(int i=2;i<=n;i++){
		for(int k=1;k<=n-i;k++){
		cout<<"  ";	
		}
		Enter_SequenQueue(Q,1);      //ѹ���i+1�е�һ�� 1 
		int k=0;
		for(int j=0;j<=i-2;j++){
		Delete_SequenQueue(Q,a1);     //���ӵ�i�е�һ��Ԫ�� 
		cout<<a1;
		if(a1<10){
			cout<<"   ";
		}else if(a1<100){
			cout<<"  ";
		}else{
		cout<<" ";	
		} 
		GetFront_SequenQueue(Q,a2);    //����`ȡ��i��Ԫ��(n>=2) 
		Enter_SequenQueue(Q,a1+a2);	    
		}
		Delete_SequenQueue(Q,a2);       //�ӵ�ֵ����� 
		cout<<a2<<endl;
		Enter_SequenQueue(Q,1);        // ��ӵ�i+1�����һ�� 1 
	}		
}


int main(){
	int n;
	cin>>n;
	YHTriangle(n);	
} 

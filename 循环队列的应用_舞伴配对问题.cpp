#include<iostream>
using namespace std;
const int MAXSIZE=1024;



typedef struct SequenQueue{     //顺序队列---循环队列 
	string data[MAXSIZE];
	int front;
	int rear;
}SequenQueue;

SequenQueue *Init_SequenQueue(){
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

int Enter_SequenQueue(SequenQueue *Q,string x){       //入队
	if(!SequenQueue_Full(Q)){
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%MAXSIZE;
		return 1;
	}else{
		return 0;
	} 
}

int Delete_SequenQueue(SequenQueue *Q,string &x){       //出队 
	if(!SequenQueue_Empty(Q)){
	x=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return 1;
	}else{
		return 0;
	}
}

int GetFront_SequenQueue(SequenQueue *Q,string &x){      //获取对头元素 
	if(!SequenQueue_Empty(Q)){
	x=Q->data[Q->front];
	return 1;
	}else{
		return 0;
	}
} 

typedef struct Person{
	string name;
	char sex;
}person;

void DancePartner(Person *dancer,int num){
	person p;
	SequenQueue *FemaleDancers,*MaleDancers;
	FemaleDancers=Init_SequenQueue();
	MaleDancers=Init_SequenQueue();
	for(int i=0;i<num;i++){
		if(dancer[i].sex=='F')
		Enter_SequenQueue(FemaleDancers,dancer[i].name);
		else
		Enter_SequenQueue(MaleDancers,dancer[i].name);	
			
	}
	cout<<"舞队中的舞伴是:"<<endl;
	cout<<"女士\t男士\n";
	while(!SequenQueue_Empty(FemaleDancers)&&!SequenQueue_Empty(MaleDancers)){
	Delete_SequenQueue(FemaleDancers,p.name);
	cout<<p.name<<'\t';
	Delete_SequenQueue(MaleDancers,p.name);
	cout<<p.name<<endl;;	
	}
	if(!SequenQueue_Empty(FemaleDancers)){
	GetFront_SequenQueue(FemaleDancers,p.name);
	cout<<"女士:"<<p.name<<"下一次最先匹配舞伴";
	}
	if(!SequenQueue_Empty(MaleDancers)){
	GetFront_SequenQueue(MaleDancers,p.name);
	cout<<"男士"<<p.name<<"下一次最先匹配舞伴";	
	} 
}  
	


int main(){
	int n;
	cin>>n;
	person dancer[n];
	for(int i=0;i<n;i++){
		cin>>dancer[i].name>>dancer[i].sex;
	}
	DancePartner(dancer,n);
} 

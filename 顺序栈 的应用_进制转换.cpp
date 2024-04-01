#include<iostream>
using namespace std;

const int MAXSIZE=1024;
typedef struct SequenStack{            //˳��ջ 
	int data[MAXSIZE];
	int top;
}SequenStack; 

SequenStack* Init_SequenStack(){         // ��ʼ�� 
	SequenStack *s;
	s=new SequenStack;
	s->top=-1;
	return s;
}

int SequenStack_Empty(SequenStack *s){     //�п� 
	if(s->top==-1) {
		return 1; 
	}else{
		return 0;
	} 
}

int SequenStack_Full(SequenStack *s){        //���� 
	if(s->top==MAXSIZE-1){
		return 1;
	}else{
		return 0;
	}
}

int Push_SequenStack(SequenStack *s,int x){         //��ջ 
	if(SequenStack_Full(s)){
	return 0;	
	}
	s->data[++(s->top)]=x;
	return 1; 
}

int Pop_SequenStack(SequenStack *s,int &x){              //������ջ 
	if(SequenStack_Empty(s)){
		return 0;
	}
	else{
		x=s->data[(s->top)--];
		return 1;
	}
}

int GetTop_SequenStack(SequenStack *s,int &x){       //��ȡջ��Ԫ�� 
	if(SequenStack_Empty(s)){
		return 0;
	}else{
	x=s->data[s->top];
	return 1; 	
	}
}


void Print_result(SequenStack *s,int r,int n){        //���ת����� 
	if(n==0){
		cout<<0<<'('<<r<<')'<<endl;
	}else{
		while(!SequenStack_Empty(s)){
		int top;
		GetTop_SequenStack(s,top);
			if(top>=10){
				cout<<(char)(top-10+'A');	
			}else{
				cout<<top;
			}
		Pop_SequenStack(s,top);
		}
		cout<<"("<<r<<")"; 
	}	
} 

SequenStack* Conversion(int n,int r){              //ת��Ϊr����ѹ�� 
	SequenStack *s;
	s=Init_SequenStack();
	
	while(n>0){
	Push_SequenStack(s,n%r);
	n/=r;	
	}	
	return s;
}


int main(){             
	int n,r;
	cout<<"������������Ҫת�������ͽ���(<=36����):"<<endl;
	cin>>n>>r;
	cout<<"ת����Ϊ:"<<endl;
	SequenStack *s;
	s=Conversion(n,r);
	Print_result(s,r,n);
	return 0;
}

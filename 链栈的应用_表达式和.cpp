#include<iostream>
using namespace std;
#include <string>

typedef struct LinkedStackNode{
	int data;
	char soperator;
	struct  LinkedStackNode *next;
	int type;
}LinkedStackNode,*LinkedStack;


LinkedStack Init_LinkedStack(){      //��ʼ�� 
	LinkedStack top;
	top=new LinkedStackNode;
	top->next=NULL;
	return top;
}



void Push_LinkedStack(LinkedStack top,string &ss){	     //����׺���ʽ�ַ���,�õ�����洢 
	int cnt=0,t;
	for(int i=0;i<ss.size();i++){
		if(ss[i]>='0'ss[i]<='9'){
			while(ss[i]>='0'&&ss[i]<='9'){
			t=ss[i]-'0';
			cnt=cnt*10+t;
			i++;	
			}LinkedStackNode *node;
			node=new LinkedStackNode;
			node->data=cnt;
			node->type=0;
			node->next=top->next;
			top->next=node;
			cnt=0;			
		}
		if(ss[i]!=' '){
		LinkedStackNode *node;
		node=new LinkedStackNode;
		node->soperator=ss[i];
		node->type=1;
		node->next=top->next;
		top->next=node;
		}
		
		}
}

void Push_LinkedStack1(LinkedStack top,int x){         //��ջ 
	LinkedStackNode *node;
	node=new LinkedStackNode;
	node->data=x;
	node->next=top->next;
	top->next=node;
}
				


int Pop_LinkedStack(LinkedStack top,int &x){               //��ջ 
	LinkedStackNode *node;
	
	if(top->next!=NULL){
		node=top->next;
		x=node->data;
		top->next=node->next;
		delete(node);
		return 1;
	}else{
		return 0;
	}
}
 

int  SumOperate(int ooperator1,int ooperator2,char ooperator){      //������������ 
	int result;
	switch(ooperator){
		case'+':result=ooperator1+ooperator2;break;
		case'-':result=ooperator1-ooperator2;break;
		case'*':result=ooperator1*ooperator2;break;
		case'/':result=ooperator1/ooperator2;break;
	}
	return result;
}

void Claculate(LinkedStack s,char ooperator){       //ȡ�������� 
	int ooperator1=0,ooperator2=0;
	int result;
	Pop_LinkedStack(s,ooperator2);
	Pop_LinkedStack(s,ooperator1);
	result=SumOperate(ooperator1,ooperator2,ooperator);
	Push_LinkedStack1(s,result);
}

void EvalauatePE(LinkedStack top,int &result){         //��������ȡ��������,�����ջ 
	LinkedStackNode *node;
	LinkedStack s;
	node=top->next;
	s=Init_LinkedStack();
	while(node!=NULL){
		if(node->type==0){
		Push_LinkedStack1(s,node->data);	
		}else{
		Claculate(s,node->soperator);	
		}
		node=node->next;
	}
	Pop_LinkedStack(s,result);	
}

void reverse(LinkedStack top){         //��ת ������ 
	LinkedStack p,q;
	p=top->next;
	top->next=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=top->next;
		top->next=q;
	} 
}

int main(){
	void add(int x,string &s);     //���(��)����   
	void  solve(char c,string &s); //�ƶ��������� 
	void move(int x,string &s);    //ȥ������ 
	string GetBack(string &s);  //��ȡ��׺���ʽ�ַ��� 
	LinkedStack top;
	top=Init_LinkedStack();
	cout<<"��������ʽ:"; 
	string s;
	cin>>s;
	string ss;	
	ss=GetBack(s);
	cout<<"ת����׺���ʽΪ:"<<ss<<endl;
	 
	Push_LinkedStack(top,ss);   //����׺���ʽ�õ�����洢
	
	cout<<"�õ�������Ϊ:"; 
	LinkedStack p=top->next;    //������� 
    while(p!=NULL){
		 if(p->type==0){
    	cout<<p->data<<'\t';
	} else{
		cout<<p->soperator<<'\t';
	}
        p=p->next;	
	}
	cout<<endl;
	
	reverse(top);               //��ת
	 
	int result;
	EvalauatePE(top,result);    //������ 
	cout<<result;               //������ 
	return 0;
}

/*��׺ת��׺���� ���º������*/ 
void add(int x,string &s)            
{
	for(int i=x-1;i>=0;i--)
	{
		if(s[i]==')')
		{
			int ans1=0,ans2=0;
			for(int j=i;j>=0;j--)
			{
				if(s[j]==')')
				ans1++;
				else if(s[j]=='(')
				ans2++;
				if(ans1==ans2)
				{
					s.insert(j,1,'(');
					break;
				}
			}
			break;
		}
		else
		{
			for(int j=i;j>=0;j--)
			{
				if(s[j]==')'||s[j]=='('||s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/')
				{
					s.insert(j+1,1,'(');
					break;
				}
				else if(j==0&&(s[j]>='0'&&s[j]<='9'))
				{
					s.insert(0,1,'(');
					break;
				}
			}
			break;
		}
	}
	x++;
	for(int i=x+1;i<s.length();i++)
	{
		if(s[i]=='(')
		{
			int ans1=0,ans2=0;
			for(int j=i;j<s.length();j++)
			{
				if(s[j]==')')
				ans1++;
				else if(s[j]=='(')
				ans2++;
				if(ans1==ans2)
				{
					s.insert(j+1,1,')');
					break;
				}
			}
			break;
		}
		else
		{
			for(int j=i;j<s.length();j++)
			{
				if(s[j]==')'||s[j]=='('||s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/')
				{
					s.insert(j,1,')');
					break;
				}
				else if(j==(s.length()-1)&&(s[j]>='0'&&s[j]<='9'))
				{
					s.insert(s.length(),1,')');
					break;
				}
			}
			break;
		}
	}
}

void  solve(char c,string &s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==c)
		{
			add(i,s);
			i++; 			
		}
	}	
} 
void move(int x,string &s)
{
	int ans1=0,ans2=0;
	for(int i=x+1;i<s.length();i++)
	{
		if(s[i]=='(')
		ans1++;
		else if(s[i]==')')
		ans2++;
		if(ans2-ans1==1)
		{
			s.insert(i+1,1,s[x]);
			s[x]=' ';
			return;
		}
	}
}

string GetBack(string &s){
	solve('*',s);
	solve('/',s);
	solve('+',s);
	solve('-',s);
	for(int i=s.length()-1;i>=0;i--)
	{
	if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			move(i,s);
		}
	}
	string t="";
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='('||s[i]==')')continue;
		t+=s[i];
	} 
	return t; 
}








 

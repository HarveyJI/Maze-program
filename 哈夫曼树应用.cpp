#include<iostream>
#include<string.h>
using namespace std;
int num[10]; 
typedef char** HCode;
typedef struct HNode{
	char Fh; 
	int weight;
	int parent,lchild,rchild;
}HNode,*HTree;

void CreatHFTree(HTree &HT,int n){
	HT=new HNode[100];
	int N=2*n-1;              //n��Ҷ����Ҫ2n-1���
	int i,j;
	for(i=0;i<n;i++){           //���������Ȩֵ 
		cin>>HT[i].Fh>>HT[i].weight;
	}
	for(i=0;i<N;i++){                       //��ʼ��Ϊ-1 
		HT[i].parent=HT[i].lchild=HT[i].rchild=-1;
	}
	for(j=n;j<N;j++){
		int min1=100,min2=100;
		int  p1=0,p2=0;
		for(i=0;i<j;i++){             //������С����Ȩֵ�Լ�����Ӧ���±�; 
			if(HT[i].parent==-1){        //û�����ʹ�
				if(min1>HT[i].weight){
					min2=min1;           p2=p1;
					min1=HT[i].weight;   p1=i;
				}else{
					if(min2>HT[i].weight){
						min2=HT[i].weight;
						p2=i;
					}	
				} 
			}			
		}
		HT[j].weight=min1+min2;  //�ҵ�����СȨֵ����Ϊ���Һ��� 
		HT[j].lchild=p1;         
		HT[j].rchild=p2;
		HT[p1].parent=HT[p2].parent=j;   //���ı亢�ӵ�˫�� 
	}
}


HCode HFTreeCoding(HTree HT,int n){
	HCode HC;
	char *cd;
	int start,i,c,f;
	HC=new char*[n+1];       //ָ�����ָ��        
	cd=new char[n];          //ָ���ַ��������ָ��      
	cd[n-1]='\0';
	cout<<"��Ӧ�ַ�����������Ϊ:"<<endl; 
	for(i=0;i<n;++i){
		start=n-1;               
		for(c=i,f=HT[i].parent;f!=-1;c=f,f=HT[f].parent){
			if(HT[f].lchild==c){
				cd[--start]='0';   
			}else{
				cd[--start]='1';   	
			}   
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);	 
		cout<<HT[i].Fh<<'\t'<<HT[i].weight<<'\t'<<HC[i]<<endl;  
	}
	delete cd;
	return HC;           
}

void  HFTreeUnCoding(HTree HT,int n){
	   char m[100];
	   cout<<"������01�����ƴ�:"<<endl; 
	   cin>>m;
	   int len=strlen(m),j=n*2-1-1;    //n��Ҷ�ӵĹ�������,��Ҫ2n-1�������Ž��,���������һ��; 
	   for(int i=0;i<len;i++){
	   		if(m[i]=='0'){           //�����0������ 
				j=HT[j].lchild;	
			}else{
				j=HT[j].rchild;
			}
			if(HT[j].lchild==-1){       //�ж��Ƿ���Ҷ��
				cout<<HT[j].Fh;
				j=n*2-1-1;       //����    
			}	
		}	   
}

int count(){
	char ch[100];
	cin>>ch;
	int len=strlen(ch);
	for(int i=0;i<len;i++){
		int n=0;
		if(ch[i]>='a'&&ch[i]<='z'){
			n=(int)ch[i]-97;
		}else if(ch[i]>='A'&&ch[i]<='Z'){
			n=(int)ch[i]-97;
		}
		num[n]++;
	}  
}

void Print(HTree HT,int n){
	cout<<"����\t���\tȨֵ\t˫��\t����\t�Һ���"<<endl;
	for(int i=0;i<2*n-1;i++){
		cout<<HT[i].Fh<<'\t'<<i<<'\t'<<HT[i].weight<<'\t'<<HT[i].parent<<'\t'
			<<HT[i].lchild<<'\t'<<HT[i].rchild<<endl;
	} 
}


int main(){
/*���� 
8
A 5
B 29
C 7
D 8
E 14
F 23
G 3
H 11*/
	 
	HTree Ht;
	int n;
	cin>>n;
	CreatHFTree(Ht,n);
	Print(Ht,n);
	cout<<endl; 
	HFTreeCoding(Ht,n);
	cout<<endl; 
	HFTreeUnCoding(Ht,n); 
	return 0;
} 

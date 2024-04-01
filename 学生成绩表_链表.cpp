#include<iostream>
#include<string.h>
using namespace std;
typedef struct courseNode{
	int	 dates;
	int  java;
	int	 dateb;
	int total; 
}course; 

typedef struct StudentNode{
    char sno[10];
	char name[8];
	char sex[4];
	char classIn[8];
	course score;
    StudentNode *next;
}Student,StudentNode;




Student* CreatStudentLinkList()                               //����ѧ����
{
   Student *head;
   Student *p;
    head=new Student;
    head->next=NULL;
    cout<<"��¼����Ϣ:(����end����)"<<endl;
	cout<<"ѧ��\t"<<"����\t"<<"�Ա�\t"<<"�༶\t"<<"���ݽṹ\t"
		<<"���ݿ�\t"<<"\tJAVA"<<"\t�ܷ�"<<endl;
    while(1){
    p=new Student;
	cin>>p->sno;    
	if(!strcmp(p->sno,"end")){
		delete p;
		break;
	}else{
	cin>>p->name>>p->sex>>p->classIn>>p->score.dateb>>p->score.java>>p->score.dates;	
	p->score.total=p->score.dateb+p->score.dates+p->score.java;
	}
	p->next=head->next; 
	head->next=p;
	}
    return head;
}


void Print_Student(Student* head){                //����ܷ�                        //���ѧ����
    Student *p=head->next;
    while(p!=NULL){
        cout<<p->sno<<'\t'<<p->name<<'\t'<<p->sex<<'\t'<<p->classIn<<'\t'<<p->score.dateb
		<<"\t\t"<<p->score.java<<"\t\t"<<p->score.dates<<'\t'<<p->score.total<<endl;
        
		p=p->next;
    }
}

void Search_Student(Student* head){     //��ѧ�Ų���ѧ�� 
    Student *p;
    char key[10];
	cout<<"������Ҫ���ҵ�ѧ����ѧ��:"<<endl; 
	cin>>key;
    p=head->next;
    while(p){
        if(strcmp(p->sno,key)==0){
             break;
        }else{
         p=p->next;  
        }
    }
	if(p!=NULL){
	cout<<p->name<<endl;
	}else{
	cout<<"����ʧ��!"<<endl; 
	}   
}

int Student_Length(Student *head){         //ͳ��ѧ������ 
    Student *p;
    int cnt=0;
    p=head->next;
    while(p){
        cnt++;
        p=p->next;
    } 
    return cnt;
}
 
Student* Getdate_Student(Student* head,int i){    //��ȡ��i��ѧ����Ϣ 
    Student *p;
    p=head->next;
    int j=1;
    while(p!=NULL){
     if(i==j){
         break;
     }else{
        p=p->next;
     }
     j++;   
    }
	return p;
}

void InsertAfter_Student(Student* head){    //������ѧ�� 
	cout<<"���ڲ���:(��end����)"<<endl;
	cout<<"ѧ��\t"<<"����\t"<<"�Ա�\t"<<"�༶\t"<<"���ݽṹ\t"
		<<"���ݿ�\t"<<"\tJAVA"<<endl;
	while(1){
	Student *s=new StudentNode;
	cin>>s->sno;
	if(!strcmp(s->sno,"end")){
		delete s;
		break;
	}
	cin>>s->name>>s->sex>>s->classIn
	>>s->score.dateb>>s->score.java>>s->score.dates;
	s->score.total=s->score.dateb+s->score.dates+s->score.java;
	s->next=head->next;
    head->next=s;	
	} 
	
}


int Delete_Student(Student* head){       //��ѧ��ɾ�� 
    cout<<"������Ҫɾ��ѧ����ѧ��:(��end����)" ;
	while(1){
	Student *p,*r;
    char key[10]; 
	cin>>key;
	if(!strcmp(key,"end")){
		break; 
	} 
    p=head;
    while(p){
        if(p->next!=NULL&&strcmp(p->next->sno,key)==0){
             break;
        }else{
         p=p->next;  
        }
    }
	if(p==NULL||p->next==NULL){
        cout<<key<<"����ʧ��!"<<endl;
		continue;	
    }
    r=p->next;
    p->next=r->next;
    delete(r); 	
	} 
    return 1; 
}
  

int Partition(Student a[],int i,int j){   //��ÿ�������һ���ؼ���λ��     
	int temp=a[i].score.total;
	Student ttemp=a[i]; 
	while(i<j){
		while(a[j].score.total>=temp&&i<j){
		j--;
		}
		if(i<j){
			a[i++]=a[j];
		}
		while(a[i].score.total<=temp&&i<j){
		i++;
		}
		if(i<j){
			a[j--]=a[i];
		}
	}
	a[i]=ttemp; 
	return i;
}
void QuickSort(Student a[],int i,int j){
	int k; 
	if(i<j){
		k=Partition(a,i,j);  
		QuickSort(a,i,k-1);   // ����ǰ�� 
		QuickSort(a,k+1,j);   //  ������ 
		
	}
}  

void chang(Student sTab[],Student* head){
	Student* p;
	p=head->next;
	int i=1;
	while(p){
	strcpy(sTab[i].classIn,p->classIn);
	strcpy(sTab[i].name,p->name);
	sTab[i].score.dates=p->score.dates;
	sTab[i].score.dateb=p->score.dateb;
	sTab[i].score.java=p->score.java;
	sTab[i].score.total=p->score.total;
	strcpy(sTab[i].sex,p->sex);
	strcpy(sTab[i].sno,p->sno);
	p=p->next;
	i++;	
	}
}

void print_Sort(Student a[],int n){          //������� 
	for(int i=n;i>=1;i--){
		cout<<a[i].sno<<" ";
	}cout<<endl;
}


int main(){
	/*
	1001 ���� �� һ�� 89 98 99
	1002 ���� �� ���� 100 89 100
	1003 ���� �� һ�� 100 87 99
	1004 ���� Ů ���� 100 99 100 
	1005 ���� Ů ���� 90 88 100 
	1006 mary Ů һ�� 90 90 90
	1007 jack �� ���� 80 99 100
	1008 peter �� ���� 80 100 98
	
	1009 �ž� Ů һ�� 88 89 80
	1010 ���� �� ���� 89 90 78 
	*/
	Student *sTab;
	sTab=CreatStudentLinkList();Print_Student(sTab);cout<<endl;   //����
	
	InsertAfter_Student(sTab);Print_Student(sTab);cout<<endl;     //����
	
	Delete_Student(sTab);Print_Student(sTab);cout<<endl; 	      //ɾ��

	Search_Student(sTab);                                         //˳�����
	
	Student sTab_sz[100];
	chang(sTab_sz,sTab);
	QuickSort(sTab_sz,1,Student_Length(sTab));
	cout<<"--------�����-------------"<<endl; 
	print_Sort(sTab_sz,Student_Length(sTab));                     //����
	cout<<endl;
	
	return 0;

} 

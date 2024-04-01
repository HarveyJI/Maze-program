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




Student* CreatStudentLinkList()                               //创建学生表
{
   Student *head;
   Student *p;
    head=new Student;
    head->next=NULL;
    cout<<"请录入信息:(输入end结束)"<<endl;
	cout<<"学号\t"<<"姓名\t"<<"性别\t"<<"班级\t"<<"数据结构\t"
		<<"数据库\t"<<"\tJAVA"<<"\t总分"<<endl;
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


void Print_Student(Student* head){                //输出总分                        //输出学生表
    Student *p=head->next;
    while(p!=NULL){
        cout<<p->sno<<'\t'<<p->name<<'\t'<<p->sex<<'\t'<<p->classIn<<'\t'<<p->score.dateb
		<<"\t\t"<<p->score.java<<"\t\t"<<p->score.dates<<'\t'<<p->score.total<<endl;
        
		p=p->next;
    }
}

void Search_Student(Student* head){     //按学号查找学生 
    Student *p;
    char key[10];
	cout<<"请输入要查找的学生的学号:"<<endl; 
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
	cout<<"查找失败!"<<endl; 
	}   
}

int Student_Length(Student *head){         //统计学生个数 
    Student *p;
    int cnt=0;
    p=head->next;
    while(p){
        cnt++;
        p=p->next;
    } 
    return cnt;
}
 
Student* Getdate_Student(Student* head,int i){    //获取第i个学生信息 
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

void InsertAfter_Student(Student* head){    //表后插入学生 
	cout<<"正在插入:(以end结束)"<<endl;
	cout<<"学号\t"<<"姓名\t"<<"性别\t"<<"班级\t"<<"数据结构\t"
		<<"数据库\t"<<"\tJAVA"<<endl;
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


int Delete_Student(Student* head){       //按学号删除 
    cout<<"请输入要删除学生的学号:(以end结束)" ;
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
        cout<<key<<"插入失败!"<<endl;
		continue;	
    }
    r=p->next;
    p->next=r->next;
    delete(r); 	
	} 
    return 1; 
}
  

int Partition(Student a[],int i,int j){   //找每次排序第一个关键字位置     
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
		QuickSort(a,i,k-1);   // 排序前半 
		QuickSort(a,k+1,j);   //  排序后半 
		
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

void print_Sort(Student a[],int n){          //输出排序 
	for(int i=n;i>=1;i--){
		cout<<a[i].sno<<" ";
	}cout<<endl;
}


int main(){
	/*
	1001 李四 男 一班 89 98 99
	1002 张三 男 二班 100 89 100
	1003 赵六 男 一班 100 87 99
	1004 王五 女 二班 100 99 100 
	1005 麻七 女 三班 90 88 100 
	1006 mary 女 一班 90 90 90
	1007 jack 男 三班 80 99 100
	1008 peter 男 三班 80 100 98
	
	1009 九九 女 一班 88 89 80
	1010 巴萨 男 二班 89 90 78 
	*/
	Student *sTab;
	sTab=CreatStudentLinkList();Print_Student(sTab);cout<<endl;   //创建
	
	InsertAfter_Student(sTab);Print_Student(sTab);cout<<endl;     //插入
	
	Delete_Student(sTab);Print_Student(sTab);cout<<endl; 	      //删除

	Search_Student(sTab);                                         //顺序查找
	
	Student sTab_sz[100];
	chang(sTab_sz,sTab);
	QuickSort(sTab_sz,1,Student_Length(sTab));
	cout<<"--------排序后-------------"<<endl; 
	print_Sort(sTab_sz,Student_Length(sTab));                     //快排
	cout<<endl;
	
	return 0;

} 

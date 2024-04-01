#include<iostream>
using namespace std;
#include<algorithm>
#include<vector> 
typedef struct Node{
    float coef;
    int exp;
}Node;

typedef Node elemtype; 

typedef struct Pnode{                
    elemtype date;
    Pnode *next;
}PolyList;


PolyList* Creat_PolyList_Tail()          //尾插建表 
{
    PolyList *head,*p,*tail;
    head=new PolyList;
    head->next=NULL;
    tail=head; 
    cout<<"请依次输入系数与指数并以结束:"<<endl; 
    int ic,ie;
	cin>>ic>>ie;
    while(ic!=0.0){
    p=new PolyList;
    p->date.coef=ic;
    p->date.exp=ie; 
    p->next=tail->next;
    tail->next=p;
    tail=p;
	cin>>ic>>ie;  
    }
    return head;
}

void PolyList_Add(PolyList *PLA,PolyList *PLB){         //计算合并 
    PolyList *pa,*pb,*tail,*s;
    pa=PLA->next;
    pb=PLB->next;
    tail=PLA;
    PLB->next=NULL;
    while(pa!=NULL&&pb!=NULL){
        if(pa->date.exp<pb->date.exp){
            tail->next=pa;
            tail=pa;
            pa=pa->next;
        }else if(pb->date.exp<pa->date.exp){
            tail->next=pb;
            tail=pb;
            pb=pb->next;
        }else{
            int sum;
            sum=pa->date.coef+pb->date.coef;
    		if(sum==0){
	            s=pa; 
	            pa=pa->next;
	            delete(s);
	            s=pb;
	            pb=pb->next;
	            delete(s);
	        }else{
	            pa->date.coef=sum;
	            tail->next=pa;
	            tail=pa;
	            pa=pa->next;
	            s=pb;
	            pb=pb->next;
	            delete(s);
	            }
        }
    }
    if(!pa&&!pb){
        tail->next=NULL;
    }
    if(pa!=NULL){
        tail->next=pa;
    }
    if(pb!=NULL){
        tail->next=pb;
    } 
}


	PolyList* fun(PolyList *L)        //升序排序单链表 
{
	PolyList *p, *q;
	int ti,te;;
	p = L->next;
	while(p!=NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			if (p->date.exp > q->date.exp)
			{
				te= p->date.exp;
				ti= p->date.coef;;
				
				p->date.exp = q->date.exp;
				p->date.coef=q->date.coef;
				
				q->date.exp = te;
				q->date.coef=ti;
				
			}
			q = q->next;
		}
		p = p->next;
 
	}
	return L;
} 

void Print_PolyList(PolyList* p){                 //输出 
    if(p==NULL)
    {
        return;
    }else{
    cout<<p->date.coef<<"X^"<<p->date.exp;
    if(p->next!=NULL){
        cout<<"+";
    }
    Print_PolyList(p->next);
    }
}

int main(){
    PolyList *PLA,*PLB;
    PLA=Creat_PolyList_Tail();
    PLB=Creat_PolyList_Tail();
    fun(PLA);
    fun(PLB);
    PolyList_Add(PLA,PLB);
    Print_PolyList(PLA->next);
    return 0;
} 

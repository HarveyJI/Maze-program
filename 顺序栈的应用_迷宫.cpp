#include<iostream>
using namespace std;
const int MAXSIZE=1024;
int maze[15][15];
int dir[5][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};
typedef struct {
	int x;
	int y;
	int dir;
}SElmemType; 
typedef struct SequenStack{
	int top;
	SElmemType data[MAXSIZE];
}SequenStack;

 

SequenStack* Init_SequenStack(){
	SequenStack *s;
	s=new SequenStack;
	s->top=-1;
	return s;
}

int SequenStack_Empty(SequenStack *s){
	if(s->top==-1) {
		return 1; 
	}else{
		return 0;
	} 
}

int SequenStack_Full(SequenStack *s){
	if(s->top==MAXSIZE-1){
		return 1;
	}else{
		return 0;
	}
}

int Push_SequenStack(SequenStack *s,SElmemType q){
	if(SequenStack_Full(s)){
	return 0;	
	}
	s->data[++(s->top)].x=q.x;
	s->data[(s->top)].y=q.y;
	s->data[(s->top)].dir=q.dir;
	return 1; 
}

int Pop_SequenStack(SequenStack *s,SElmemType &q){
	if(SequenStack_Full(s)){
		return 0;
	}
	else{
		q.dir=s->data[(s->top)--].dir;
		q.y=s->data[(s->top)].y;
		q.x=s->data[(s->top)].x;
		return 1;
	}
}

int GetTop_SequenStack(SequenStack *s,SElmemType &q){
	if(SequenStack_Empty(s)){
		return 0;
	}else{
	q.dir=s->data[(s->top)].dir;
	q.y=s->data[(s->top)].y;
	q.x=s->data[(s->top)].x;
	return 1; 	
	}
}

int Path(SequenStack *s,int x,int y){
	int xx,yy,dd,i,j,trytime;
	SElmemType temp;
	SElmemType tryPath;
	temp.x=x;
	temp.y=y;
	temp.dir=0;
	Push_SequenStack(s,temp);
	while(!SequenStack_Empty(s)){
		
	GetTop_SequenStack(s,temp);
	xx=temp.x;
	yy=temp.y;
	dd=temp.dir+1;
	trytime=0;
	while(dd<=4){
		i=xx+dir[dd][0];
		j=yy+dir[dd][1];
		
		if(maze[i][j]==0||maze[i][j]==9){
			if(trytime==0){
			Pop_SequenStack(s,tryPath);
			tryPath.dir=dd;
			Push_SequenStack(s,tryPath);
			trytime++;
			}
			temp.x=i;
			temp.y=j;
			temp.dir=1;
			Push_SequenStack(s,temp);
			xx=i;
			yy=j;
			   
				if(maze[i][j]==9){
				return 1;
				}
				else{
				dd=1;
				}
				maze[i][j]=-1;
		}else{
			dd++;
			trytime=0;
			}
		
		
		}if(dd==5&&!SequenStack_Empty(s)){
		Pop_SequenStack(s,temp);
		}
	}return 0;
		
	}
	
		

int main(){             
	SequenStack *s;
	s=Init_SequenStack();
	int n,m,x,y;
	cout<<"请输入迷宫大小:"<<endl; 
	cin>>n>>m;
	cout<<"请创建"<<n<<"X"<<m<<"的迷宫:"<<endl;
	cout<<"2为入口,9为出口!"<<endl; 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>maze[i][j];
			}	
	}
	for(int ii=0;ii<n;ii++)
	{
		for(int jj=0;jj<m;jj++)
		{
			if(maze[ii][jj]==2){
				x=ii;
				y=jj;
			}
			}	
	}
	Path(s,x,y);
	
	

	 for(int iii=0;iii<n;iii++)
	{
		for(int jjj=0;jjj<m;jjj++)
		{
			cout<<maze[iii][jjj]<<'\t';
		}
		cout<<endl;
	}
	return 0;
}


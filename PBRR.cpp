#include<iostream>
#include <algorithm> //for using the comparator function
#include <queue> //for implementing queue DS


using namespace std;

//ye structure hai jo process table store krega
struct process
{
  int pid;
  int bt;
  int prior;
  int start_time;
  int bt_rem;
}ps[100];

//for sorting on the basis of priority
bool comparatorPrior(struct process a,struct process b)
{
   int x =a.prior;
   int y =b.prior;
   return x < y;
}
//for sorting on the basis of burst time
bool comparatorBT(struct process a,struct process b)
{
   int x =a.bt_rem;
   int y =b.bt_rem;
   return x < y;
}


bool comparatorPID(struct process a,struct process b)
{
   int x =a.pid;
   int y =b.pid;
   return x < y;
}

int main()
{
    
    int n,index,i;
    queue<int> q;
    bool visited[100]={false};
    int curr_time = 0;
    int completed = 0,tq;
    
    cout<<"Enter total number of processes: ";
    cin>>n;    


    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Process " <<i<< " Priority: ";
        cin >> ps[i].prior;
        ps[i].pid=i;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Process " <<i<< " Burst Time: ";
        cin >> ps[i].bt;
        ps[i].bt_rem= ps[i].bt;
    }
    
    cout<<"\nEnter time quantum: ";
    cin>>tq;
    
    
   sort(ps,ps+n,comparatorPrior); //pehle sort krlia process table ko
   
  
    
    while(completed != n) 
    {
      for(i=0;i<n;i++){
      	
      	q.push(i);
      	visited[i]=true;
      	index=q.front();
      	if(ps[index].bt_rem>0){
		 	cout<<ps[index].bt_rem<<"-----";  
			} 
        q.pop();
      	
      if(ps[index].bt_rem>tq)
      {    
            ps[index].bt_rem -= tq;
            curr_time += tq;
      }
      else if(ps[index].bt_rem<=tq)
      {
            curr_time += ps[index].bt_rem;
            ps[index].bt_rem = 0;
            completed++;

      }

    
}//for

sort(ps,ps+n,comparatorBT);
continue;
}//while
	 
      
      









        

   return 0;
}
   
    
    
    
    

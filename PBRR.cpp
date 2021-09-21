#include<iostream>
#include <algorithm> //for using the comparator function
#include <queue> //for implementing queue DS


using namespace std;

//ye structure hai jo process table store krega(all info abt a process)
struct process
{
  int pid;
  int bt;
  int prior;
  int start_time;
  int bt_rem;
  int tat,wt;
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

//process id's ko simultaneously sort krne k liye
bool comparatorPID(struct process a,struct process b)
{
   int x =a.pid;
   int y =b.pid;
   return x < y;
}

int main()
{
    
    int n,index,i,context=-1,tq;
    queue<int> q; //ready queue
    int curr_time = 0; //to track the current time in the gantt chart
    int completed= 0; //to check if the process is completed or not
    float sum_tat=0,sum_wt=0;
    
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
    cout<<endl;
    
    
   sort(ps,ps+n,comparatorPrior); //pehle sort krlia process table ko on the basis of the priorities assigned by the user
   
  
 
for(i=0;i<n;i++){
      	//pehle process ko push kia in the ready queue
      	
      	q.push(i);
      	index=q.front();
      	
      	//if it has some burst time remaining
      	
      	if(ps[index].bt_rem>0)
		  {
		 	cout<<ps[index].bt_rem<<"-----";  
			} 
		
		// process ko ready queue se nikalkr execute kia
        q.pop();
        
        //two cases arise: either bt<tq or bt>=tq
      	
      if(ps[index].bt_rem>tq)
      {    
            ps[index].bt_rem -= tq;
            curr_time += tq;
           
            
      }
      else if(ps[index].bt_rem<=tq && ps[index].bt_rem>0 )
      {
            curr_time += ps[index].bt_rem;
            ps[index].bt_rem = 0;
            completed++; //ye process complete hogya and ab ise dobara queue mei daalne ki koi need nhi hai
            
            ps[index].tat = curr_time; //turnarnd time
            ps[index].wt = ps[index].tat - ps[index].bt; //waiting time
            sum_tat+=ps[index].tat;
            sum_wt+=ps[index].wt;
          
      }
      
//context switching occurs
context++;
}//for

//sorting on the basis of burst time
sort(ps,ps+n,comparatorBT);

//2nd iteration occurs

for(i=0;i<n;i++){
	q.push(i);
	index=q.front();
    if(ps[index].bt_rem>0)
		  {
		 	cout<<ps[index].bt_rem<<"-----";  
		 	context++;
		 	curr_time+=ps[index].bt_rem;
  ps[index].tat = curr_time;
  sum_tat+=ps[index].tat;
  
  
ps[index].wt = ps[index].tat - ps[index].bt; //waiting time
  sum_wt+=ps[index].wt;
  
 ps[index].bt_rem=0;  
		 	
			} 
        q.pop();
           
    
      
}//for

//displaying performance metrics

cout<<endl<<"Context Switches:"<<context;
cout<<endl<<"Average Turnaround Time:"<<sum_tat/n;
cout<<endl<<"Average Waiting Time:"<<sum_wt/n;
   return 0;
}
   
    
    
    
    

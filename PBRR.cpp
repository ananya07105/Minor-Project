#include<iostream>
#include <algorithm> 
#include <queue> 
#include<climits>

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
    
    int n,index;
    queue<int> q;
    bool visited[100]={false},is_first_process=true;
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
   

    q.push(0);  
    visited[0] = true;  
    
    while(completed != n) 
    {
      index = q.front();
	  cout<<ps[index].bt_rem<<"-----";  
      q.pop();
      
      
      
      if(ps[index].bt_rem == ps[index].bt) //we saw this process for the first time
      {
            ps[index].start_time = curr_time;
            is_first_process = false;
             
      }
	  
	  if(ps[index].bt_rem>tq)
      {    
            ps[index].bt_rem -= tq;
            curr_time += tq;
      }
      else 
      {
            curr_time += ps[index].bt_rem;
            ps[index].bt_rem = 0;
            completed++;

      }
    

for(int i = 1; i < n; i++) 
      {
      
          if(ps[i].bt_rem > 0 && visited[i] == false) //agla process konsa enqueue hoga
          { 
            q.push(i);
            visited[i] = true;
          }
      }



      
    
      if( ps[index].bt_rem> 0)//jo process dobara se enqueue hoye the
          q.push(index);
      
          
           
      if(q.empty())
      {
      	
      	  
          for(int i = 0; i < n; i++)
          {
            if(ps[i].bt_rem > 0)
            {
              q.push(i);
              visited[i] = true;
              break;
            }
          }
          
      }      
        
   } //while loop
   return 0;
}
   
***********************************************************************************************
//	sort(ps,ps+n,comparatorBT); //burst time ke basis pe sort krne ke liye
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

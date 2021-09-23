#include<iostream>
#include<queue>

using namespace std; 

// structure for each process
struct process_struct{
	int pid;
	int bt;
	int rem_bt;
	int start_time;
	int tat,wt; 
}ps[100];

int main(){
	int n,tq,index;
	int context=-1;
	queue<int> q; 
	int curr_time=0; //current time on the gaant chart
	int completed=0; //number of completed process
	float sum_tat=0,sum_wt=0; // avg turn around time and avg waiting time
	
	cout<<"Enter Number of Processes: ";
	cin>>n;
	cout<<endl;
	
	for(int i=0;i<n;i++){
		cout<<"Enter Process "<<i<<" Burst Time: ";
		cin>>ps[i].bt;
		ps[i].rem_bt=ps[i].bt;
		ps[i].pid=i;
	}
	
	cout<<"Enter Time Quantum: ";
	cin>>tq;
	
	while(completed!=n){
		for(int i=0;i<n;i++){
			if(ps[i].rem_bt>0){
				q.push(i);
				if(ps[i].rem_bt-tq==0){
					completed++;
					ps[i].tat = curr_time; //turnarnd time
            		ps[i].wt = ps[i].tat - ps[i].bt; //waiting time
            		sum_tat+=ps[i].tat;
            		sum_wt+=ps[i].wt;
				}
				if(ps[i].rem_bt-tq>=0){
					cout<<"P"<<i<<"----";
					curr_time+=tq;
					ps[i].rem_bt-=tq;
					context++;
				}
				else if(ps[i].rem_bt-tq<0 && ps[i].rem_bt>0){
					cout<<"P"<<i<<"----";
					curr_time+=tq;
					ps[i].rem_bt=0;  // indicated that process has been finished
					context++;
					completed++;  // number of finished processes5
					ps[i].tat = curr_time; //turnarnd time
            		ps[i].wt = ps[i].tat - ps[i].bt; //waiting time
            		sum_tat+=ps[i].tat;
            		sum_wt+=ps[i].wt;
				}
			}
			q.pop();
		}
	}
	
	cout<<endl;
	cout<<endl;
	cout<<"Context Switches: "<<context<<endl;
	cout<<"Average Waiting Time:"<<sum_wt/5<<" ms"<<endl;
	cout<<"Average Turn Around Time Time:"<<sum_tat/5<<" ms";
}
#include <iostream>
#include <algorithm>
using namespace std;

struct process
{
	int bt,pr,ct,ta,wt;
	string pro_id;

			  /*
	bt = Burst time,
	ct = Completion time,
	ta = Turn around time,
	wt = Waiting time
	*/

}process;

bool compare(process a,process b)
{
	return a.bt<b.bt;
		 /* This schedule will always return TRUE
if above condition comes*/

}

bool compare2(process a,process b)
{
	return a.pr>b.pr;
	 /* This schedule will always return TRUE
if above condition comes*/

}

int main()
{
	process pro[10];
	int n,i,j;
	cout<<"Enter the number of process:";
	cin>>n;
	cout<<"Enter the process id: ";
	cout<<endl;
    cout<<"Enter the burst time:";
    cout<<endl;
    cout<<"Enter the priority :";
    cout<<endl;
	for(i=0;i<n;i++)
	{
		cin>>pro[i].pro_id;
		cin>>pro[i].bt;
		cin>>pro[i].pr;
	}

	sort(pro,pro+n,compare);

	 /*sort is a predefined function  defined in algorithm.h header file,
it will sort the schedules according to their burst time*/

	pro[0].ct=pro[0].bt;
	pro[0].ta=pro[0].ct-pro[0].bt;
	pro[0].wt=pro[0].ta-pro[0].bt;
	i=1;

	while(i<n-1)
	{

		for(j=i;j<n;j++)
		{
			if(pro[j].bt>pro[i-1].ct)
			break;
		}
		sort(pro+i,pro+i+(j-i),compare2);
		pro[i].ct=pro[i-1].ct+pro[i].bt;
		pro[i].ta=pro[i].ct-pro[i].bt;
		pro[i].wt=pro[i].ta-pro[i].bt;
		i++;
		}
		pro[i].ct=pro[i-1].ct+pro[i].bt;
		pro[i].ta=pro[i].ct-pro[i].bt;
		pro[i].wt=pro[i].ta-pro[i].bt;

	for(i=0;i<n;i++)
	{
		//displaying all the values
		cout<<pro[i].pro_id<<"\t"<<pro[i].bt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<"\t"<<pro[i].pr;
		cout<<endl;
	}
	return 0;
}

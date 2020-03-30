/* 
					LOVELY PROFESSIONAL UNIVERSITY
			Academic Task-3 (Simulation based assignment)
			School of Computer Science and Engineering  
			Faculty of Technology And Sciences 
			Name of the faculty member : Shivani Sharma
			Course Code: CSE316  Course Title: Operating System

			Submitted by : S. Jahnavi Prasad
			Regd.no : 11803179	Section : K18RD	Roll no : 42
			
			Q.no.20 
			Consider that a system has P resources of same type. 
			These resources are shared by Q processes time to time. 
			All processes request and release the resources one at a time. 
			Generate a solution to demonstrate that, 
			the system is in safe state when following conditions are satisfied. Conditions:
 				1.  Maximum resource need of each process is between 1 and P.
 				2. Summation of all maximum needs is less than P+Q  
*/

#include<stdio.h>
int main()
{
	system("COLOR 0E");
	int i,p,q,resource,max_need=0,count=0;
	printf("\n\n\t-------------------------------------------------\n");
	printf("\t|\t\tDEADLOCK DETECTION\t\t|\n");								//Heading
	printf("\t-------------------------------------------------");
	label:	printf("\n\nEnter number of resources available : ");			//resources input
	scanf("%d",&p);
	printf("\nEnter number of processes available : ");						//processes input
	scanf("%d",&q);
	resource=p;
	int process[q],End[q],allot[q];
	for(i=0;i<q;i++)
	{
		printf("\nEnter number of resources required by Process %d\n",i+1);
		scanf("%d",&process[i]);
		End[i]=0;
		allot[i]=0;
	}
	printf("\n\n\t\t\tYOU HAVE\n\n");										//Displaying given data
	printf("\t\tProcess \tResources\n");
	for(i=0;i<q;i++)
	{
		printf("\t\tP%d \t\t%d\n",i+1,process[i]);
		max_need=max_need+process[i];
		if(process[i]<1||process[i]>p)										//checking condition 1
		{
			count++;
		}
	}
	if(max_need<p+q&&count==0) 												//checking condition 2
	{		
		printf("\n\n\t-------------------------------------------------\n");
		printf("\n\n");
		printf("Both conditions are satisfied\n");							//both conditions satisfied
	}
	else
	{
		printf("\n\n\n\t---CONCLUSION---\t");
		printf("\n\nConditions are not satisfied\n");						//one or both conditions failed
		printf("System is in unsafe state \nDead lock : Possible\n\n");
		printf("DO YOU WANT TO CONTINUE:\n");
		printf("Press 1 for main menu\n");
		printf("Press Any other key to Exit\n");
		int ch;
		scanf("%d", &ch);
		if(ch==1)
		{
			goto label;
		}
		else
		return 0;

	}
		while(1)
		{
			count=0;
			for(i=0;i<q;i++)
			{
				if(End[i]==0)
				{
					if(resource>0)
					{
					allot[i]=allot[i]+1;
					resource=resource-1;
					printf("Process %d + 1\n",i+1);
					}
					if(allot[i]==process[i])
					{
						printf("Process %d completed it execution\n",i+1);		//resource allocation to processes 
						End[i]=1;
						resource=resource+process[i];
						printf("Process %d - %d \n",i+1,process[i]);
					}
				}
			}
			for(i=0;i<q;i++)
			{
				if(End[i]==1)
				count++;
			}
			if(count==q)
			break;
		}
		printf("\n\n");
		printf("\t---CONCLUSION---\t");
		printf("\n\n");
		printf("\tNo Dead Lock\n\n");
		printf("DO YOU WANT TO CONTINUE:\n");
		printf("Press 1 for main menu\n");
		printf("Press Any other key to Exit\n");
		int ch;
		scanf("%d", &ch);
		if(ch==1)
		{
			goto label;
		}
		else
		return 0;					
}

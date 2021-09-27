#include<stdio.h>
#include<stdlib.h>
typedef struct
{
int pid;
int btime;
int wtime;
}
sp;
int main()
{
int i,j,n,tbm=0,towtwtime=0,totttime;
sp *p,t;
printf("\n SJF scheduling ..\n");
printf("******************************\n");
printf("Enter the no of processes:");
scanf("%d",&n);
p=(sp*)malloc(sizeof(sp));
printf("Enter the burst time of");
for(i=0;i<n;i++)
{
printf("\n process %d\t",i+1);
scanf("%d",&p[i].btime);
p[i].pid=i+1;
p[i].wtime=0;
}
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
{
if(p[i].btime>p[j].btime)
{
t=p[i];
p[i]=p[j];
p[j]=t;
}}

printf("\n process \tburst time \t waiting time\tTAT\n");
for(i=0;i<n;i++)
{
towtwtime+=p[i].wtime=tbm;
tbm+=p[i].btime;
printf("\nP%d\t\t%d",p[i].pid,p[i].btime);
printf("\t\t%d\t\t%d",p[i].wtime,p[i].wtime+p[i].btime);
}
totttime=tbm+towtwtime;
printf("\n Total waiting time :%d", towtwtime );
printf("\n Average waiting time :%f",(float)towtwtime/n);
printf("\n Total turn around time :%d",totttime);
printf("\n Average turn around time: :%f\n",(float)totttime/n);
}

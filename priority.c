#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
int pno;
int pri;
int btime;
int wtime;
}sp;
int main()
{
int i,j,n;
int tbm=0,totwtime=0,totttime=0;
sp *p,t;
printf("\n PRIORITY SCHEDULING.\n");
printf("**************************\n");
printf("Enter the no of process:");
scanf("%d",&n);
p=(sp*)malloc(sizeof(sp));

for(i=0;i<n;i++)
{
printf("Enter the burst time and priority:\n");
printf("process:%d\n",i+1);
scanf("%d%d",&p[i].btime,&p[i].pri);
p[i].pno=i+1;
p[i].wtime=0;
}
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
if(p[i].pri>p[j].pri)
{
t=p[i];
p[i]=p[j];
p[j]=t;
}
}
printf("\n process\tpriority\tburst time\twaiting time\tTAT\n");
for(i=0;i<n;i++)
{
totwtime+=p[i].wtime=tbm;
tbm+=p[i].btime;
printf("\nP%d\t\t%d\t\t%d",p[i].pno,p[i].pri,p[i].btime);
printf("\t\t%d\t\t%d",p[i].wtime,p[i].wtime+p[i].btime);
}
totttime=tbm+totwtime;
printf("\n total waiting time:%d",totwtime);
printf("\n average waiting time:%f",(float)totwtime/n);
printf("\n total turnaround time:%d",totttime);
printf("\n avg turnaround time:%f\n",(float)totttime/n);
}

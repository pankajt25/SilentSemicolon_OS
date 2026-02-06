#include <stdio.h>
int main(){
int BT[100],AT[100],WT[100],TAT[100],CT[100],n,c,time=0;
float tw=0,tt=0;

printf("Processes & arrival times? ");
scanf("%d %d",&n,&c);

for(int i=0;i<n;i++){
printf("P%d BT: ",i+1);
scanf("%d",&BT[i]);
AT[i]=c?(printf("P%d AT: ",i+1),scanf("%d",&AT[i]),AT[i]):0;
}

for(int i=0;i<n;i++){
if(time<AT[i])time=AT[i];
WT[i]=time-AT[i];
CT[i]=time+BT[i];
TAT[i]=CT[i]-AT[i];
time=CT[i];
tw+=WT[i];
tt+=TAT[i];
}

printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++)
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,AT[i],BT[i],CT[i],TAT[i],WT[i]);

printf("\nAvg WT=%.2f, Avg TAT=%.2f\n",tw/n,tt/n);
}

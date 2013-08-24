#include <stdio.h>
 
int main()
{
	int times,month,day,year,leap;
	int result,rightmonth;
 
    scanf("%d",&times);
	while(times--)
	{	char date[11]={0};
 
	leap=0;
	result=1;
	scanf("%s",date);
	month=(date[0]-'0')*10+date[1]-'0';
	day=(date[3]-'0')*10+(date[4]-'0');
	year=(date[6]-'0')*1000+(date[7]-'0')*100+(date[8]-'0')*10+date[9]-'0';		
 
	if(((year%4==0)&&(year%100)!=0)||year%400==0)
		leap=1;
	if(day>31||month>12||day==0||month==0)
		result=0;
	switch(month)
	{
 
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		rightmonth=31;break;
	case 4:case 6:case 9:case 11: rightmonth=30;break;
	case 2:rightmonth=(leap==1?29:28);break;	
 
	}
	if(day>rightmonth)
		result=0;
 
	if(result)
		printf("Yes\n");
	else
		printf("No\n");
 
 
	}
 
	return 0;
}
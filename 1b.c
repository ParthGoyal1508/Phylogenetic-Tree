#include<stdio.h>
#include<string.h>
int main()
{
	float arr[25][20];
	float min;
	int i,j,x,y,op=0,r=0;
	FILE *input;
	input= fopen("Ndistance.txt","r");
	char nm[100000],a[100000];
	char name[25][10000];
	char  c;
	fscanf(input,"%[^\n]s",nm);
	fscanf(input,"\n");
	x=1;
	for(i=1;i<strlen(nm);i++)
	{	
		if(nm[i]==',') 
		{
			x++;
			j=0;
		}
		else
		{
			name[x][j]=nm[i];
			j++;
		}
	}
	int total=x;
	//for(i=1;i<=total;i++)
	//printf("%s\n",name[i]);
	//fscanf(input,"%[^\n]s",a);
	//fscanf(input,"\n");
	i=1,j=0;
	for(;(c=getc(input))!= EOF;)
	{
		if(c=='\n'||c=='\r')
		{
			i++;
			j=0;
			op=0;

		}
		else if(c==',')
		{
			op=1;
			j++;
			fscanf(input,"%f",&arr[i][j]);
		}
		else if(op==0) continue;
	}
	/*for(i=1;i<=total-1;i++)
	{
		for(j=1;j<=total;j++)
		{
			printf("%f ",arr[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------\n");*/
	for(r=1;r<=total-1;r++)
	{
		min=10000;
		for(i=1;i<=total;i++)
		{
			for(j=i+1;j<=total;j++)
			{
				if(arr[i][j]<min && arr[i][j]!=1000) 
				{
					min=arr[i][j];
					x=i;
					y=j;
				}
			}
		}
					char temp[100000];
					for(int fo=0;fo<100000;fo++)
					{
						temp[fo]='\0';
					}
					strcpy(temp,"(");
					strcat(temp,name[x]);
					strcpy(name[x],temp);
					strcat(name[x],",");
					strcat(name[x],name[y]);
					strcat(name[x],")");
					name[y][0]='\0';	
		
//		printf("x:%d,y:%d\n",x,y);
		for(i=1;i<=total;i++)
		{
			arr[x][i]=(arr[x][i]+arr[i][y])/2;	
		}
		for(i=1;i<=total;i++)
		{
			arr[i][x]=arr[x][i];
		}
		for(i=1;i<=total;i++)
		{
			arr[y][i]=1000;
		}
		for(i=1;i<=total;i++)
		{
			arr[i][y]=1000;
		}
	}
	for(i=1;i<=total;i++)
	{
		if(name[i][0]!='\0')
			printf("%s\n",name[i]);
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
char seq[25][100000];
int len[50];
char str[100];
int total;
int arr[100][100];
int DISTANCE(int x,int y)
{
	if(len[x]==len[y])
	{
		int i,a,val1,val2,dis=0;
		for(i=0;i<len[x];i++)
		{
			for(a=1;a<=total;a++)
				if(str[a]==seq[x][i]) val1=a;
			for(a=1;a<=total;a++)
				if(str[a]==seq[y][i]) val2=a;
			dis+=arr[val1][val2];
		}
		return dis;
	}
	else
	{
		int dis=0;
		int val1,val2;
		if(len[x]<len[y])
		{
			int max=-99999999,m,n,a;
			for(m=0;m<(len[y]-len[x]+1);m++)
			{
				dis=0;
				for(n=m;n<m+len[x];n++)
				{
					for(a=1;a<=total;a++)
						if(str[a]==seq[x][n-m]) val1=a;
					for(a=1;a<=total;a++)
						if(str[a]==seq[y][n]) val2=a;
					dis+=arr[val1][val2];
				}
				if (dis>max) max=dis;
			}
			return max;
		}
		else
		{
			int max=-99999999,m,n,a;
			for(m=0;m<len[x]-len[y]+1;m++)
			{
				dis=0;
				for(n=m;n<m+len[y];n++)
				{
					for(a=1;a<=total;a++)
						if(str[a]==seq[x][n]) val1=a;
					for(a=1;a<=total;a++)
						if(str[a]==seq[y][n-m]) val2=a;
					dis+=arr[val1][val2];
				}
				if(dis>max) max=dis;
			}
			return max;
		}
	}
}
int main()
{

	FILE *input;
	input= fopen("Protein.txt","r");
	char c;
	char no[25][25];
	char name[25][100];
	int i=0,j=0;
	int total_seq=0;
	int distance[100][100];
	while((c=getc(input))!=EOF)
	{
		if(c=='>')
		{
			i++;
			fscanf(input,"%[^\[]",no[i]);
			getc(input);
			fscanf(input,"%[^]]",name[i]);
			fscanf(input,"%[^\n]",no[i]);
			j=0;

		}
		else if (c>='A' && c<='Z')
		{
			seq[i][j]=c;
			j++;
		}
		else continue;
	}
	total_seq=i;
	for(i=1;i<=total_seq;i++) len[i]=strlen(seq[i]);
	/*for(i=1;i<=total_seq;i++)
	  printf("%s\n",name[i]);
	  for(i=1;i<=total_seq;i++)
	  printf("%s\n",seq[i]);*/
	FILE *in;
	in=fopen("BLOSUM62.txt","r");
	char p;
	char string[100];
	fscanf(in,"%[^\n]",string);
	getc(in);
	j=1;
	for(i=0;i<strlen(string);i++)
	{
		if(string[i]>='A' && string[i]<='Z') 
		{
			str[j]=string[i];
			j++;
		}

	}
	total=j-1;
	int op=0;
	i=1,j=1;
	for(;(p=getc(in))!= EOF;)
	{
		if(p=='\n'||p=='\r')
		{
			i++;
			j=0;
			op=0;

		}
		else if(p==' ')
		{
			op=1;
			fscanf(in,"%d",&arr[i][j]);
			if(j==total+1) 
			{
				for(;(p=getc(in))!='\r';)
				{
					if(i==total+1 && j==total+1)
					{
						break;
					}
				}

				p=getc(in);
				j=0;
				i=i+1;
				op=0;
				if(i==total+1 && j==total+1)
				{
					break;
				}
			}
			j++;
		}
		else if(op==0) continue;
		else if(i==total+1 && j==total+1) break;
	}
	int a,b;
	for(a=1;a<=total_seq;a++)
	{
		for(b=a+1;b<=total_seq;b++)
		{
			distance[a][b]=DISTANCE(a,b);
		}
	}
	for(a=1;a<=total_seq;a++)
		distance[a][a]=-1000;
	for(b=1;b<=total_seq;b++)
	{
		for(a=b+1;a<=total_seq;a++)
			distance[a][b]=distance[b][a];
	}
	FILE *fp=fopen("Pdistance.txt","w");
	fprintf(fp,"\t");
	for(a=1;a<total_seq;a++)
		fprintf(fp,"%s,",name[a]);
	fprintf(fp,"%s\n",name[total_seq]);
	for(i=1;i<=total_seq;i++)
	{
		fprintf(fp,"%s,",name[i]);
		for(j=1;j<total_seq;j++)
		{
			fprintf(fp,"%d,",distance[i][j]);
		}
		fprintf(fp,"%d",distance[i][j]);
		fprintf(fp,"\n");
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len[25];
char seq[25][5000];
float DISTANCE(int x,int y)
{
	if(len[x]==len[y])
	{
		int count=0,i;
		for(i=0;i<len[x];i++)
			if(seq[x][i]==seq[y][i]) count++;

		return ((float) (len[x]-count)/len[x] );
	}
	else
	{
		int MIN,count=0,i;
		if(len[x]<len[y]) 
		{
			int max=0,m,n;
			MIN=len[x];
			for(m=0;m<(len[y]-len[x]+1);m++)
			{
				count=0;
				for(n=m;n<m+len[x];n++)
				{
					if (seq[y][n]==seq[x][n-m]) count++;
				}
				if (count>max) max=count;
			}
			return ((float) (len[x]-max)/len[x]);
		}
		else 
		{
			int max=0,m,n;
			MIN=len[y];
			for(m=0;m<len[x]-len[y]+1;m++)
			{
				count=0;
				for(n=m;n<m+len[y];n++)
				{
					if (seq[x][n]==seq[y][n-m]) count++;
				}
				if(count>max) max=count;
			}
			return ((float) (len[y]-max)/len[y]);
		}
	}
}
int main()
{
	FILE *input;
	input= fopen("Nucleotide.txt","r");
	char c;
	char no[25][25];
	char name[25][100];
	char genus[25][25];
	char species[25][25];
	float distance[25][25];
	int i=0,j=0;
	int total_seq;
	while((c=getc(input))!=EOF)
	{
		if(c=='>') 
		{
			i++;
			fscanf(input,"%s",no[i]);
			fscanf(input,"%s",genus[i]);
			fscanf(input,"%s",species[i]);
			fscanf(input,"%[^\n]",name[i]);
			j=0;
		}
		else if (c=='A'||c=='T'||c=='G'|c=='C') 
		{
			seq[i][j]=c;
			j++;
		}
		else continue;
	}
	total_seq=i;
	int a,b;
	for(a=1;a<=i;a++)
		len[a]=strlen(seq[a]);


	for(a=1;a<=total_seq;a++)
	{
		for(b=a+1;b<=total_seq;b++)
		{
			distance[a][b]=DISTANCE(a,b);
		}
	}
	for(a=1;a<=total_seq;a++)
		distance[a][a]=0;
	for(b=1;b<=total_seq;b++)
	{
		for(a=b+1;a<=total_seq;a++)
			distance[a][b]=distance[b][a];
	}
	FILE *fp=fopen("Ndistance.txt","w");
	fprintf(fp,"\t");
	for(a=1;a<total_seq;a++)
	fprintf(fp,"%s %s,",genus[a],species[a]);
	fprintf(fp,"%s %s",genus[total_seq],species[total_seq]);
	fprintf(fp,"\n");
	for(a=1;a<=total_seq;a++)
	{
		fprintf(fp,"%s %s,",genus[a],species[a]);
		for(b=1;b<total_seq;b++)
		{
			fprintf(fp,"%f,",distance[a][b]);
		}
		fprintf(fp,"%f",distance[a][b]);
		fprintf(fp,"\n");
	}
	return 0;
}

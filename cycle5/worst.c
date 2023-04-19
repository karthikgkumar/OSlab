#include<stdio.h>
int main()
{
	int m,n,i,k,j;
	printf("Enter no. of blocks");
	scanf("%d",&m);
	printf("Enter no. of processes");
	scanf("%d",&n);
	int bsize[m],psize[n],allocation[n];
	printf("Enter block size\n");
	for(i=0;i<m;i++)
		scanf("%d",&bsize[i]);
	printf("Enter process size\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&psize[i]);
		allocation[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		k=-1;
		for(j=0;i<m;j++)
		{
			if(bsize[j]>=psize[i])
			{
				if(k==-1)
					k=j;
				else if(bsize[k]<bsize[j])
					k=j;
			}
		}
		if(k!=1)
		{
			allocation[i]=k;
			bsize[k]-=psize[i];
		}
		printf("\nProcess No.\tProcess Size\tBlock no.\n");
		for (int i = 0; i < n; i++)
		{
		    printf("%d \t\t\t %d \t\t\t", i+1, psize[i]);
		    if (allocation[i] != -1)
		        printf("%d\n",allocation[i] + 1);
		    else
		        printf("Not Allocated\n");
		}

	}
	return 0;
}
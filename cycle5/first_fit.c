#include <stdio.h>

void implimentFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    // This will store the block id of the allocated block to a process
    int allocate[processes];
    
    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    for(int i = 0; i < processes; i++)
    {
		allocate[i] = -1;
    }
	
    // take each process one by one and find
    // first block that can accomodate it
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++) { 
            if (blockSize[j] >= processSize[i])
            {
                // allocate block j to p[i] process
                allocate[i] = j;
 
                // Reduce size of block j as it has accomodated p[i]
                blockSize[j] -= processSize[i];
 
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void main()
{
    printf("enter number of processes");
    int n;int a;
    scanf("%d",&n);
    printf("enter number of blocks");
    scanf("%d",&a);
    int blockSize[a];
    int processSize[n];
    printf("enter blocksize");
    for(int i=0;i<a;i++){
        scanf("%d ",&blockSize[i]);
        
    }
    printf("enter processsize");
    for(int i=0;i<n;i++){

        scanf("%d ",&processSize[i]);
        
    }
    
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int k = sizeof(processSize)/sizeof(processSize[0]);
    
    implimentFirstFit(blockSize, m, processSize, k);
}

// // output
// Process No.     Process Size    Block no.
// 1                        212                    2
// 2                        417                    5
// 3                        112                    2
// 4                        426                    Not Allocated
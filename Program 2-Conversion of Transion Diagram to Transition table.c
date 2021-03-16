#include<bits/stdc++.h>
struct setStates
{
	int state;
	int final; // 0 - NO    1 - YES
	int start; // 0 - NO    1 - YES
};
typedef struct setStates sstate; 

int main()
{
	int s,v,i,j;
	int **sv,*var; 
	sstate *states;

	printf("\nInput the number of finite set of states : ");
	scanf("%d",&s);
	printf("\nInput the number of finite set of input variables : ");
	scanf("%d",&v);

	// creating transition table	
	sv = (int **)malloc(v*sizeof(int));
	//printf("\n1 sucess\n");
	for(i=0;i<s;i++)
	{
		sv[i]=(int *)malloc(sizeof(int));
	}
	/*printf("\n2 sucess\n");
	printf("\nThe Array : \n");
	for(i=0;i<s;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("%d\t",sv[i][j]);
		}
		printf("\n");
	}*/

	// storing state information
	states = (sstate *)malloc(s*sizeof(sstate));
	printf("\nInput the states and its info (state start final): \n");
	for(i=0;i<s;i++)
	{
		scanf("%d%d%d",&states[i].state,&states[i].start,&states[i].final);
	}	 

	// storing input veribale
	var = (int *)malloc(v*sizeof(int));
	printf("\nInput the veriables : \n");
	for(i=0;i<v;i++)
	{
		scanf("%d",&var[i]);
	}

	// storing inputs of transition function
	for(i=0;i<s;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("\nThe sates %c with input veribale %c move to state : ",states[i].state,var[j]);
			scanf("%d",&sv[i][j]);
		}
	}

	// display transition table on screen
	printf("\nThe Transition Table : \n");
	printf("\t");
	for(i=0;i<v;i++)
	{
		printf("%c\t",var[i]);
	}	
	printf("\n-----------------------------------------------");
	for(i=0;i<s;i++)
	{
		printf("\n%c  %c  %c\t",states[i].state,(states[i].start==0)?' ':'$',(states[i].final==0)?' ':'*');
		for(j=0;j<v;j++)
		{
			printf("%c\t",sv[i][j]);
		}
		printf("\n");
	}		 	
}
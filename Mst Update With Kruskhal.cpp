#include<stdio.h>
#include<stdlib.h>




int i,j,k,a,b,u,v,n,ne=1;
int U,V,W;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
int main()
{


	printf("How Many Vertex\n");    // vertex er sonkha koto seita ber krte hb e
	scanf("%d",&n);
	printf("Enter The Adjacency Matrix :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("The Edges Of Minimum Spanning Tree\n");
	while(ne < n)   // while loop diye ag e er vitor edge gulo sort kora hochhe, er por sob theke kom weight er edge nichhi
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);   // 2 ta vertex er parent same kina seita check kora hocche
		v=find(v);
		if(uni(u,v))   // jei edge ta choto seita niye union kora hochhe
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	} // ei loop shese MST print hb e
	printf("Enter Which 2 Vertex You Want To Enter Your Edge (U,V)\n");  // pura graph e new edge add kora hb e
	scanf("%d%d",&U,&V);  // kon 2  ta vertex jar vitor edge add kora hb e sei 2 ta scan kore nichhi
	printf("Enter The Edge Weight Between The Vertices\n");
	scanf("%d",&W);   // 2 ta vertex er edge weight koto seitaw scan kora hocche
	check_for_cycle();  // new edge nil e cycle hb e kin a seita check korar jonooo ekta function call hb e , er kaj hoilo mainly DFS er moto



	return 0;

}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
int check_for_cycle()
{
    int j;
    int visited[i]=1;  // cycle check korte si , ei array te rakhbo parent gula ,jeta diye check korbo maily cycle ache kina

    printf(" %d->",i+1);
    for(j=0;j<n;j++)
    {
        if(cost[i][j]==1&&visited[j]==0)
            check_for_cycle(j);
    }

}


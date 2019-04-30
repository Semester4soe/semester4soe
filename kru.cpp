
#include <iostream>
#include<string.h>
#define MAX 10
using namespace std;

class kruskal
{
	public:
	int i, j, k, a, b, u, v, n, ne;
	int min, mincost, cost[MAX][MAX], parent[MAX];
	int find(int);
	int uni(int, int);
	void mainkruskal();
	void create();
	kruskal() {
		ne=1;
		mincost=0;


		for (int i = 1; i <= MAX; i++)
			for(int j = 1; j <= MAX; j++)
			cost[i][j]=999;


		for (int i = 1; i <= MAX; i++)
			parent[i]=0;
	}
};




void kruskal :: create()
{
	int ch, wt;
	cout<<"No. of Vertices in a graph ::  ";
	cin>>n;

	for (int i = 1; i< n; i++)
	 {
		for(int j = i+1; j <= n; j++)
		{
			cout<<"Does edge is present between "<< i <<" and " <<j<<"?(1/0)- ";
			cin >> ch;
			if(ch==1) {
				cout << " Enter the weight? ";
				cin >> wt;
				cost[i][j] = cost[j][i] = wt;
			}

		}
	}
}


void kruskal::mainkruskal(){
	while(ne<n) {
		for(i=1,min=999;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min)	{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}

		u=find(u);
		v=find(v);
		if(uni(u,v)) {
			cout<<"edge "<<ne++<<" ("<<a<<","<<b<<") "<<min<<"\n";
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	cout<<"\ntMinimum cost = "<<mincost <<"\n";
}







int kruskal::find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}

int kruskal::uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}


int main()
{
	kruskal obj;
	obj.create();
	obj.mainkruskal();
	return 0;
}



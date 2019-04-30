
#include <iostream>
#include<string.h>
#define MAX 10

using namespace std;


class djs
{
	public:
	int i, j, k, a, b, u, v, n, ne;
	int min, mincost, cost[MAX][MAX], process[MAX];
	void shortestpath(int ,int);
	void displayGraph();
	void create();
	djs() {

		for (int i = 1; i <= MAX; i++)
			for(int j = 1; j <= MAX; j++)
			cost[i][j]=999;
	}
};

void djs :: create()
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

void djs::displayGraph(){
	int i,j;
	cout << "The entered Graph is : \n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout << "\t" << cost[i][j];
		}
		cout << "\n";
	}

}

void djs:: shortestpath(int s,int t)
{
	int newdist,dist[MAX],processed[MAX],preced[MAX],curr,i,k,dc,smalldist;
	int p,j=0;
	int path[MAX];

	for(i=1;i<=n;i++)
	{
		processed[i]=preced[i]=0;
		dist[i]=999;
	}

	processed[s]=1;
	dist[s]=0;
	curr=s;


	while(curr!=t) {
		smalldist=999;
		dc=dist[curr];

		for(i=1;i<=n;i++)
		{
			if(processed[i]==0){
				newdist=dc+cost[curr][i];

				if(newdist < dist[i]) {
					dist[i]=newdist;
					preced[i]=curr;
				}
				if(dist[i] < smalldist){
					smalldist=dist[i];
					k=i;
				}
			}
		}

		curr=k;
		processed[curr]=1;
	}


	p = t;
	path[j++] = p;
	while (p != s)
	{
		p = preced[p];
		path[j++] = p;
	}
	cout <<"\n Shortest Path: ";
	for(i=j-1;i>=0;i--) {
		cout << path[i];
	}

	cout << " Shortest distance : " << dist[t] << "\n";

}


int main(){
	int s,t;
	djs obj;
	obj.create();
	obj.displayGraph();
	cout << "\n Enter start and target vertices: ";
	cin >> s;
	cin >> t;
	obj.shortestpath(s, t);
	return 0;
}



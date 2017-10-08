/*#include <graphics.h>

int main( )
{
    initwindow(400, 300, "First Sample");
    circle(100, 50, 40);
    while (!kbhit( ))
    {
        delay(200);
    }
    return 0;
}*/

#include <conio.h>
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
#define fori(a,b) for(lli (i)=(lli)(a);(i)<=(lli)(b);(i)++)
#define forj(a,b) for(lli (j)=(lli)(a);(j)<=(lli)(b);(j)++)
#define fork(a,b) for(lli (k)=(lli)(a);(k)<=(lli)(b);(k)++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inf (lli)1000000007
#define pi 3.14159265359
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sz(a) (lli)(a).size()
#define iter(a) typeof((a).begin())

#define xwidth	1520
#define yheight 800
#define N 200


typedef long long int lli;
typedef vector< lli > vlli;
typedef pair<lli,lli> plli;
typedef set<lli> slli;
typedef map<lli,lli> mlli;

lli Mat[N+5][N+5];


vlli fin(N+5,0);

vlli Edges[N+5];
vector< plli > Nodes;


lli w1=1,w2=0,w3=0,w4=0;


lli distan(plli x,plli y)
{
    return w1*sqrt(pow(x.X-y.X,2)+pow(x.Y-y.Y,2));
}

lli distan2(plli x,plli y)
{
    return w1*sqrt(pow(x.X-y.X,2)+pow(x.Y-y.Y,2))+ w2*( 10+rand()%100 ) ;
}


void dijkstra(lli source,lli destination)
{
	
	
	vlli dist(N+1);
	fori(1,N)dist[i]=INT_MAX;
	vlli visited(N+1,0);
	vlli parent(N+1);
	
	dist[source]=0;
	
	parent[source]=source;
	
	fori(1,N)
	{
		lli curr_dist=INT_MAX;
		lli curr=-1;
		forj(1,N)
		{
			if (visited[j]==0 && (dist[j]<curr_dist) )
			{
				curr_dist=dist[j];
				curr=j;
			}	
		}
		
		if (curr==-1)break;
		
		//cout<<curr<<" ";
		visited[curr]=1;
		
		forj(0,sz(Edges[curr])-1)
		{
			//cout<<curr<<" "<<Edges[curr][j]<<endl;
			
			if (dist[ Edges[curr][j] ] > dist[ curr ]  +  distan(Nodes[curr] , Nodes[ Edges[curr][j] ] ) )
			{
				parent[  Edges[curr][j]  ] = curr;
				dist[ Edges[curr][j] ] = dist[ curr ]  +  distan(Nodes[curr] , Nodes[ Edges[curr][j] ] );
			}
		}
		
	}
	lli dest=destination;
	
	fori(1,N)
	{
		//cout<<parent[i]<<" ";
	}
	
	cout<<endl;
	
	while (parent[dest] != dest )
	{
		//cout<<dest<<" ";
		
		fin[dest]=1;
		
		line( Nodes[dest].X, Nodes[dest].Y, Nodes[ parent[dest] ].X, Nodes[ parent[dest] ].Y );
		
		dest=parent[dest];
		
	}
	
	return;
	
	
	
}


void dijkstra2(lli source,lli destination)
{
	
	
	vlli dist(N+1);
	fori(1,N)dist[i]=INT_MAX;
	vlli visited(N+1,0);
	vlli parent(N+1);
	
	dist[source]=0;
	
	parent[source]=source;
	
	fori(1,N)
	{
		lli curr_dist=INT_MAX;
		lli curr=-1;
		forj(1,N)
		{
			if (visited[j]==0 && (dist[j]<curr_dist) )
			{
				curr_dist=dist[j];
				curr=j;
			}	
		}
		
		if (curr==-1)break;
		
		//cout<<curr<<" ";
		visited[curr]=1;
		
		forj(0,sz(Edges[curr])-1)
		{
			//cout<<curr<<" "<<Edges[curr][j]<<endl;
			
			if (dist[ Edges[curr][j] ] > dist[ curr ]  + Mat[  curr ][ Edges[curr][j] ] )
			{
				parent[  Edges[curr][j]  ] = curr;
				dist[ Edges[curr][j] ] = dist[ curr ]  + Mat[  curr ][ Edges[curr][j] ] ;
			}
		}
		
	}
	lli dest=destination;
	
	fori(1,N)
	{
		//cout<<parent[i]<<" ";
	}
	
	cout<<endl;
	
	while (parent[dest] != dest )
	{
		//cout<<dest<<" ";
		
		line( Nodes[dest].X, Nodes[dest].Y, Nodes[ parent[dest] ].X, Nodes[ parent[dest] ].Y );
		
		dest=parent[dest];
		
	}
	
	return;
	
	
	
}




int main()
{
	//fastio
	lli t=1;
	//cin>>t;
	//make_sieve();
	while (t--)
    {
        srand(41);
		initwindow( xwidth , yheight , "First Sample");
		
		setbkcolor(GREEN);
		
		
		
		delay(1000);
		
		
		Nodes.pb({0,0});
		
		setlinestyle(0,0xFFFF,1);
		
        fori(1,N)
        {
            lli x=1+rand()%xwidth;
            lli y=1+rand()%yheight;
            Nodes.pb({x,y});
        }

        fori(1,N)
        {
            vector< plli > temp;
            temp.clear();
            forj(1,N)
            {
                if (j!=i && distan(Nodes[i],Nodes[j])<=1000 )
                {
                    temp.pb({ distan(Nodes[i],Nodes[j]) ,j});
                    //Edges[i].pb(j);
                }

            }
            sort(temp.begin(),temp.end());
            forj(0,min(3LL,sz(temp)-1))
            {
                Edges[i].pb(temp[j].Y);
            }
        }

        fori(1,N)
        {
            //cout<<Nodes[i].X<<" "<<Nodes[i].Y<<endl;
            forj(0,sz(Edges[i])-1)
            {
            	line(Nodes[i].X,Nodes[i].Y,Nodes[  Edges[i][j] ].X,Nodes[ Edges[i][j] ].Y);
                //cout<<Edges[i][j]<<" ";
            }
            //cout<<endl;
        }
		
		delay(3000);
		
		lli source=1;
		lli source2=1;
		
		lli destination=1;
		lli destination2=1;
		
		fori(1,N)
		{
			if (Nodes[i].X<Nodes[source].X)
				source=i;
			if (Nodes[i].Y>Nodes[source2].Y)
				source2=i;
		}
		
		
		fori(1,N)
		{
			if (Nodes[i].X>Nodes[destination].X)
				destination=i;
			if (Nodes[i].Y<Nodes[destination2].Y)
				destination2=i;
		}
		
		setlinestyle(0,0xFFFF,13);
		
		setcolor(14);
		dijkstra(source,destination);
		setcolor(9);
		//dijkstra(source2,destination2);
		
		
		w2=10;
		
		lli mx=100;
		
		/*fori(1,N)
        {
            //cout<<Nodes[i].X<<" "<<Nodes[i].Y<<endl;
            forj(0,sz(Edges[i])-1)
            {
            	
            	if (distan(Nodes[i], Nodes[ Edges[i][j] ]) > mx )
            	{
            		mx=distan(Nodes[i], Nodes[ Edges[i][j] ]);
				}
            	
            	//line(Nodes[i].X,Nodes[i].Y,Nodes[  Edges[i][j] ].X,Nodes[ Edges[i][j] ].Y);
                //cout<<Edges[i][j]<<" ";
            }
            //cout<<endl;
        }*/
        
        
        delay(5000);
        setlinestyle(0,0xFFFF,3);
        
        
        fori(1,N)
        {
        	
        	forj(1,N)
        	{
        		
        		Mat[i][j]=0;
			}
        	
		}
		
		fori(1,N)
		{
			
			if (fin[i]==1)
			{
				
				forj(0,sz(Edges[i])-1)
				{
					
					Mat[i][ Edges[i][j]  ]=distan2(Nodes[i],Nodes[  Edges[ i ][j] ]);
					
					mx=max(mx,Mat[i][  Edges[i][j]  ]);
					
				}
				
			}
			
			else
			{
				forj(0,sz(Edges[i])-1)
				{
					
					Mat[i][   Edges[i][j]  ]=distan(Nodes[i],  Nodes[ Edges[i][j] ] );
					mx=max(mx,Mat[i][ Edges[i][j] ]);
				}
				
			}
			
			
		}
		
		cout<<mx<<endl;
		
		fori(1,N)
		{
			
			forj(0,sz(Edges[i])-1)
			{
				
				double rat= (double)Mat[ i ][ Edges[i][j] ]/(double)mx;
				
				cout<<Mat[i][ Edges[i][j] ]<<endl;
				
				if (rat>0.3)
				{
					setcolor(4);
					setlinestyle(0,0xFFFF,7);
					line(Nodes[i].X,Nodes[i].Y,Nodes[  Edges[i][j] ].X,Nodes[ Edges[i][j] ].Y);
				}
			
				//else setcolor(15);
				
				
				
				
			}
			
			
		}
		
		
        
			
		delay(5000);
		setlinestyle(0,0xFFFF,13);
		
		setcolor(2);
		dijkstra2(source,destination);
		setcolor(1);
		//dijkstra2(source2,destination2);
		
		getch();

	}
	return 0;
}




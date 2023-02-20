#include <bits/stdc++.h>
#define Mod(a,b) ((((a)%(b))+(b))%(b))
#define ll long long
#define vec vector<ll>
#define pb push_back
#define mk make_pair
#define MAX2 9223372036854775806 
const int MOD = 1000000007;
const int MAX = 10000005;

using namespace std;

/*
Shortest Path 1

Thought Process

. Shortest Path to every other node
. Weights are +ve
. Directed Graph
. Dijktra's

Implementation

. Using a min heap/set to store pairs of <long long, long long>, first one denoting dist, second one source
. Pick the top, relax its adjacent
. Update dist vector and add to the set, else run the next iter
. Remove the previous version of the node
. Update visited vector
. If visited vector size reaches number of nodes, done, read dist vector

*/

int main()


{

    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > adj[n+1];
    int a,b,c;
    for(int i =0 ; i<m;i++){
        cin>>a>>b>>c;
        adj[a].pb(mk(b,c));
    }


    set<pair<ll,int> > s;
    ll dist[n+1] ;
    for(int i =0;i<n+1;i++)
        dist[i] = MAX2;
    set<int> size;

    s.insert(mk(0,1));
    dist[1] = 0;

    while(size.size()!=n){
        auto temp = s.begin();
        int u = (*temp).second;
        size.insert(u); 
        ll d = (*temp).first;
        s.erase(temp);
        for (int j = 0;j<adj[u].size();j++){
            if(dist[adj[u][j].first]>dist[u]+adj[u][j].second){

                // EDIT : Remove previous version of the node
                if(dist[adj[u][j].first]!=MAX2){
                    s.erase(s.find(mk(dist[adj[u][j].first],adj[u][j].first)));
                }    

                dist[adj[u][j].first]=dist[u]+adj[u][j].second;
                s.insert(mk(dist[u]+adj[u][j].second,adj[u][j].first));
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<dist[i]<<" ";
    }



}


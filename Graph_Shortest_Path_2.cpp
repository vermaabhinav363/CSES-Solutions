#include <bits/stdc++.h>
#define Mod(a,b) ((((a)%(b))+(b))%(b))
#define ll long long
#define vec vector<ll>
#define pb push_back
#define mk make_pair
#define MAX2 9223372036854775807
const int MOD = 1000000007;
const int MAX = 10000005;

using namespace std;

/*
Shortest Path 1

Thought Process

. Preprocess first and then answer queries
. All pair shortest path problem
. Undirected
. Will use Floyd Warshall
. Time - O(V*V*V) -> 125,000,000
. Space - O(V*V) -> 250000

Implementation

. 2 2D Array
. For the ith iteration, replicate as it is, values for node i
. For rest check if A[m,n] > A[m,i] + A[i,n]
. If it is replace
. Do it for n times, n-> no of vertices
. Take care of infinity


*/

int main()


{

    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int,int> > adj[n+1];
    ll a,b,c;

    // Preprocessing

    long long adj_p[n+1][n+1];
    long long adj_c[n+1][n+1];
    for(int i =0;i<=n;i++){
        for(int j =0;j<=n;j++)
            adj_p[i][j]=MAX2;
    }
    for(int i  =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            adj_p[i][j] = MAX2;
            if(i==j)
                adj_p[i][j]=0;
        }
    }
    for(int i =0 ; i<m;i++){
        cin>>a>>b>>c;
        adj[a].pb(mk(b,c));
        adj[b].pb(mk(a,c));
        adj_p[a][b] = min(c,adj_p[a][b]);
        adj_p[b][a] = min(c,adj_p[a][b]);
    }

    for(int k = 1;k<=n;k++){
        if(k%2==1){

            for(int i  =1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(i==k){
                        adj_c[i][j] = adj_p[i][j];
                    }
                    else if(j==k){
                        adj_c[i][j] = adj_p[i][j];
                    }
                    else{
                        if(adj_p[i][k] != MAX2 && adj_p[k][j]!=MAX2)
                        adj_c[i][j] = min(adj_p[i][j] , (adj_p[i][k] + adj_p[k][j]));
                        else
                        adj_c[i][j] = adj_p[i][j];
                    }
                }
            }

        }
        else{

            for(int i  =1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(i==k){
                        adj_p[i][j] = adj_c[i][j];
                    }
                    else if(j==k){
                        adj_p[i][j] = adj_c[i][j];
                    }
                    else{
                        if(adj_p[i][k] != MAX2 && adj_p[k][j]!=MAX2)
                        adj_p[i][j] = min(adj_c[i][j] , (adj_c[i][k] + adj_c[k][j]));
                        else
                        adj_p[i][j] = adj_c[i][j];
                    }
                }
            }

        }
    }
    while(q--){
        if(n%2==1){
            cin>>a>>b;
            if(adj_c[a][b]==MAX2){
                cout<<-1<<" ";
            }
            else
            cout<<adj_c[a][b]<<" ";
        }
        else{
            cin>>a>>b;
            if(adj_p[a][b]==MAX2){
                cout<<-1<<" ";
            }
            else
            cout<<adj_p[a][b]<<" ";
        }
    }





}


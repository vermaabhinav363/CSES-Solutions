#include <bits/stdc++.h>
#define Mod(a,b) ((((a)%(b))+(b))%(b))
#define ll long long
#define vec vector<ll>
#define pb push_back
#define mk make_pair
#define MAX2 9223372036854775806
#define MAX3 -9223372036854775806
const int MOD = 1000000007;
const int MAX = 10000005;

using namespace std;

/*
High Score

Thought Process

. Finding single source longest path
. Multiply by -1, then get single source shortest path
. Looks like -ve edges, cannot use Dijkstra Algo
. Floyd Warshall ??
. V Cube, TLE
. Bellman Ford handles -ve edges
. Idea of -ve cycle, cycle whose values keep on decreasing
. Idea of propagation and relaxation
. Heart of the problem is that in a single source shortest path with no -ve cycles, max length of SSSP is v-1
. Relax all edges v-1 times
. If no negative cycle, our answer is final
. If negative cycle, there would be a change after v-1 times, convert that values to -INF
. Propagate, loop again v-1 times, to catch all -INF
. Use BFS when no weights, Dijkstra for +ve weight, Bellman Ford for -ve Edges and -ve cycles


Implementation

TO DO:


*/

int main()


{

    ll n,m;
    cin>>n>>m;
    vector<tuple<ll,ll,ll> > vecx;
    ll a,b,c;
    for(ll i =0;i<m;i++){
        cin>>a>>b>>c;
        vecx.pb(make_tuple(a,b,-1*c));
    }

    ll dist[n+1];
    for(ll i =0 ;i <=n;i++)
        dist[i]  = MAX2;

    dist[1] = 0;

    for(ll i =1 ;i<n;i++){

        for(ll j =0;j<m;j++){
            a = get<0>(vecx[j]);
            b = get<1>(vecx[j]);
            c = get<2>(vecx[j]);

            if(dist[a]!=MAX2)
            dist[b] = min(dist[a] + c,dist[b]);

        }

    }

    ll dist2[n+1];
    for(ll i =0 ;i<=n;i++)
        dist2[i]  = dist[i];


    for(ll j =0;j<m;j++){
            a = get<0>(vecx[j]);
            b = get<1>(vecx[j]);
            c = get<2>(vecx[j]);

            if(dist2[a]!=MAX2)
            dist2[b] = min(dist2[a] + c,dist2[b]);

    }
    bool flag = false;
    for(ll i =0 ;i <=n;i++){
        if(dist2[i]!=dist[i]){
            flag = true;
            dist[i] = MAX3;
            break;
        }

    }

    if(flag){

        for(ll i =1 ;i<n;i++){

            for(ll j =0;j<m;j++){
                a = get<0>(vecx[j]);
                b = get<1>(vecx[j]);
                c = get<2>(vecx[j]);

                if(dist[a]!=MAX2 && dist[a]!=MAX3){
                    // EDIT, TO DO, THINK
                    if(dist[b]<dist[a]+c)
                    dist[b] = MAX3;
                }
                if(dist[a]==MAX3)
                    dist[b] = dist[a];

            }

        }

        if(dist[n]!=MAX3)

        cout<<-1*dist[n];

        else

        cout<<-1;
    }
    else{
          cout<<-1*dist[n];
    }




}


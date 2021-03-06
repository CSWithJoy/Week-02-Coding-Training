//dijkstra纯模板。。
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxx=500;
const int INF=999999999;
struct edge{int to,cost;};
typedef pair<int,int> P;
int n,m,qi,o;
vector<edge> g[maxx];
int d[maxx];
void dijkstra(int qi){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+m+1,INF);
    d[qi]=0;
    que.push(P(0,qi));
    while(!que.empty()){
	//	printf("%d",d[8]);
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<g[v].size();i++){
            edge e=g[v][i];
            if(d[e.to]>d[v]+e.cost){
	//			if(e.to==7)  printf("dv=%d cost=%d v=%d to=%d\n",d[v],e.cost,v,d[e.to]);
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
void pro(){
    scanf("%d%d",&m,&n);
    int a,b,c;
    edge w;
    for(int i=0;i<=m;i++)
        g[i].clear();
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a,&b,&c);
        w.to=b,w.cost=c;
        g[a].push_back(w);
        w.to=a,w.cost=c;
        g[b].push_back(w);
    }
    dijkstra(1);
    printf("Case %d: ",o);
    if(d[m]!=999999999)
        printf("%d\n",d[m]);
    else
        printf("Impossible\n");
}
int main(){
    int T;
    scanf("%d",&T);
    for(o=1;o<=T;o++)
        pro();
    return 0;
}

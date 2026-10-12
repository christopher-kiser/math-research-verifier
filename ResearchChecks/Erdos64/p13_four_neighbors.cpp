// Erdős #64 — P13 external-neighbor necessary-condition enumeration.
// Exact finite search. Does not establish the Erdős–Gyárfás conjecture.
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
constexpr int N=13;
bool hasCycle(const vector<int>& masks,int length){
  const int n=N+(int)masks.size();
  vector<uint32_t> adj(n,0);
  auto edge=[&](int u,int v){adj[u]|=1u<<v;adj[v]|=1u<<u;};
  for(int i=0;i<N-1;i++) edge(i,i+1);
  for(int j=0;j<(int)masks.size();j++)
    for(int i=0;i<N;i++) if(masks[j]&(1<<i)) edge(13+j,i);
  auto dfs=[&](auto&& self,int start,int cur,uint32_t seen,int vertices)->bool{
    if(vertices==length) return bool(adj[cur]&(1u<<start));
    auto avail=adj[cur]&~seen;
    while(avail){
      auto bit=avail&-avail;avail-=bit;
      int next=__builtin_ctz(bit);
      if(next<=start)continue;
      if(self(self,start,next,seen|bit,vertices+1))return true;
    }
    return false;
  };
  for(int start=0;start<n;start++){
    auto avail=adj[start];
    while(avail){
      auto bit=avail&-avail;avail-=bit;
      int next=__builtin_ctz(bit);
      if(next<=start)continue;
      if(dfs(dfs,start,next,(1u<<start)|bit,2))return true;
    }
  }
  return false;
}
int main(){
  vector<int> patterns;
  for(int a=0;a<(1<<N);a++){
    bool valid=true;
    for(int i=0;i<N;i++) if(a&(1<<i))
      for(int d:{2,6}) if(i+d<N && (a&(1<<(i+d)))) valid=false;
    if(valid) patterns.push_back(a);
  }
  int n=(int)patterns.size();
  vector<vector<unsigned char>> compatible(n,vector<unsigned char>(n,0));
  for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
    int a=patterns[i],b=patterns[j];
    if(__builtin_popcount((unsigned)(a&b))>=2)continue;
    if(hasCycle({a,b},4)||hasCycle({a,b},8))continue;
    compatible[i][j]=compatible[j][i]=1;
  }
  for(int i=0;i<n;i++)
    if(__builtin_popcount((unsigned)patterns[i])==1)compatible[i][i]=1;
  uint64_t triples=0,quadruples=0,degreeCovered=0;
  for(int i=0;i<n;i++)for(int j=i;j<n;j++)if(compatible[i][j])
    for(int k=j;k<n;k++)if(compatible[i][k]&&compatible[j][k]){
      triples++;
      int sum=__builtin_popcount((unsigned)patterns[i])+
        __builtin_popcount((unsigned)patterns[j])+
        __builtin_popcount((unsigned)patterns[k]);
      for(int l=k;l<n;l++){
        if(!compatible[i][l]||!compatible[j][l]||!compatible[k][l])continue;
        quadruples++;
        if(sum+__builtin_popcount((unsigned)patterns[l])<15)continue;
        array<int,N> deg{};
        for(int m:{patterns[i],patterns[j],patterns[k],patterns[l]})
          for(int p=0;p<N;p++)deg[p]+=(m>>p)&1;
        bool covered=deg[0]>=2 && deg[N-1]>=2;
        for(int p=1;p<N-1;p++)covered &= deg[p]>=1;
        if(covered)degreeCovered++;
      }
    }
  cout<<"patterns="<<n<<" triples="<<triples
      <<" pairCompatibleQuadruples="<<quadruples
      <<" degreeCovered="<<degreeCovered<<"\n";
  // Regression gate: do not report success for changed counts without review.
  if(n!=400 || triples!=506998 || quadruples!=8099222 || degreeCovered!=0)
    return 1;
}

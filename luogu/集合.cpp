#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n=0){ init(n); }
    void init(int n_){
        n = n_;
        p.resize(n);
        r.assign(n,0);
        for(int i=0;i<n;i++) p[i]=i;
    }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int x,int y){
        x = find(x); y = find(y);
        if(x==y) return;
        if(r[x]<r[y]) swap(x,y);
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a,b;
    int p;
    if(!(cin>>a>>b>>p)) return 0;
    int n = (int)(b - a + 1);
    if(n <= 0){ cout << 0 << "\n"; return 0; }

    // Special fast case
    if(p > b){
        cout << n << "\n";
        return 0;
    }

    // Sieve primes up to b
    int B = (int)b;
    vector<char> is_prime(B+1, true);
    is_prime.assign(B+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i*(long long)i<=B;i++){
        if(is_prime[i]){
            for(long long j = 1LL*i*i; j<=B; j+=i) is_prime[(int)j] = false;
        }
    }
    vector<int> primes;
    for(int i=p;i<=B;i++){
        if(is_prime[i]) primes.push_back(i);
    }

    DSU dsu(n);
    // For each prime >= p, union all multiples in [a,b]
    for(int q : primes){
        // first multiple of q >= a:
        long long start = (a + q - 1) / q * (long long)q;
        if(start > b) continue;
        int first_idx = (int)(start - a); // index in [0..n-1]
        for(long long val = start + q; val <= b; val += q){
            int idx = (int)(val - a);
            dsu.unite(first_idx, idx);
        }
    }

    // count distinct roots
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(dsu.find(i) == i) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}

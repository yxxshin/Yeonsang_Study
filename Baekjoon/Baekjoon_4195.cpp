#include <iostream>
#include <map>
#define MAX_N 100000
using namespace std;

int id = 1;
int parent[MAX_N+3];    // parent[i] : i'th node's parent
int size[MAX_N+3];      // size of tree[i]
map<string,int> m;      // information about people {name,id}

int find(int u) {
    // if root node, return
    if(u == parent[u])
        return u;

        // else : go up to find root node
    else {
        // path compression : every parent[node] would be root, so time is saved for second time
        return parent[u] = find(parent[u]);
    }
}

// Union : merge tree u to tree v
void merge(int u, int v){
    // find u and v 's root node
    u = find(u);
    v = find(v);

    // if roots are same, they are already in the same tree
    if(u == v)
        return;

    // if tree 'u' is bigger than 'v', swap
    if(size[u] > size[v]){
        int temp = u;
        u = v;
        v = temp;
    }

    // merge two trees ( u is added to v )
    parent[u] = v;
    size[v] += size[u];
    size[u] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        // initialization
        for(int i = 1; i <= MAX_N; i++){
            parent[i] = i;  // root node : parent is itself
            size[i] = 1;
        }

        int F;
        cin >> F;
        while(F--){
            string s1, s2;
            cin >> s1 >> s2;
            // if new name, insert to map
            if(m.count(s1) == 0)
                m.insert(make_pair(s1,id++));
            if(m.count(s2) == 0)
                m.insert(make_pair(s2,id++));

            // find root
            int s1_root = find(m[s1]);
            int s2_root = find(m[s2]);

            // merge and print answer
            merge(s1_root, s2_root);
            cout << max(size[s1_root],size[s2_root]) << '\n';
        }
    }
}
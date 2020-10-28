#include <cstdio>
#include <vector>
using namespace std;
vector<double> ans;

int main() {
    for(int i = 0; i < 3; i++){
        double a, b;
        scanf("%lf %lf", &a, &b);
        double val1 = b * 10;
        double val2 = (a * 10 >= 5000 ? a * 10 - 500: a * 10);
        double val = val1 / val2;
        ans.push_back(val);
    }

    if(ans[0]>ans[1] && ans[0]>ans[2]) printf("S\n");
    else if(ans[1]>ans[2] && ans[1]>ans[0]) printf("N\n");
    else printf("U\n");
}
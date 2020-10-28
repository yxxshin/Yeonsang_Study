#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int distance(Point& p, Point& q) {
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

bool compare_x(Point& p, Point& q){
    return (p.x < q.x);
}

bool compare_y(Point& p, Point& q){
    return (p.y < q.y);
}

int findMin(vector<Point>::iterator it, int n){
    // when n=2 or n=3
    if(n==2) return distance(it[0], it[1]);
    if(n==3) return min( {distance(it[0], it[1]), distance(it[1],it[2]), distance(it[2],it[0])});

    // else
    // set the middle line and divide-and-conquer
    // 3 cases: left side / right side / including the line
    int line = (it[n/2 - 1].x + it[n/2].x) / 2;     // middle line
    int minDistance = min(findMin(it, n/2), findMin(it + n/2, n - n/2));   // left side & right side

    // including the line
    vector<Point> middle;
    middle.reserve(n);

    // push_back points which distances from line is lower than minDistance
    // only consider these points
    for(int i = 0; i < n; i++){
        int temp = line -it[i].x;
        if( temp * temp < minDistance) middle.push_back(it[i]);
    }

    // sort by y-value
    sort(middle.begin(), middle.end(), compare_y);

    // keypoint: if the difference of y-value gets larger than minDistance, you don't need to consider the left points
    int size = middle.size();
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size && (middle[j].y - middle[i].y) * (middle[j].y - middle[i].y) < minDistance; j++) {
            minDistance = min(minDistance, distance(middle[i], middle[j]));
        }
    }

    return minDistance;

}


int main() {
    // input n
    int n;
    scanf("%d",&n);

    // make Point vector and get input
    vector<Point> vec(n);
    for(vector<Point>::iterator it = vec.begin(); it != vec.end(); it++) {
        scanf("%d %d", &it->x, &it->y);
    }

    // sort by x-value
    sort(vec.begin(), vec.end(), compare_x);

    // print
    printf("%d\n", findMin(vec.begin(), n));
}
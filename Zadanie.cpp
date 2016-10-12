#include <bits/stdc++.h>
#include <stack>
//#include <algorithm>
using namespace std;

struct Point
{
	int x, y;
};

vector<Point> hull;
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

void reverse (int i, int j)
{
    stack <Point> reverseVector;
    for (int k=i; k<=j; i++)
    {
        reverseVector.push(hull[k]);
    }
    for (int k=i; k<=j; i++)
    {
        hull[k]=reverseVector.top();
        reverseVector.pop();
    }
}

double length(int n)
{
    double d = 0;
    for (int i=0 ; i< n; i++)
    {
        d+=sqrt((hull[i].x-hull[i+1].x)*(hull[i].x-hull[i+1].x)+(hull[i].y-hull[i+1].y)*(hull[i].y-hull[i+1].y));
    }
        d+=sqrt((hull[n-1].x-hull[0].x)*(hull[n-1].x-hull[0].x)+(hull[n-1].y-hull[0].y)*(hull[n-1].y-hull[0].y));

        return d;
}

// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
	// There must be at least 3 points
	if (n < 3) return;

	// Initialize Result

	// Find the leftmost point
	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;

	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again. This loop runs O(h)
	// times where h is number of points in result or output.
	int p = l, q;
	do
	{
		// Add current point to result
		hull.push_back(points[p]);

		// Search for a point 'q' such that orientation(p, x,
		// q) is counterclockwise for all points 'x'. The idea
		// is to keep track of last visited most counterclock-
		// wise point in q. If any point 'i' is more counterclock-
		// wise than q, then update q.
		q = (p+1)%n;
		for (int i = 0; i < n; i++)
		{
		// If i is more counterclockwise than current q, then
		// update q
		if (orientation(points[p], points[i], points[q]) == 2)
			q = i;
		}

		// Now q is the most counterclockwise with respect to p
		// Set p as q for next iteration, so that q is added to
		// result 'hull'
		p = q;

	} while (p != l); // While we don't come to first point

	// Print Result
	cout << "Convex Hull:" << endl;
	for (int i = 0; i < hull.size(); i++)
		cout << "(" << hull[i].x << ", "
			<< hull[i].y << ")\n";

	int weight[n-1];
	bool flag = false;

	for (int i = 0; i < n; i++) {
	    for(int j = 0; j < hull.size(); j++)
	        if((points[i].x == hull[j].x) && (points[i].y == hull[j].y)) {
	            flag = false;
	            break;
	        }
	        else
	            flag = true;
	    if(flag){
    	    for(int k = 0; k < hull.size()-1; k++)
    	        weight[k]=(points[i].x-hull[k].x)*(points[i].x-hull[k].x)+
    	        +(points[i].y-hull[k].y)*(points[i].y-hull[k].y)+
    	        +(points[i].x-hull[k+1].x)*(points[i].x-hull[k+1].x)+
    	        +(points[i].y-hull[k+1].y)*(points[i].y-hull[k+1].y);
    	    int small=weight[0];
    	    int num = 0;

            for (int x=0; x < hull.size()-1; x++)
            {
                if(weight[x]<small) {
                    small=weight[x];
                    num = x;
                }
            }
            hull.insert (hull.begin()+num+1, points[i]);

	    }
	}

	cout << endl << "Hamiltonian path:" << endl;
	for (int i = 0; i < hull.size(); i++)
		cout << "(" << hull[i].x << ", "
			<< hull[i].y << ")\n";
}

// Driver program to test above functions
int main()
{
    int n,k;
    cin>>n;
	cout<<"Zmiana";
	cout<<"Jeszcze jedna";
	Point points[n];
	for (int i=0;i<n;i++)
	{
	 //   cin>>k;
	    cin>>points[i].x;
	    cin>>points[i].y;
	}


	convexHull(points, n);

	//reverse(1,3);

	//cout << endl << "Popsuty Hamiltonian path:" << endl;
	//for (int i = 0; i < hull.size(); i++)
	//	cout << "(" << hull[i].x << ", "
	//		<< hull[i].y << ")\n";

	cout<< length(n) << endl;
	return 0;
}

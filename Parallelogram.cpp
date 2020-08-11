#include<iostream>
#include<math.h>
using namespace std;
float x[10],y[10],xp,yp;
//a function that calculates the distance between 2 points
float calculate_length(float a1,float b1,float a2,float b2)
{
    return sqrt(pow(a2-a1,2)+pow(b2-b1,2));
}
//a function that calculates the area of a triangle when given its coordinates
float calculate_area(float a1,float b1,float a2,float b2,float a3,float b3)
{
    float l1,l2,l3;
    l1=calculate_length(a1,b1,a2,b2);
    l2=calculate_length(a1,b1,a3,b3);
    l3=calculate_length(a2,b2,a3,b3);
    float s=(l1+l2+l3)/2;
    return sqrt(s*(s-l1)*(s-l2)*(s-l3));

}
//the idea here is to divide the parallelogram into 2 triangles, then checking whether the point belongs to any of them.
//the way to do that is to create 3 smaller triangles from the larger ones, each of the 3 having the point we're checking as
// a vertex and then the another 2 points consecutively. we calculate the area of each of the 3 triangles, and if it's exactly
//equal to the area of the larger one, then the point belongs inside the triangle, and thus inside the parallelogram
bool check_if_inside(float a1, float b1)
{

    float area,area1,area2,area3;
    area1=calculate_area(x[0],y[0],x[2],y[2],xp,yp);
    area2=calculate_area(x[0],y[0],a1,b1,xp,yp);
    area3=calculate_area(a1,b1,x[2],y[2],xp,yp);
    area=calculate_area(x[0],y[0],x[2],y[2],a1,b1);
    return (abs((area1+area2+area3)-area)<=0.000001);
}
int main()
{
    cout<<"Please enter the coordinates of the points, clockwise or counterclockwise\n";
    for(int i=0;i<4;i++)
    {
        cin>>x[i]>>y[i];
    }
    cout<<"Please enter the coordinates of the point you would like to check\n";
    cin>>xp>>yp;
    //checking whether any of the 2 triangles contains the point
    if(check_if_inside(x[1],y[1])||check_if_inside(x[3],y[3]))
    {
        cout<<"The point is inside the parallelogram\n";
    }
    else
    {
        cout<<"The point is NOT inside the parallelogram\n";
    }
    return 0;
}

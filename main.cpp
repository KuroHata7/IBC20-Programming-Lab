#include<iostream>
#include<math.h>
using namespace std;
float x1,yy1,x2,y2,x3,y3,l1,l2,l3,area;
//calculates the lengths of the (possibly) triangle's sides
void calculate_lengths()
{
    l1=sqrt(pow(x2-x1,2)+pow(y2-yy1,2));
    l2=sqrt(pow(x3-x1,2)+pow(y3-yy1,2));
    l3=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
}
//checks whether or not the given coordinates form a triangle
bool check_if_triangle()
{
    if (l1+l2>l3&&l1+l3>l2&&l2+l3>l1)
    {
        return true;
    }

    return false;
}
//Calculates the area of the triangle using Heron's formula
float calculate_area()
{
    float s=(l1+l2+l3)/2;
    return sqrt(s*(s-l1)*(s-l2)*(s-l3));
}
int main()
{
    cin>>x1>>yy1>>x2>>y2>>x3>>y3;
    calculate_lengths();
    if(!check_if_triangle())
    {
        cout<<"The given coordinates do not form a triangle!\n";
        return 0;
    }
    area = calculate_area();
    cout<<"Here is the triangle's area:\n"<<area;
    return 0;
}

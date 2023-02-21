#include<stdio.h>

struct Point3D
{
    int x,y,z;

    Point3D(int x1, int y1, int z1)
    {
        this->x=x1;
        y=y1;
        z=z1;
    }
};


int main()
{
    Point3D* p=new Point3D(3,4,7);
    Point3D* q=p;

    p->y= 12;
    p->z= -3;
    printf("%d   %d    %d",q->x,q->y,q->z);
    return 0;
}


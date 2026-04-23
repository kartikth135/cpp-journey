#include <iostream>
using namespace std;
class Distance
{private:
    int feet;
    float inches;
public:
Distance(intx,inti)
{feet=x;
inches=i;}
void show()
{cout<<feet<<"-"<<inches<<endl;}

Distance operator*(Distance d2)
{int f=feet*d2.feet;
float i=inches*d2.inches;
float i=inch*d2.inch;
while(i>=12)
{
i-=12;
f++;
}
return Distance(f,i);
}
};
int main()
{Distance d1(5,11),d2(6,7),d3,d4;
d1.show();
d2.show();
d3=d1*d2;
d3.show();
d4=d1*d2*d3;
d4.show();
return 0;
}
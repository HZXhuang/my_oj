#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0); // π的值
const double EPS = 1E-3;  // 控制精度

double getlen(double x1,double y1,double x2,double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double getgcd(double x, double y, double z)
{
    double gcd1 = x > y ? x : y;
    double gcd2 = gcd1 == x ? y : x;
    while(true){
        gcd1 = fmod(gcd1, gcd2);
        double temp = gcd2;
        gcd2 = gcd1;
        gcd1 = temp;
        if (gcd2 <= EPS) break;
    }
    if (z > gcd1){
        double temp = gcd1;
        gcd1 = z;
        z = temp;
    }
    while (true){
        gcd1 = fmod(gcd1,z); // double类型的取模
        double temp1 = gcd1;
        gcd1 = z;
        z = temp1;
        if (z <= EPS) break;
    }
    return gcd1;
}

int main()
{
    double x1,y1,x2,y2,x3,y3,S,a,b,c,R,A,B,C,p,t;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    a = getlen(x1,y1,x2,y2);
    b = getlen(x1,y1,x3,y3);
    c = getlen(x2,y2,x3,y3);
    p = (a + b + c) / 2.0;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    R = a * b * c / (4 * S);
    A = acos((2 * R * R - a * a) / (2 * R * R));
    B = acos((2 * R * R - b * b) / (2 * R * R));
    C = 2 * PI - A - B;  // 减小误差，这里很重要，不然无法通过，因为误差太大
    t = getgcd(A,B,C);
    S = PI * R * R * sin(t) / t;
    printf("%.8f\n", S);

    return 0;
}

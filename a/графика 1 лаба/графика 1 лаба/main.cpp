#include <iostream>
#include <cmath>

using namespace std;

void num1()
{
    double eps = 1e-9;
    double ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    double abx = bx - ax;
    double aby = by - ay;
    double cdx = dx - cx;
    double cdy = dy - cy;
    double acx = cx - ax;
    double acy = cy - ay;

    double vect = abx * cdy - aby * cdx;
    if (fabs(vect) < eps) {
        double vect_tow = abx * acy - aby * acx;
        if (fabs(vect_tow) < eps) {
            cout << "совпадают";
        }
        else {
            cout << "паралельны";
        }

    }
    else {
        cout << "пересекаются";
    }
}
//2
//2 2 1 1 0 0
//точка С лежит на луче
//2
//2 2 3 3 2 2
//точка С совпадает с точкой А
//1
//4 4 5 5 2 2 3 3
//совпадают
//1
//2 2 3 3 4 4 5 5
//совпадают
//1
//1 1 2 2 1 2 2 3
//паралельны

void num2()
{
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    double abx = bx - ax;
    double aby = by - ay;
    double acx = cx - ax;
    double acy = cy - ay;
    double eps = 1e-9;

    double scal = abx * acx + aby * acy;
    if (scal > eps) {
        cout << "точка С лежит на луче";
    }
    else if (fabs(scal) < eps) {
        cout << "точка С совпадает с точкой А";
    }
    else {
        cout << "лежит вне луча";
    }
}

void num3()
{
    double eps = 1e-9;
    double ax, ay, az, bx, by, bz, cx, cy, cz;
    cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;

    double abx = bx - ax;
    double aby = by - ay;

    double acx = cx - ax;
    double acy = cy - ay;

    double nz = abx * acy - aby * acx;

    if (nz < -eps)
        cout << "по часовой";
    else if (nz > eps)
        cout << " против часовой";
    else
        cout << " на одной прямой";
}

void num4() {
    double A1, B1, C1, D1;
    double A2, B2, C2, D2;
    double x0, y0, z0;
    double eps = 1e-9;

    cin >> A1 >> B1 >> C1 >> D1;
    cin >> A2 >> B2 >> C2 >> D2;
    cin >> x0 >> y0 >> z0;

    double E1 = A1*x0 + B1*y0 + C1*z0 + D1;
    double E2 = A2*x0 + B2*y0 + C2*z0 + D2;

    if (fabs(E1) < eps && fabs(E2) < eps)
        cout << "Точка принадлежит прямой";
    else
        cout << "Точка не принадлежит прямой";

}

int main(){
    int in;
    while(true){
        cin >>in;
        if (in == 1){
            num1();
        }
        else if (in == 2){
            num2();
        }
        else if (in == 3){
            num3();
        }
        else if (in == 4){
            num4();
        }
        else{
            return 0;
        }
    }
    
}

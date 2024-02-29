#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main(){
    int a,b,h,m;
    cin>>a>>b>>h>>m;
    double m_angle=M_PI/30;
    double h_angle=M_PI/6;
    double more_angle=(M_PI/6)*(m/60.0);
    double angle=abs((h*h_angle+more_angle)-(m*m_angle));
    if(angle>M_PI){
        angle=abs(2*M_PI)-angle;
    }
    double re=sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(angle));
    cout<<std::fixed<<std::setprecision(14)<<re<<endl;
}
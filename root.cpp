
#include <iostream>
#include <cmath>

using namespace std;
double F(double x)
{return (2*x-exp(-0.1*x));}

double FindHord(double (*f)(double) ,double a ,double b,double tc)
{
    double c;
    while((abs(f(b)-f(a)))>tc)
    {
        c = (f(b)*a-f(a)*b)/(f(b)-f(a));
        if((f(a)*f(c))>0)
        {
            a = c;
        }
        else
        {
            b =c;
        }
    }
    return c;}

double FindDih(double a, double b, double tc)
{ 
double c;
while (abs((b - a) / 2) > tc) 
{
    c = (a + b) / 2;
    if ((F(a) * F(c)) > 0) 
    {
        a = c;
    }
    else
    {
        b = c;
    }
}
return c;}
  
int main()
{
   setlocale(LC_ALL,"Russian");
   cout << "Введите начало и конец интервала:" << endl;
   double a,b,tc,x,z,q;
   cin >> b;
   cin >> a;
   cout << "Введите точность:" << endl;
   cin >> tc;
   if(F(a)*F(b) > 0)
   {
       cout << "False" << endl;
       return 0;
   }
   else
   {
       cout << "True" << endl;
   }
   
   z = FindHord(F,a,b,tc);
   q = FindDih(a,b,tc);
   
   cout << "Метод хорд x=" << z << endl;
   cout << "Метод дихотомии x=" << q << endl;
   


    return 0;
}
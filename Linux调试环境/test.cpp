#include<iostream>
int sum(int a,int b)
{
    return a+b;
}
int main()
{
    int a=10;
    int b=20;
    int S=sum(a,b);
    std::cout<<S<<std::endl;
    return 0;
}

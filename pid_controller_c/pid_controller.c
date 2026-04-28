#include<stdio.h>
int main()
{
    double target=1.0;
    double kp=1.2;
    double ki=0.3;
    double kd=0.1;
    double y=0.0;
    double ynext=0.0;
    double u=0.0;
    int step=100;
    double error=0.0;
    double prev_error=0.0;
    double e_sum=0.0;
    double p_out,i_out,d_out;
    double d_err;
    int k;
    for(k=0;k<step;k++)
    {
        error=target-y;
        e_sum=e_sum+error;
        d_err=error-prev_error;
        u=kp*error+ki*e_sum+kd*d_err;
        ynext=0.8*y+0.2*u;
        printf("k=%d y=%lf u=%lf error=%lf\n",k,y,u,error);
        y=ynext;
        prev_error=error;
    }
    return 0;
}
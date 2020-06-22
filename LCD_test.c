#include <stdio.h>
#include <stdlib.h>

int main()	
{
    int a,b,c,d;
    int x = 2;
    int y = 2;
    int z;
    int f;

    printf("please input first number in the form x/y\n");
    scanf("%d/%d",&a,&b);
    printf("please input another number in the form x/y\n");
    scanf("%d/%d",&c,&d);

    while(x<=a,x<=b)
    {
        if((a%x==0)&&(b%x==0)){
            a = a/x;
            b = b/x;
        }
        else{
            x++;
        }
    }//simplify the first

    while(y<=c,y<=d)
    {
        if((c%y==0)&&(d%y==0)){
            c = c/y;
            d = d/y;
        }
        else{
            y++;
        }
    }

    if(b<d){
        f = b;
        b = d;
        d = f;
    }

    for(z=b;(z%b!=0) || (z%d!=0);z++){

    }

    printf("their least common denominator is 1/%d",z);
    return 0;
}

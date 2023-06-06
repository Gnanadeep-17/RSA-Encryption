#include <stdio.h>
#include<math.h>
int inversefun(int l,int r);
int keygen(int a,int x,int q);
int gcd(int a,int b);
int main()
{
    int p=5,q=11,m=13;
    int ph=(p-1)*(q-1),e=3;
    int c,pl;
    int n=p*q;
    int g;
    c=keygen(m,e,n);
    printf("Encrypted Message=%d\n",c);
    g=gcd(ph,e);
    if(g!=0){
        return -1;
    }
    int s=inversefun(ph,e);

    s=s<0?s+ph:s;
    printf("inverse =%d\n",s);
    pl=keygen(c,s,n);
    printf("decrypted Message=  %d ",pl);
    return 0;
}

int inversefun(int l,int r){
    int q,ri,x,temp;
    static int y=1;
    if(l%r==1)
    return -l/r;
    else{
        q=l/r;
        ri=l%r;
        temp=inversefun(r,ri);
        x=y+(-q)*temp;
       
        if(l%r!=1)
            y=temp;
        return x;
    }
}
int keygen(int a,int x,int q){
    int i=0,d=1;
    while(x>=pow(2,i)){
        i++;
    }
    i-=1;
    while(x!=0){
        d=(d*d)%q;
        if(x>=pow(2,i)){
           x-=pow(2,i);
            d=(d*a)%q;
        }
        i--;
    }
    return d;
}
int gcd(int a,int b){
    int r,temp;
    while(a>b && b>0){
        temp=a;
        a=b;
        r=a%b;
        b=r;
    }
    return a;
}

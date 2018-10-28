//NOJ 5.找幸运数

#include<stdio.h>

int main(){

    int a,b=0,c=0,d;

    scanf("%d",&a);

    d=a;

    while(a>0){
        b=a%10;
        c=c*10+b;
        a/=10;
    }
    if(d==c){
        printf("yes");
    } else {
        printf("no");
    }
    return 0;
}
NOI 8.是该年的第几天？

#include <stdio.h>

int main() {
    int year,moth,day;
    int mo[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int d,i;

    scanf("%d-%d-%d",&year,&moth,&day);

    d=day;
    if((year%4==0&&year%100!=0)||year%400==00) 
    mo[1]=29;
    for(i=0;i<moth-1;i++)
    d+=mo[i];
    printf("%d",d);


} 
//NOJ 9.成绩转换

#include <stdio.h>

int main() {
    int year,moth,day;
    int mo[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int d,i;

    scanf("%d-%d-%d",&year,&moth,&day);

    d=day;
    if((year%4==0&&year%100!=0)||year%400==00) 
    mo[1]=29;
    for(i=0;i<moth-1;i++)
    d+=mo[i];
    printf("%d",d);


}
//NOJ 12.五猴分桃

#include<stdio.h>
#include<math.h>
int main(){

    int a=pow(5,5)-4;
    int b,i;

    b=a;

    for(i=1;i<=5;i++){
        b=(b-1)/5*4;


    } 
    printf("%d %d",a,b);
    return 0;
}
//NOJ 13.你会存钱吗？

#include <stdio.h>
#include<math.h>
int main( )
{
    double r1, r2, r3, r5, r8, d, z, max;//r1,r2,r3,r5,r8，表示1年，2年，3年，5年，8年的年利率，
    int i1, i2, i3, i5, i8, n1, n2, n3, n5, n8;//用i1，i2，i3，i5，i8表示1年，2年，3年，5年，8年存款的次数。
    n1=n2=n3=n5=n8=0;
    r1=0.63/100*12;   r2=0.66/100*12;
    r3=0.69/100*12;   r5=0.75/100*12;
    r8=0.84/100*12;
    max=d=2000;
    for(i8=0; i8<=2; i8++)
    for(i5=0; i5<=(20-i8*8)/5; i5++)
    for(i3=0; i3<=(20-i8*8-i5*5)/3; i3++)
    for(i2=0; i2<=(20-i8*8-i5*5-i3*3)/2; i2++){
            i1=20-i8*8-i5*5-i3*3-i2*2;
            z=d*pow(1+r1, i1)*pow(1+r2*2, i2)*pow(1+r3*3, i3)
           *pow(1+r5*5, i5)*pow(1+r8*8, i8);
            if(z>max){
                    max=z; n1=i1; n2=i2; n3=i3; n5=i5; n8=i8;  }
                    }
    printf("%d %d %d %d %d\n", n8,n5,n3,n2,n1);
    printf("%.2f\n", max);
}
//NOJ 21.合数世纪

#include<stdio.h>
#include<math.h>
int main(){
    int n,m=0,a,b,i,o,l;
    scanf("%d",&n);
    for(a=0,b=99;m<n;a=a+100,b=b+100){
        for(i=a;i<=b;i++){
            for(o=2,l=0;o<=sqrt(i);o++){
                if(i%o==0) {
                l=1;
                break;}
            }
            if(l==0) break;
        }
    if(l==1)m++;
    }
    printf("%d %d",a-100,b-100);
    return 0;
}
·可以直接从样例入手 直接从n=1开始判断
·判断素数 i<=sqrt(n)优化为i方<=n (可以不用加<math.h>，但可能数据溢出） 继续优化为 i<=n/i（不会产生溢出）
·时间复杂度一般10^7左右 不要达到10^9
//NOJ 22.排列

- //思路：计算abc,def,ghi三个数中1-9每个数字的频数，如果至少有一个数字的频数不为1，就不符合条件。
- #include<iostream>
- #include<cstdio>
- #include<algorithm>
- #include<cmath>
- #include<cstring>
- using namespace std;
-
- int main()
- {
- int abc,def,ghi,i;
- int a[10];
- memset(a,0,sizeof(a));
- for(abc=123;abc<=987/3;abc++)
- {
- def=2*abc;
- ghi=3*abc;
- a[abc/100]++;
- a[abc/10%10]++;
- a[abc%10]++;
- a[def/100]++;
- a[def/10%10]++;
- a[def%10]++;
- a[ghi/100]++;
- a[ghi/10%10]++;
- a[ghi%10]++;
- for(i=1;i<10;i++)
- if(a[i]!=1) break;
- if(i==10) printf("%d %d %d\n",abc,def,ghi);
- memset(a,0,sizeof(a));
- }
- return 0;
- ｝
- //把频数数组换成标记数组，某个数字i出现过则置a[i]=1。如果不符合条件，必然至少有一个数组元素没有被标记。
- #include <stdio.h>
- #include <stdlib.h>
- #include <string.h>
- int main()
- {
- int abc,def,ghi,i;
- int a[10];
-
- memset(a, 0, sizeof(a));
- for(abc = 123; abc <= 329; abc++)
- {
- def = 2*abc;
- ghi = 3*abc;
-
- a[abc/100] = a[abc/10%10] = a[abc%10] = 1;
- a[def/100] = a[def/10%10] = a[def%10] = 1;
- a[ghi/100] = a[ghi/10%10] = a[ghi%10] = 1;
-
- for( i = 1; i <= 9; i++)
- if(a[i]==0) break;
- if(i==10) printf("%d %d %d\n", abc, def, ghi);
- memset(a, 0, sizeof(a));
- }
- return 0;
- }
//NOJ 23.最大乘积

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20],s=1,n,m,i=1,j=1,b,e,f;
    scanf("%d",&n);
    m=n;
    for(n=0;n<m;n++)
        scanf("%d",&a[n]);
    if (m==1) {
        if (a[0]<0) printf("-1");
        else printf("%d",a[0]);
        return 0;
    };
    if (m==2) {
        if ((a[0]<0)&&(a[1]<0)) printf("%d",(a[0]*a[1]));
        else if ((a[0]>0)&&a[1]>0) printf("%d",(a[0]*a[1]));
             else if (a[0]>a[1]) printf("%d",a[0]);
                  else printf("%d",a[1]);
                  return 0;
    };
    b=0;
    for (n=0;n<m;n++)
        if (a[n]<0) b=b+1;
    if (b%2==0) {
        for (n=0;n<m;n++)
            s=s*a[n];
        printf("%d",s);
        return 0;
    }
    else {
      for (n=0;n<m;n++)
      if (a[n]<0) {
        e=n;
        break;
      };
      for (n=m-1;n>=0;n--)
        if (a[n]<0) {
        f=n;
        break;
      };
      for (n=e+1;n<m;n++)
        i=i*a[n];
      for (n=f-1;n>=0;n--)
        j=j*a[n];
      if (i>j) s=i;
      else s=j;
      printf("%d",s);
    };
    return 0;
}
//NOJ 25.“1”的传奇

#include<stdio.h>
int main()
{
int x,y=0,t;
scanf("%d",&x);
for(t=1;x/t>0;t*=10){
y+=x/(t*10)*t;
if(x/t%10>1) y+=t;
else if(x/t%10) y+=x%t+1;
}
printf("%d\n",y);
return 0;
}
//NOJ 27.除法

//思路：计算abcde。fghi两个数中1-9每个数字的频数，如果至少有一个数字的频数不为1，就不符合条件。  
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cmath>  
#include<cstring>  
using namespace std;  

int main()  
{  
    int abcde,fghi,i,n;  
    int a[10];  
    memset(a,0,sizeof(a));
    scanf("%d",&n);  
    for(abcde=n*1234;abcde<=98765;abcde++)  
    {  
        for(fghi=1234;fghi<=98765/n;fghi++) {
        if((abcde*1.00)/fghi==n){     
        a[abcde/10000]++;  
        a[abcde/1000%10]++;  
        a[abcde/100%10]++;  
        a[abcde/10%10]++;  
        a[abcde%10]++;  
        a[fghi/1000]++;  
        a[fghi/100%10]++;  
        a[fghi/10%10]++; 
        a[fghi%10]++;   
        for(i=1;i<10;i++)  
            if(a[i]!=1) break;  
        if(i==10) printf("%d/%05d=%d\n",abcde,fghi,n);  
        memset(a,0,sizeof(a));
    }
    }
    }  
    return 0;  
    }
//NOJ 29.危险的组合//盒子里装有铀和铅

#include<stdio.h>
#include<math.h>
int main()
{int n;
int f(int);
scanf("%d",&n);
printf("%d",f(n));
return 0;
}
int f(int n)
{int a;
if(n==1||n==2)
a=0;
else if(n==3)
a=1;
else if(n==4)
a=3;
else
a=f(n-1)*2+pow(2,n-4)-f(n-4);
return a;
}
//NOJ 30.特殊整数

#include<stdio.h>
#include<math.h>
int main(){
    int m,n,i,o,g=0;
    double  s=0;//设置double来避免数据溢出
    scanf("%d %d",&m,&n);
    for(i=pow(10,n-1);i<pow(10,n);i++){
        o=i;
        while(o>0){
            if(o%10==m) break;
            o/=10;
        }
        if(o){
            if(i%m!=0){
                g++;
                s+=i;
            }
        }
    }
    printf("%d %.0lf",g,s);
    return 0;
}
//NOJ 33，亲和数

#include<stdio.h>
int main(){
    int i,s,A,B;
    scanf("%d %d",&A,&B);
    for(i=1,s=0;i<A;i++){
        if(A%i==0) s+=i;
    }
    //printf("%d",s);
    if(s!=B) {
    printf("NO");
    return 0;//防止输出两个NO 
    }
    for(i=1,s=0;i<B;i++){
        if(B%i==0) s+=i;
    }
    //printf("%d",s);
    if(s==A) printf("YES");
    else printf("NO");
    return 0;
}
//NOJ 35.最大整数

#include <stdio.h>
//#include <stdlib.h>
    int getfloor(double m)
{
    int n;
    n=m;
    if(n!=m&&n<0) //循环嵌套可以通过逻辑语句简化 
        n--;
    return n;
}
int main()
{
    double x;
    scanf("%lf",&x);
    printf("%d",getfloor(x));
    return 0;
}
//NOJ 37.逆序整数
1.网易云课堂 翁凯//输出时前面不会有0 甩了答案不止一条街

#include<stdio.h>
int main(){
    int n,m=0,i;
    scanf("%d",&n);
    while(n>0){
        i=n%10;
        m=10*m+i;
        n/=10;
    }
    printf("%d",m);
    return 0;
}
2.//NOJ答案

#include <stdio.h>

int nixu(int n)
{
  if(n>10) {
  printf("%d",n%10);
  nixu(n/10);
  }
  else{
  printf("%d",n);
  return 0;}
}
int main()
{
  int n;
  scanf("%d",&n);
  nixu(n);
  return 0;
}
//NOJ 39.模版函数

#include<iostream>
using namespace std;
template<typename T>
void fuc(T x,T y,T z)
{
    T t;
    if(x>y){
        t=y;
        y=x;
        x=t;
    }
    if(x>z){
        t=z;
        z=x;
        x=t;
    }
    if(y>z){
        t=y;
        y=z;
        z=t;
    }
    cout<<x<<' '<<y<<' '<<z<<endl;
}
int main(){
    int a,b,c;
    char m,n,o;
    double d,e,f;
    cin>>a>>b>>c>>m>>n>>o>>d>>e>>f;
    fuc(a,b,c);
    fuc(m,n,o);
    fuc(d,e,f);
    return 0;
}
//NOJ 41.插入法排降序

#include<stdio.h>
void InsertionSort(int A[],int s,int m){//插入法排降序
    int i,k,t;
    for(i=s+1;i<s+m;i++){
        t=A[i],k=i-1;
        while(t>A[k]){
        A[k+1]=A[k],k--;
        if(k==s-1)break;
        }
        A[k+1]=t;
    }   
}
    //int A[100];
int main(){
    int N,s,m,i,A[100];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);//输入A【N】
    }
    scanf("%d%d",&s,&m);
    InsertionSort(A,s,m);
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
//NOJ 42.选择法排降序

#include<stdio.h>
void InsertionSort(int A[],int s,int m){//选择法排降序
    int i,j,k,t;
    for(i=s;i<s+m;i++){
        k=i;
        for(j=i+1;j<s+m;j++){
            if(A[j]>A[k])k=j;
            if(i!=k) t=A[i],A[i]=A[k],A[k]=t;        }
    }   
}
    //int A[100];
int main(){
    int N,s,m,i,A[100];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);//输入A【N】
    }
    scanf("%d%d",&s,&m);
    InsertionSort(A,s,m);
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
//NOJ 44.冒泡法排降序

#include<stdio.h>
void InsertionSort(int A[],int s,int m){//冒泡排降序
    int i,j,k,t;
    for(i=s,k=1;i<s+m-1;i++,k++){
        for(j=s;j<s+m-k;j++){
            if(A[j]<A[j+1])  t=A[j],A[j]=A[j+1],A[j+1]=t;        }
    }   
}
int main(){
    int N,s,m,i,A[100];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);//输入A【N】
    }
    scanf("%d%d",&s,&m);
    InsertionSort(A,s,m);
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
//NOJ 49.快速排降序

#include<stdio.h>
void QuickSort(int A[],int s,int m){//快速排降序
    int i,j,t,left=s,right=s+m-1;
    if    (left<right){
        i=left;j=right+1;
        while(1){
            while(i<s+m&&A[++i]>A[left]);//向后搜索
            while(j-1>-1&&A[--j]<A[left]);//向前搜索
            if(i>=j) break;
            t=A[i],A[i]=A[j],A[j]=t;            //交换
        }
    t=A[left],A[left]=A[j],A[j]=t;        //交换
    QuickSort(A,s,j-s);            //关键数据左半部分递归
    QuickSort(A,j+1,m-j+s-1);    //关键数据右半部分递归
    }
}
int main(){
    int N,s,m,i,A[100];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);//输入A【N】
    }
    scanf("%d%d",&s,&m);
    QuickSort(A,s,m);
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    return 0;
}


#include <stdlib.h>
#include <stdio.h>
void QuickSort(int a[],int numsize)
{
int i=0,j=numsize-1;
int val=a[0];
if(numsize>1)
{
while(i<j)
{
for(;j>i;j--)
if(a[j]>val)
{
a[i++]=a[j];
break;
}
for(;i<j;i++)
if(a[i]<val)
{
a[j--]=a[i];
break;
}
}
a[i]=val;
QuickSort(a,i);
QuickSort(a+i+1,numsize-i-1);
}
}
int main()
{
    int n,b[99],a[99],s,m,i,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    scanf("%d%d",&s,&m);
    for(i=s;i<=m;i++)
    a[i-s]=b[i];
    l=m-s+1;
    QuickSort(a,l);
    for(i=s;i<=m;i++)
    b[i]=a[i-s];
    for(i=0;i<n;i++)
    printf("%d ",b[i]);
    return 0;
}


#include <stdio.h>

using namespace std;

void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/

    while(first < last)
    {
        while(first < last && a[last] <= key)
        {
            --last;
        }

        a[first] = a[last];/*将比第一个大的移到低端*/

        while(first < last && a[first] >= key)
        {
            ++first;
        }

        a[last] = a[first];   
/*将比第一个小的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}
int main(){
    int N,s,m,i,A[100];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);//输入A【N】
    }
    scanf("%d%d",&s,&m);
    Qsort(A,s,s+m-1);
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    return 0;
}

 //NOJ 43.输出左上角

#include<stdio.h>

int a[100][100];
int main(){
    int N,i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<N;i++){//输出左上角
        for(j=0;j<N;j++){
            if(i+j<=N-1)
            printf("%d ",a[i][j]);
        }
        printf("\n");

    }
    return 0;
}
//NOJ 47.输出左下角

#include<stdio.h>

int a[100][100];
int main(){
    int N,i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<N;i++){//输出左下角
        for(j=0;j<N;j++){
            if(i>=j)
            printf("%d ",a[i][j]);
        }
        printf("\n");

    }
    return 0;
}


#include <iostream>
using namespace std;

//扩展欧几里德算法
int extgcd(int a, int b, int &x, int &y)
{
	if(b == 0) {x=1; y=0; return a;}
	int d = extgcd(b,a%b,x,y);
	int t = x; x = y; y = t-a/b*y;
	return d;
}

int china(int b[], int w[], int k)//w[]存放互质的数，b[]存放余数
{
	int i,d,x,y,m,a=0,n=1;
	for(i=0;i<k;++i) n *= w[i];
	for(i=0; i<k; ++i)
	{
		m = n / w[i];
		d = extgcd(w[i],m,x,y);
		a = (a + y*m*b[i]) % n;
	}
	if(a > 0) return a;
	else return a+n;
}

int main()
{
	int b[3] = {2,2,3};
	int w[3] = {3,7,5};
	int dmin = china(b,w,3);
	cout<<dmin<<endl;
	return 0;
}

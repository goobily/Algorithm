#include <iostream>
using namespace std;

/************************************************************************/
/*      欧几里德算法求最大公约数 【辗转相除法】                             */
/************************************************************************/
int gcd_recur(int a, int b)
{
	if (b == 0) return a;
	return gcd_recur(b, a%b);
}

int gcd_iter(int a, int b)
{
	while(b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
/************************************************************************/
/* a*x + b*y = gcd(a,b)                                                 */
/************************************************************************/
int ex_gcd(int a, int b, int& x, int& y)
{
	if (b == 0) {
		x = 1; 
		y = 0;
		return a;
	}
	else {
		int r = ex_gcd(b, a%b, x, y);
		int t = x;
		x = y;
		y = t - a/b*y;
		return r;
	}
}

/************************************************************************/
/*  中国剩余定理:
设 ：
1. w[] 为两两互质的数，i=0,1,...,k
2. b[] 为对应余数, i=0,1,...,k

设 Mi 为能够被w[0], w[1], ... , w[i-1], w[i+1], ... , w[k] 整除，但是 除以w[i]正好余1，(Mi % w[i] =1 )
即： Mi是w[0],w[1], ... , w[i-1], w[i+1], ... , w[k]的最小公倍数，且 Mi % w[i] = 1
如果 M0, M1, ... , Mk 都求出来了，那么：
 X = M0*b[0] + M1*b[1] + ... + Mk*b[k] 就是要求的一个解。
 X % (w[0]*w[1]*...*w[k])就是最小整数解了，若小于0，则加上一个(w[0]*w[1]*...*w[k])即可。

 怎么求Mi :

 设 W = w[0]*w[1]*...*w[k] ， x, y为任意整数
 因为 Mi 能够被w[0], w[1], ... , w[i-1], w[i+1], ... , w[k] 整除
 所以有： Mi = W/w[i] * x; 又因为 Mi % w[i] =1, 
 所以有： Mi = w[i]*y + 1;
 所以 W/w[i] * x = w[i]*y + 1 
 ===》 W/w[i] * x + （-w[i]*y） = 1 
 因为 w[]是两两互质的数，所以W/w[i]和-w[i]也互质
 因此有：  W/w[i] * x + （-w[i]*y） = 1 = gcd(W/w[i], -w[i]); ---->扩展欧几里德原型
*/
/************************************************************************/

int china(int w[], int b[], int k)
{
	int i, gcd, x, y;
	int W=1, result=0;
	for(i=0; i<k; ++i)
		W *= w[i];
	for(i=0; i<k; ++i) {
		gcd = ex_gcd(W/w[i], w[i], x, y);
		result += x*W/w[i]*b[i];
	}
	
	return (result%W + W) % W;
}


int main()
{
	/*int a,b;
	cin >>a >>b;
	int x,y;
	cout <<"gcd(" <<a << ", " << b <<") = " <<gcd_recur(a,b)<<endl;
	cout <<"gcd(" <<a << ", " << b <<") = " <<gcd_iter(a,b)<<endl;
	int gcd_ = ex_gcd(a,b,x,y);
	cout << "[" <<gcd_ << ":" << x << ":" << y << "]" <<endl;*/

	int bb[3] = {2,2,3};
	int ww[3] = {3,7,5};
	int dmin = china(ww, bb,3);
	cout << "china : " << dmin <<endl;
	return 0;
}
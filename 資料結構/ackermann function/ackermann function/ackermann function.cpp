#include<iostream>
using namespace std;
double ack(double m,double n)
{
	while (m != 0)
	{
		if (n == 0)
			n = 1;
		else
			n = ack(m, n - 1);
			m = m - 1;
	}
	return n + 1;
	
}
int main()
{
	double a, b;
	cin >> a >> b;
	cout << ack(a, b) << endl;
}
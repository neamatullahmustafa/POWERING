#include <iostream>
#include <chrono>
long long time()
{
	using namespace std::chrono;
	return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}
long double power_rec(unsigned int A, unsigned int N)
{
	long double pow = 1;
	if (N == 1) 
		return A;
	 pow = power_rec(A, N / 2);
	if (N % 2 == 0)
		return pow * pow;
	else
		return A * pow * pow;
}
long double power_loop(unsigned int a, unsigned int n)
{
	long double pow = 1;
	for (int i = 0; i < n; i++)
		pow *= a;
	return pow;
}
using namespace std;
int main() 
{
	double long power = 1, start_time_loop = 0, end_time_loop = 0
                         , start_time_rec = 0, end_time_rec = 0;
	int unsigned n = 0 , a = 1;
	cout << "please enter the number\n";
	cin >> a;
	cout << "please enter the power\n";
	cin >> n;
	start_time_loop = time();
	power = power_loop(a, n);
	cout << "pow with loop = " << power << "\n";
	end_time_loop = time();
	cout <<"time with loop = "<<end_time_loop - start_time_loop << " micro sec\n";
	start_time_rec = time();
	power = power_rec(a, n);
	cout << "pow with recursion = " << power << "\n";
	end_time_rec= time();
	cout << "time with recursion = " << end_time_rec - start_time_rec << " micro sec\n";
	return 0;
}


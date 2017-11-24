#include <iostream>

using namespace std;

unsigned long long int rec_fib(unsigned short);
unsigned long long int generated_fib(unsigned short);

int main()
{
    unsigned short nth_fib_number;
    cin >> nth_fib_number;
    cout << "Nth fibonacci  number is: " << rec_fib (nth_fib_number) << '\n'; //time complexity: 2^n
    cout << "Nth fibonacci  number is: " << generated_fib (nth_fib_number) << '\n'; //time complexity: n
    return 0;
}

unsigned long long int rec_fib(unsigned short N)
{
    return (N == 1 || N == 2) ? (1) : (rec_fib(N-1)+rec_fib(N-2));

}

unsigned long long int generated_fib(unsigned short N)
{
    unsigned long long a=1, b=1, c=1;
    for(int i = 0; i< N-2; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

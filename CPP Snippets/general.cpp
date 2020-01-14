#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
//#include <iomanip>
//#include <locale>
using namespace std;

#define PE 1e-8
#define M_PI 3.14159265358979323846
#define M_PIL 3.141592653589793238462643383279502884L

//***format double or int with commmas***
//? way1:

string FormatWithCommas(double value)
{
    stringstream ss;
    ss.imbue(locale(""));
    ss << fixed << showpoint << setprecision(2) << value;
    return ss.str();
}
//? way 2: alternative faster way
class comma_numpunct : public std::numpunct<char>
{
protected:
    virtual char do_thousands_sep() const
    {
        return ',';
    }

    virtual std::string do_grouping() const
    {
        return "\03";
    }
};
//? way3: simpler way
void printfcomma(int n)
{
    if (n < 1000)
    {
        printf("%d", n);
        return;
    }
    printfcomma(n / 1000);
    printf(",%03d", n % 1000);
}
//need to write in main
int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
}
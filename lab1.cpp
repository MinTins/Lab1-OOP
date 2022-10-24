#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int n = 1000;
int c[10];

void reset(int *p)
{
    for (int i = 0; i < 10; i++)
    {
        *(p + i) = 0;
    }
}

int menu()
{
    cout << "1 : Linear congruent method" << endl;
    cout << "2 : Quadr congruent method" << endl;
    cout << "3 : Fibonacci numbers" << endl;
    cout << "4 : Inverse congruent sequence" << endl;
    cout << "5 : Merge method" << endl;
    cout << "6 : \"3 sigma\" rule" << endl;
    cout << "7 : Polar coordinate method" << endl;
    cout << "8 : The method of relations" << endl;
    cout << "9 : Logarithm method for generating an indicative distribution" << endl;
    cout << "10: Ahrens method for generating a gamma distribution of order a > 1" << endl;
    cout << "-1:  --Quit--" << endl
         << endl;
    cout << "-> ";

    int met;
    if (!(cin >> met))
    {
        met = 0;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return met;
}

long long getValue(const char *prompt)
{
    long long value;

    while (1)
    {
        cout << "Value of \"" << prompt << "\": ";
        if (cin >> value)
        {
            break;
        }
        else
        {
            cout << "*Wrong input*" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        };
    }

    return value;
}

bool check_prime(long long n)
{
    bool is_prime = true;

    if (n == 0 || n == 1)
    {
        is_prime = false;
    }

    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }

    return is_prime;
}

void getCount()
{
    int count = 0;

    while (1)
    {
        cout << "*How many elements -> ";
        if (cin >> count)
        {
            n = count;
            if (count < 1)
            {
                cout << "\n*Wrong input*" << endl;
                continue;
            }
            break;
        }
        else
        {
            cout << "\n*Wrong input* | Set a default - 1000" << endl;
            count = 1000;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        };
    }
    n = count;
}

void getActionType(int &act_type)
{
    while (act_type < 1 || act_type > 3)
    {
        cout << "\nSelect a method:\n   1) preset value\n   2) own value\n-> ";
        if (!(cin >> act_type))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        };
    }
}

void method01(unsigned long long x0, long long a, long long c_, long long m, vector<unsigned long long> &x1_vls)
{
    unsigned long long x;
    for (int i = 0; i < n; i++)
    {
        x = (a * x0 + c_) % m;
        x1_vls.push_back(x);
        double u = (double)x / m;
        x0 = x;
        c[(int)(u * 10)]++;
    }
}

vector<unsigned long long> method01(int act_type = 1)
{
    vector<unsigned long long> x1_vls;
    getActionType(act_type);

    if (act_type == 1)
    {
        method01(42949672, 82589933, 4294967279, 4294967291, x1_vls);
    }
    else
    {
        long long x0;
        long long a, m, c_;

        while (1)
        {
            x0 = getValue("x0");
            a = getValue("a");
            c_ = getValue("c");
            m = getValue("m");

            if (!(m > 0))
            {
                cout << "*Error input: Must be -> m > 0" << endl;
            }
            else if (!(a >= 0 && a < m))
            {
                cout << "*Error input: Must be -> 0 <= a < m" << endl;
            }
            else if (!(c_ >= 0 && c_ < m))
            {
                cout << "*Error input: Must be -> 0 <= c < m" << endl;
            }
            else if (!(x0 >= 0 && x0 < m))
            {
                cout << "*Error input: Must be -> 0 <= x0 < m" << endl;
            }
            else if (!(check_prime(c_)))
            {
                cout << "*Error input: 'c' must be prime" << endl;
            }
            else if (!(check_prime(m)))
            {
                cout << "*Error input: 'm' must be prime" << endl;
            }
            else if (((a - 1) % m == 0))
            {
                cout << "*Error input: b = a-1 must be multiple to p (divider m)" << endl;
            }
            else if (!(m % 4 != 0 || (a - 1) % 4 != 0))
            {
                cout << "*Error input: b must be multiple to 4" << endl;
            }
            else
            {
                break;
            }
        }

        method01(x0, a, c_, m, x1_vls);
    }
    return x1_vls;
}

void method02(unsigned long long x0, long long a, long long d, long long c_, long long m, vector<unsigned long long> &x2_vls)
{
    unsigned long long x;
    for (int i = 0; i < n; i++)
    {
        x = (d * x0 * x0 + a * x0 + c_) % m;
        x2_vls.push_back(x);
        double u = (double)x / m;
        x0 = x;
        c[(int)(u * 10)]++;
    }
}

vector<unsigned long long> method02(int act_type = 1)
{
    vector<unsigned long long> x2_vls;
    getActionType(act_type);

    if (act_type == 1)
    {
        method02(42949672, 4294967197, 4294967231, 4294967279, 4294967291, x2_vls);
    }
    else
    {
        long long x0, a, d, m, c_;

        while (1)
        {
            x0 = getValue("x0");
            a = getValue("a");
            d = getValue("d");
            c_ = getValue("c");
            m = getValue("m");
            cout << x0 << " " << a << " " << d << " " << m << " " << c_ << endl;

            if (!(m > 0))
            {
                cout << "*Error input: Must be -> m > 0" << endl;
            }
            else if (!(check_prime(c_)))
            {
                cout << "*Error input: 'c' must be prime" << endl;
            }
            else if (!(check_prime(m)))
            {
                cout << "*Error input: 'm' must be prime" << endl;
            }
            else if (!(m % 2 != 1 || ((a - 1) % m != 0 && d % m != 0)))
            {
                cout << "*Error input: d and a-1 must be multiple to p (divider m)" << endl;
            }
            else if (!((d % 2 != 0 && (d % ((a - 1) % 4)) != 0 && m % 4 != 0) || (d % ((a - 1) % 2) != 0 && m % 2 != 0)))
            {
                cout << "*Error input: d must be even and multiple under appropriate conditions" << endl;
            }
            else if (!(m % 3 != 0 || d % ((3 * c_) % 9 == 0)))
            {
                cout << "*Error input: d must be not multiple to 3c mod 9" << endl;
            }
            else
            {
                break;
            }
        }
        method02(x0, a, d, c_, m, x2_vls);
    }
    return x2_vls;
}

void method03(long long x0, long long x1, long long m)
{
    long long x = x1;
    for (int i = 0; i < n; i++)
    {
        x1 = (x + x0) % m;
        double u = (double)x1 / m;
        x0 = x;
        x = x1;
        c[(int)(u * 10)]++;
    }
}

void method03(int act_type = 1)
{
    getCount();
    getActionType(act_type);

    switch (act_type)
    {
    case 1:
        method03(1247437, 224743647, 4294967291);
        break;
    case 2:
        method03(getValue("x0"), getValue("x1"), getValue("m"));
        break;
    }
}

long long inversion(long x, long long m)
{
    long long inv;
    for (long long i = 0; i < m; i++)
    {
        if ((x * i) % m == 1)
        {
            inv = i;
        }
    }
    return inv;
}

void method04(long long x0, long long a, long long c_, long long m)
{
    long x;
    for (int i = 0; i < n; i++)
    {
        x = (a * inversion(x0, m) + c_) % m;
        double u = (double)x / m;
        x0 = x;
        c[(int)(u * 10)]++;
    }
}

void method04(int act_type = 1)
{
    getCount();
    getActionType(act_type);

    switch (act_type)
    {
    case 1:
        method04(17, 29, 18, 6543);
        break;
    case 2:
        method04(getValue("x0"), getValue("a"), getValue("c"), getValue("m"));
        break;
    }
}

void method05_m(long long m)
{
    cout << "\nFor numbers generator by method 1:";
    vector<unsigned long long> x_v = method01(0);
    cout << "\nFor numbers generator by method 2:";
    vector<unsigned long long> y_v = method02(0);
    reset(c);

    unsigned long long z;
    for (int i = 0; i < n; i++)
    {
        z = (x_v[i] - y_v[i]) % m;
        double u = (double)z / m;
        c[(int)(u * 10)]++;
    }
}

void method05(int act_type = 1)
{
    getCount();
    getActionType(act_type);

    switch (act_type)
    {
    case 1:
        method05_m(4294967291);
        break;
    case 2:
        method05_m(getValue("m"));
        break;
    }
}

void for_method06_08(double x)
{
    if (-3 <= x && x < -2.4)
    {
        c[0]++;
    }
    if (-2.4 <= x && x < -1.8)
    {
        c[1]++;
    }
    if (-1.8 <= x && x < -1.2)
    {
        c[2]++;
    }
    if (-1.2 <= x && x < -0.6)
    {
        c[3]++;
    }
    if (-0.6 <= x && x < 0)
    {
        c[4]++;
    }
    if (0 <= x && x < 0.6)
    {
        c[5]++;
    }
    if (0.6 <= x && x < 1.2)
    {
        c[6]++;
    }
    if (1.2 <= x && x < 1.8)
    {
        c[7]++;
    }
    if (1.8 <= x && x < 2.4)
    {
        c[8]++;
    }
    if (2.4 <= x && x <= 3)
    {
        c[9]++;
    }
}

void method06_m(long long m)
{
    cout << "\nFor numbers generator by method 1:";
    vector<unsigned long long> x_v = method01();
    reset(c);
    double sum;
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < 12; s++)
        {
            double u = (double)x_v[i + s] / m;
            sum += u;
        }
        sum -= 6;
        for_method06_08(sum);
        sum = 0;
    }
}

void method06(int act_type = 1)
{
    getCount();
    getActionType(act_type);

    switch (act_type)
    {
    case 1:
        method06_m(4294967291);
        break;
    case 2:
        method06_m(getValue("m"));
        break;
    }
}

void method07_m(long long m)
{
    cout << "\nFor numbers generator by method 1:";
    vector<unsigned long long> x_v = method01();
    reset(c);
    double u1, u2, v1, v2, s, xf1, xf2;
    for (int i = 0; i < n; i++)
    {
        u1 = (double)x_v[i] / m;
        u2 = (double)x_v[1 + i] / m;
        v1 = 2 * u1 - 1;
        v2 = 2 * u2 - 1;
        s = v1 * v1 + v2 * v2;
        if (s < 1)
        {
            xf1 = v1 * sqrt((-2 * log(s)) / s);
            xf2 = v2 * sqrt((-2 * log(s)) / s);
            for_method06_08(xf1);
            for_method06_08(xf2);
        }
    }
}

void method07(int act_type = 1)
{
    getCount();
    getActionType(act_type);

    switch (act_type)
    {
    case 1:
        method07_m(4294967291);
        break;
    case 2:
        method07_m(getValue("m"));
        break;
    }
}

void method08(long long m1, long long m2)
{
    cout << "\nFor numbers generator by method 1:";
    vector<unsigned long long> x_v = method01();
    cout << "\nFor numbers generator by method 2:";
    vector<unsigned long long> y_v = method02();
    reset(c);

    for (int i = 0; i < n; i++)
    {
        double u = (double)x_v[i] / m1;
        double v = (double)y_v[i] / m2;
        if (u != 0)
        {
            double xf = sqrt(8 / M_E) * (v - 0.5) / u;
            if (xf * xf <= -4 * log(u))
            {
                for_method06_08(xf);
            }
        }
    }
}

void method08(int act_type = 1)
{
    getCount();
    getActionType(act_type);

    switch (act_type)
    {
    case 1:
        method08(4294967291, 4294967291);
        break;
    case 2:
        method08(getValue("m1"), getValue("m2"));
        break;
    }
}

void method09(long long m, long long mu)
{
    cout << "\nFor numbers generator by method 2:";
    vector<unsigned long long> x_v = method02();
    reset(c);
    double u, xf;
    for (int i = 0; i < n; i++)
    {
        u = (double)x_v[i] / m;
        xf = -mu * log(1 - u);
        if (xf < 100)
        {
            c[(int)xf / 10]++;
        }
    }
}

void method09(int act_type = 1)
{
    getCount();
    getActionType(act_type);

    switch (act_type)
    {
    case 1:
        method09(4294967291, 20);
        break;
    case 2:
        method09(getValue("m"), getValue("mu"));
        break;
    }
}

void method10(long long m1, long long m2, long a)
{
    cout << "\nFor numbers generator by method 1:";
    vector<unsigned long long> x_v = method01();
    cout << "\nFor numbers generator by method 2:";
    vector<unsigned long long> y_v = method02();
    reset(c);
    double y, xf, u, v;
    for (int i = 0; i < n; i++)
    {
        u = (double)x_v[i] / m1;
        y = tan(u * M_PI);
        xf = sqrt(2 * a - 1) * y + a - 1;
        if (xf > 0)
        {
            v = (double)y_v[i] / m2;
            if (v <= ((1 + y * y) * exp((a - 1) * log((xf) / (a - 1)) - sqrt(2 * a - 1) * y)))
            {
                c[(int)xf / 10]++;
            }
        }
    }
}

void method10(int act_type = 1)
{
    getCount();
    getActionType(act_type);

    switch (act_type)
    {
    case 1:
        method10(4294967291, 4294967291, 17);
        break;
    case 2:
        method10(getValue("m1"), getValue("m2"), getValue("a"));
        break;
    }
}

void histogram1_5()
{
    int precision = 2;
    cout << '\n'
         << "  Range       "
         << "Frequency" << endl;

    for (int i = 0; i < 9; i++)
    {
        double current_range = (double)i / 10;
        cout << "[" << setprecision(1) << fixed << current_range << ";" << current_range + 0.1 << ")"
             << "      " << setprecision(precision) << (double)c[i] / n << fixed << endl;
    }
    cout << "[0.9;1.0]"
         << "      " << fixed << (double)c[9] / n << '\n'
         << endl;
}

void histogram6_8()
{
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << '\n'
         << "  Range       "
         << "Frequency" << endl;
    cout << "[-3.0;-2.4)"
         << "      " << (double)c[0] / n << endl;
    cout << "[-2.4;-1.8)"
         << "      " << (double)c[1] / n << endl;
    cout << "[-1.8;-1.2)"
         << "      " << (double)c[2] / n << endl;
    cout << "[-1.2;-0.6)"
         << "      " << (double)c[3] / n << endl;
    cout << "[-0.6; 0.0)"
         << "      " << (double)c[4] / n << endl;
    cout << "[0.0 ; 0.6)"
         << "      " << (double)c[5] / n << endl;
    cout << "[0.6 ; 1.2)"
         << "      " << (double)c[6] / n << endl;
    cout << "[1.2 ; 1.8)"
         << "      " << (double)c[7] / n << endl;
    cout << "[1.8 ; 2.4)"
         << "      " << (double)c[8] / n << endl;
    cout << "[2.4 ; 3.0]"
         << "      " << (double)c[9] / n << '\n'
         << endl;
}

void histogram9_10()
{
    cout.precision(2);
    cout.setf(ios::fixed);
    int precision = 2;
    cout << '\n'
         << "  Range         "
         << "Frequency" << endl;

    cout << "[ 0; 10)"
         << "      " << (double)c[0] / n << endl;
    for (int i = 1; i < 9; i++)
    {
        cout << "[" << i * 10 << "; " << i * 10 + 10 << ")"
             << "      " << (double)c[i] / n << endl;
    }
    cout << "[90;100]"
         << "      " << (double)c[9] / n << '\n'
         << endl;
}

int main()
{
    int met = -1;

    while (1)
    {
        met = menu();
        if (met == -1)
        {
            break;
        }
        switch (met)
        {
        case 1:
            getCount();
            method01(0);
            histogram1_5();
            break;
        case 2:
            getCount();
            method02(0);
            histogram1_5();
            break;
        case 3:
            method03(0);
            histogram1_5();
            break;
        case 4:
            method04(0);
            histogram1_5();
            break;
        case 5:
            method05(0);
            histogram1_5();
            break;
        case 6:
            method06(0);
            histogram6_8();
            break;
        case 7:
            method07(0);
            histogram6_8();
            break;
        case 8:
            method08(0);
            histogram6_8();
            break;
        case 9:
            method09(0);
            histogram9_10();
            break;
        case 10:
            method10(0);
            histogram9_10();
            break;
        }
        reset(c);
    }
    return 0;
}
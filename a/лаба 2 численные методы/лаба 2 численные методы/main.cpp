#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


double f1(double x, double y) {
    return y - 1.5 - x * x * x;
}

double f2(double x, double y) {
    return x * x + y * y / 4.0 - 1.0;
}

// F(X)
vector<double> F(double x, double y) {
    return { f1(x, y), f2(x, y) };
}

// W^T(X)
vector<vector<double>> jacobiT(double x, double y) {
    return {
        { -3 * x * x,  2 * x },
        { 1,            y / 2.0 }
    };
}


vector<double> multiply(const vector<vector<double>>& A,
                        const vector<double>& v)
{
    vector<double> result(2, 0.0);

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            result[i] += A[i][j] * v[j];

    return result;
}

double dot(const vector<double>& a,
           const vector<double>& b)
{
    return a[0] * b[0] + a[1] * b[1];
}

double normL1(const vector<double>& v) {
    return fabs(v[0]) + fabs(v[1]);
}



int main() {

    vector<double> X = { 0.2, 1.2 };  
    const double tol = 0.001;
    const int maxIter = 100;

    cout << "Метод скорейшего спуска (вариант В)\n";

    for (int k = 0; k < maxIter; ++k) {

        double x = X[0];
        double y = X[1];

        // F(Xk)
        vector<double> Fk = F(x, y);

        // W^T(Xk)
        vector<vector<double>> Wt = jacobiT(x, y);

        // u = W^T * F
        vector<double> u = multiply(Wt, Fk);

        // W^T * u
        vector<double> Wt_u = multiply(Wt, u);

        // λk (вариант В)
        double numerator   = dot(Fk, Wt_u);
        double denominator = dot(Wt_u, Wt_u);

        if (fabs(denominator) < 1e-15) {
            cout << "Знаменатель близок к нулю. Остановка.\n";
            break;
        }

        double lambda = numerator / denominator;

        vector<double> Xnext = {
            X[0] - lambda * u[0],
            X[1] - lambda * u[1]
        };

        double error = normL1({ Xnext[0] - X[0],
                                Xnext[1] - X[1] })
                       / (normL1(X) + 1e-15);

        cout << "Итерация " << k + 1 << ":\n";
        cout << "  X = (" << X[0] << ", " << X[1] << ")\n";
        cout << "  lambda = " << lambda << "\n";
        cout << "  error = " << error << "\n\n";

        if (error < tol) {
            X = Xnext;
            cout << "Критерий выполнен.\n\n";
            break;
        }

        X = Xnext;
    }

    cout << "Решение:\n";
    cout << "x = " << X[0] << endl;
    cout << "y = " << X[1] << endl;

    cout << "\nПроверка:\n";
    cout << "f1 = " << f1(X[0], X[1]) << endl;
    cout << "f2 = " << f2(X[0], X[1]) << endl;

    return 0;
}

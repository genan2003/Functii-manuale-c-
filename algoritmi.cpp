#include "algoritmi.h"
#include <iostream>
using namespace std;

void Citire(int v[], int n)
{
    for (int i = 1; i <= n; i++)
        cin >> v[i];
}
void Afisare(int v[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
}
void Swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int Suma_n_elem(int v[], int inceput, int sfarsit)
{
    if (inceput == sfarsit)
        return v[inceput];
    else
    {
        int mijloc = (inceput + sfarsit) / 2;
        int sum1 = Suma_n_elem(v, inceput, mijloc);
        int sum2 = Suma_n_elem(v, mijloc + 1, sfarsit);
        return sum1 + sum2;
    }
}
void Bubble_sort(int v[], int n)
{
    int sortat;
    do
    {
        sortat = 1;
        for (int i = 1; i <= n - 1; i++)
            if (v[i] > v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = 0;
            }
    } while (!sortat);
}
int Maxim(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int Minim(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
void Counting_sort(int &n, int v[])
{
    int Min = v[1], Max = v[1], frecventa[100000] = {0}, i, j;
    for (i = 1; i <= n; i++)
    {
        frecventa[v[i]]++;
        Max = Maxim(Max, v[i]);
        Min = Minim(Min, v[i]);
    }
    int k = 1;
    for (i = Min; i <= Max; i++)
        for (j = 1; j <= frecventa[i]; j++)
            v[k++] = i;
    n = k;
}
void Quick_sort(int v[], int stanga, int dreapta)
{
    int i = stanga, j = dreapta, mijloc = (stanga + dreapta) / 2;
    int pivot = v[mijloc];
    while (i <= j)
    {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i <= j)
        {
            Swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (i < dreapta)
        Quick_sort(v, i, dreapta);
    if (j > stanga)
        Quick_sort(v, stanga, j);
}
int Cautare_lineara(int v[], int n, int element)
{
    for (int i = 1; i <= n; i++)
        if (v[i] == element)
            return i;
    return -1;
}
int Cautare_binara(int v[], int n, int element)
{
    int ls = 1, ld = n, ok = 0, mijloc;
    Quick_sort(v, 1, n);
    while (ls <= ld && !ok)
    {
        mijloc = (ls + ld) / 2;
        if (v[mijloc] == element)
            ok = 1;
        else if (element < v[mijloc])
            ld = mijloc - 1;
        else
            ls = mijloc + 1;
    }
    if (ok == 1)
        return mijloc;
    else
        return -1;
}
void Ciur(int n)
{
    bool ok[100000] = {0};
    int i;
    ok[0] = ok[1] = 1;
    for (i = 4; i <= n; i += 2)
        ok[i] = 1;
    for (i = 3; i * i <= n; i += 2)
        if (!ok[i])
            for (int j = i * i; j <= n; j += 2 * i)
                ok[j] = 1;
    for (i = 1; i <= n; i++)
        if (ok[i] == 0)
            cout << i << " ";
}
int Oglindit(int n)
{
    int copie = n;
    int oglindit = 0;
    while (n != 0)
    {
        int cifra = n % 10;
        oglindit = oglindit * 10 + cifra;
        n /= 10;
    }
    return oglindit;
}
int Media_aritmetica(int a, int b)
{
    return (a + b) / 2;
}
int Cifra_maxima(int n)
{
    int cifmax = 0;
    while (n != 0)
    {
        int cif = n % 10;
        if (cif > cifmax)
            cifmax = cif;
        n /= 10;
    }
    return cifmax;
}
int Eliminare_cifrelor_impare(int n)
{
    int nrNou = 0;
    int p = 1;
    while (n != 0)
    {
        int cif = n % 10;
        if (cif % 2 == 0)
        {
            nrNou += cif * p;
            p *= 10;
        }
        n /= 10;
    }
    return nrNou;
}
int Eliminare_cifrelor_pare(int n)
{
    int nrNou = 0;
    int p = 1;
    while (n != 0)
    {
        int cif = n % 10;
        if (cif % 2 != 0)
        {
            nrNou += cif * p;
            p *= 10;
        }
        n /= 10;
    }
    return nrNou;
}
int Nr_cifre(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}
int Prim(int n)
{
    if (n == 1 || n == 0)
        return 0;
    if (n != 2 && n % 2 == 0)
        return 0;
    for (int d = 3; d * d <= n; d += 2)
        if (n % d == 0)
            return 0;
    return 1;
}
int Cmmdc(int a, int b)
{
    while (b != 0)
    {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}
int Cmmmc(int a, int b)
{
    return (a * b) / Cmmdc(a, b);
}
void Permutare_stanga(int v[], int n)
{
    int aux = v[1];
    for (int i = 2; i <= n; i++)
        v[i - 1] = v[i];
    v[n - 1] = aux;
}
void Permutare_dreapta(int v[], int n)
{
    int aux = v[n - 1];
    for (int i = n - 2; i >= 1; i--)
        v[i + 1] = v[i];
    v[1] = aux;
}
void Interclasare(int a[], int b[], int c[], int n, int m) // WIP
{
    Quick_sort(a, 1, n);
    Quick_sort(b, 1, m);
    int i = 1, k = 1, j = 1;
    while ((i <= n) && (j <= m))
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    for (; i <= n; i++)
        c[k++] = a[i];
    for (; j <= m; j++)
        c[k++] = b[i];
}
void Citire_matrice(int a[101][101], int n, int m)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}
void Afisare_matrice(int a[101][101], int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}
void Bordare(int a[101][101], int n, int m) // WIP
{
    for (int j = 1; j <= m + 1; j++)
    {
        a[0][j] = 0;
        a[m + 1][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i][0] = 0;
        a[i][m + 1] = 0;
    }
}
int strlen(char s[])
{
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++)
        len = i;
    return len + 1;
}
void strcat(char s1[], char s2[])
{
    int i = 0;
    for (i = 0; s1[i] != '\0'; i++)
        ;
    for (int j = 0; s2[j] != '\0'; j++, i++)
        s1[i] = s2[j];
    s1[i] = '\0';
}
void strcpy(char s1[], char s2[])
{
    int i = 0;
    for (i = 0; s2[i] != '\0'; i++)
        s1[i] = s2[i];
    s1[i] = '\0';
}
int strcmp(char s1[], char s2[])
{
    int i = 0;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
        ;
    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    else
        return s1[i] - s2[i];
}
char *strchr(char s[], char c)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
            return s + i;
    }
    return NULL;
}
char *strstr(char sir[], char subSir[])
{
    for (unsigned i = 0; sir[i] != NULL; i++)
    {
        if (sir[i] == subSir[0])
        {
            int gasit = 1, k = i + 1;
            for (unsigned j = 1; subSir[j] != NULL; j++)
            {
                if (sir[k] != subSir[j])
                {
                    gasit = 0;
                    break;
                }
                k++;
            }
            if (gasit == 1)
                return sir + i;
        }
    }
    return NULL;
}
void Swap_char(char &a, char &b)
{
    char t = a;
    a = b;
    b = t;
}
char *strrev(char *s)
{
    int i = 0, j;
    int n = strlen(s) - 1;
    for (j = n; i <= n / 2; i++, j--)
        Swap_char(s[i], s[j]);
    return s;
}
char *strtok(char *s, char *sep)
{
    static char *previous = NULL;

    if (s != NULL)
        previous = s;

    if (previous == NULL)
        return NULL;

    char *result = new char[strlen(previous) + 1];
    int i = 0;

    for (; strchr(sep, previous[i]) == NULL; result[i] = previous[i], i++)
        ;

    if (previous[i] == '\0')
    {
        result[i] = '\0';
        previous = NULL;
        return result;
    }

    result[i] = '\0';
    previous = &previous[i + 1];

    return result;
    delete[] result;
}
int pow(int a, int n)
{
    int p = 1;
    while (n != 0)
    {
        int c = n % 2;
        if (c == 1)
        {
            p *= a;
        }
        n /= 2;
        a *= a;
    }
    return p;
}
void Descompunere_in_factori_primi(int n)
{
    int d = 2;
    int p;
    while (n > 1)
    {
        p = 0;
        while (n % d == 0)
        {
            ++p;
            n /= d;
        }
        if (p)
            cout << d << " " << p << '\n';
        ++d;
        if (n > 1 && d * d > n)
        {
            d = n;
        }
    }
}
long double sqrt(long double N, long double LG)
{
    long double NG = (LG + (N / LG)) / 2;
    while ((NG - LG > 0.00001) || (LG - NG > 0.00001))
    {
        LG = NG;
        NG = (LG + (N / LG)) / 2;
    }
    return NG;
}
void phi_de_la_1_la_n(int n)
{
    int phi[n + 1];
    for (int i = 0; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
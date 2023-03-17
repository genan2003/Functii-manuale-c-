#pragma once
#include <iostream>
using namespace std;

//Algoritmi vectori
void Citire(int v[], int n);
void Afisare(int v[], int n);
int Suma_n_elem(int v[], int inceput, int sfarsit); //Divide et tempera
void Bubble_sort(int v[], int n);
void Counting_sort(int &n, int v[]);
void Quick_sort(int v[], int stanga, int dreapta);
int Cautare_lineara(int v[], int n, int element);
int Cautare_binara(int v[], int n, int element);
void Ciur(int n); //numerele prime pana la n
void Permutare_stanga(int v[], int n);
void Permutare_dreapta(int v[], int n);
void Interclasare(int a[], int b[], int c[], int n, int m); //Argumentele functiei sunt: vectorul a, vectorul b, vectorul c, nr de elemente a lui a, nr de elemente a lui b

//Algoritmi elementari pentru prelucrarea unui numar
int Oglindit(int n);
int Media_aritmetica(int a, int b);
int Cifra_maxima(int n);
int Eliminare_cifrelor_impare(int n);
int Eliminare_cifrelor_pare(int n);
int Nr_cifre(int n);
int Prim(int n);
int Cmmdc(int a, int b);
int Cmmmc(int a, int b);
void Descompunere_in_factori_primi(int n);
void Transformare_baza_b(int &n,int b);//de terminat
void Transformare_in_baza_10(int &n,int b);//de terminat
void phi_de_la_1_la_n(int n);

//Algoritmi matrici
void Citire_matrice(int a[101][101], int n, int m);
void Afisare_matrice(int a[101][101], int n, int m);
void Bordare(int a[101][101], int n, int m);

//Algoritmi siruri
int strlen(char s[]);
void strcat(char s1[], char s2[]);
void strcpy(char s1[], char s2[]);
int strcmp(char s1[], char s2[]);
char *strchr(char s[], char c);
char *strstr(char sir[], char subSir[]);
char *strrev(char *s);
char *strtok(char *s, char *sep);

//Functii diverse
void Swap(int &a, int &b);
void Swap_char(char &a, char &b);
int pow(int a,int n);
long double sqrt (long double N, long double LG);
int Max(int a, int b);
int Min(int a, int b);
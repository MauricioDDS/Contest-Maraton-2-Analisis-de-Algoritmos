#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calcularMCD(long a, long b) {
    long resto;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

void solve(long a, long b, long c, long d, char operand){
    long numerador[10] = {0}, denominador[10] = {1};
    numerador[2] = a*c;
    denominador[2]=b*d;
    numerador[3] = b==d? a+c : (a*d)+(b*c);
    denominador[3] = b==d? b : (b*d);
    numerador[5] =  b==d? a-c : (a*d)-(b*c);
    denominador[5] = denominador[3];
    numerador[7] = a*d;
    denominador[7] = b*c;
    long value = (int)operand - 40;
    long mcd = calcularMCD(numerador[value], denominador[value]);
    cout<< numerador[value]/mcd << " " << denominador[value]/mcd<< "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    long a, b, c, d;
    char operand;
    while(cin >> a >> b >> operand >> c >> d){
      solve(a,b,c,d,operand);  
    }
}
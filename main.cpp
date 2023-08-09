#include <cmath>
#include <iostream>
#define QTD_NOTAS_TOTAIS 7

using namespace std;

float troco;
int notas[QTD_NOTAS_TOTAIS] = {2, 5, 10, 20, 50, 100, 200};
int qtdNotas[QTD_NOTAS_TOTAIS];

void imprimeTroco() {
    cout << "\n\nO troco total é: " << troco << endl;
    for(int i = QTD_NOTAS_TOTAIS-1; i >= 0; i--) {
        if(qtdNotas[i] > 0)
        cout << "Quantidades de notas de " << notas[i] << ": " << qtdNotas[i] << endl;
    }
}

void calculaTroco(float compra, float pagamento) {
    float resto;
    resto = troco = pagamento - compra;
    for(int i = QTD_NOTAS_TOTAIS-1; i >= 0; i--) {
        if(resto/notas[i] > 0) {
            qtdNotas[i] = trunc(resto/notas[i]);
            resto -= qtdNotas[i]*notas[i];
        }
    }
}

int main()
{
    float compra, pagamento;
    
    cout << "--- Programa para calcular o troco ---" << endl;
    
    cout << "Insira o valor total da compra: ";
    cin >> compra;
    
    cout << "Insira o valor do pagamento: ";
    cin >> pagamento;
    
    calculaTroco(compra, pagamento);
    imprimeTroco();
    
    return 0;
}
// Expressões
// Pedrinho e Zezinho estão precisando estudar resolução de expressões matemáticas para uma prova que irão fazer. Para isso, eles querem resolver muitos exercícios antes da prova. Como sabem programar, então decidiram fazer um gerador de expressões matemáticas.

// O gerador de expressões que eles criaram funciona em duas fases. Na primeira fase é gerada uma cadeia de caracteres que contém apenas os caracteres '{', '[', '(', '}', ']' e ')'. Na segunda fase, o gerador adiciona os números e operadores na estrutura criada na primeira fase. Uma cadeia de caracteres é dita bem definida (ou válida) se atende as seguintes propriedades:

// Ela é uma cadeia de caracteres vazia (não contém nenhum caractere).
// Ela é formada por uma cadeia bem definida envolvida por parênteses, colchetes ou chaves. Portanto, se a cadeia SS é bem definida, então as cadeias (SS), [SS] e {SS} também são bem definidas.
// Ela é formada pela concatenação de duas cadeias bem definidas. Logo, se as cadeias XX e YY são bem definidas, a cadeia XYXY é bem definida.
// Depois que Pedrinho e Zezinho geraram algumas expressões matemáticas, eles perceberam que havia algum erro na primeira fase do gerador. Algumas cadeias não eram bem definidas. Eles querem começar a resolver as expressões o mais rápido possível, e sabendo que você é um ótimo programador resolveram pedir que escreva um programa que dadas várias cadeias geradas na primeira fase, determine quais delas são bem definidas e quais não são.

// Entrada
// A entrada é composta por diversas instâncias. A primeira linha da entrada contém um inteiro TT indicando o número de instâncias. Em seguida temos TT linhas, cada uma com uma cadeia AA.

// Saída
// Para cada instância imprima uma linha contendo a letra 'S' se a cadeia é bem definida, ou a letra 'N' caso contrário.

// Restrições
// 1 \leq T \leq 201≤T≤20
// a cadeia de caracteres AA tem entre 1 e 100000 caracteres.
// a cadeia de caracteres AA contém apenas caracteres '{', '[', '(', '}', ']' e ')'.
// Exemplos de Entrada	Exemplos de Saída
// 12
// ()
// []
// {}
// (]
// }{
// ([{}])
// {}()[]
// ()]
// {[]
// (
// (([{}{}()[]])(){}){}
// (((((((((({([])}])))))))))
// S
// S
// S
// N
// N
// S
// S
// N
// N
// N
// S
// N

#include <iostream>
#include <stack>

using namespace std;

enum isValid {
    S = 'S',
    N = 'N'
};

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string input;
        cin >> input;

        stack<char> s;

        isValid valid = S;
        for (auto c : input) {
            if (c == '{' || c == '[' || c == '(') { s.push(c); }
            else if (c == '}' || c == ']' || c == ')') {
                if (s.empty()) {
                    valid = N;
                    break;
                }
                char comp = s.top();
                s.pop();
                if (comp == '{' && c != '}' || comp == '[' && c != ']' || comp == '(' && c != ')') {
                    valid = N;
                    break;
                }
            }
        }

        if (!s.empty()) valid = N;

        cout << (char) valid << endl;
    }
}
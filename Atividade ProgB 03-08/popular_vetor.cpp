#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

using namespace std; // Importa todo o namespace std

void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    int opcao = 0;
    vector<int> vetor;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(0, 99);

    do {
        limpar_tela();
        cout << "=== MENU PRINCIPAL ===\n";
        cout << "1 - Popular vetor com numeros aleatorios\n";
        cout << "2 - Listar vetor populado\n";
        cout << "3 - Ordenar vetor\n";
        cout << "4 - Calcular média aritmética\n";
        cout << "5 - Calcular mediana\n";
        cout << "6 - Exibir Maior e Menor valor do vetor\n";
        cout << "7 - Sair\n";
        cout << "Opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = 0;
        }

        switch (opcao) {
            case 1:
                cout << "\nPopulando o vetor com numeros aleatorios...\n";
                vetor.resize(10);
                for (int& val : vetor) {
                    val = distrib(gen);
                }
                cout << "Vetor populado com sucesso!\n";
                break;

            case 2:
                cout << "\nListando o vetor:\n";
                if (!vetor.empty()) {
                    for (int val : vetor) {
                        cout << val << "\t";
                    }
                    cout << "\n";
                } else {
                    cout << "Vetor vazio. Nada a exibir.\n";
                }
                break;

            case 3:
                cout << "\nOrdenando o vetor...\n";
                if (!vetor.empty()) {
                    bool trocou = false;
                    for (size_t i = 0; i < vetor.size() - 1; ++i) {
                        trocou = false;
                        for (size_t j = 0; j < vetor.size() - i - 1; ++j) {
                            if (vetor[j] > vetor[j + 1]) {
                                swap(vetor[j], vetor[j + 1]);
                                trocou = true;
                            }
                        }
                        if (!trocou) break;
                    }
                    cout << "Vetor ordenado com sucesso!\n";
                } else {
                    cout << "Vetor vazio. Nada a ordenar.\n";
                }
                break;

            case 4:
                if (!vetor.empty()) {
                    cout << "\nCalcular Media:\n";
                    int soma = accumulate(vetor.begin(), vetor.end(), 0);
                    float media = static_cast<float>(soma) / vetor.size();
                    cout << "A Media deste vetor e " << media << "\n";
                } else {
                    cout << "\nVetor Vazio, Nada a exibir.\n";
                }
                break;

            case 5:
                if (!vetor.empty()) {
                    bool ordenado = is_sorted(vetor.begin(), vetor.end());

                    if (ordenado) {
                        cout << "\nCalculando Mediana:\n";
                        size_t n = vetor.size();
                        float mediana;
                        
                        if (n % 2 == 0) {
                            mediana = static_cast<float>(vetor[n / 2 - 1] + vetor[n / 2]) / 2.0f;
                        } else {
                            mediana = static_cast<float>(vetor[n / 2]);
                        }
                        
                        cout << "O valor equivalente a mediana deste vetor e " << mediana << "\n";
                    } else {
                        cout << "\nVetor desordenado! Por favor, ordene o vetor primeiro (Opcao 3).\n";
                    }
                } else {
                    cout << "\nVetor Vazio, Nada a exibir.\n";
                }
                break;

            case 6:
                if (!vetor.empty()) {
                    bool ordenado = is_sorted(vetor.begin(), vetor.end());

                    if (ordenado) {
                        cout << "\nEncontrar maior e menor numero do vetor:\n";
                        cout << "O menor valor do vetor e " << vetor.front() << "\n";
                        cout << "O maior valor do vetor e " << vetor.back() << "\n";
                    } else {
                        cout << "\nVetor desordenado! Por favor, ordene o vetor primeiro (Opcao 3).\n";
                    }
                } else {
                    cout << "\nVetor Vazio, Nada a exibir.\n";
                }
                break;

            case 7:
                cout << "\nSistema encerrado.\n";
                break;

            default:
                cout << "\nOpcao invalida. Redigite.\n";
                break;
        }

        if (opcao != 7) {
            pausar();
        }

    } while (opcao != 7);

    return 0;
}
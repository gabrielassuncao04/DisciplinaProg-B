#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

#include "meusTipos.h"

int main()
{
    vector<Veiculo> garagem;
    int opcao;
    string placa, cor, horaEntrada;

    do
    {
        cout << "\nMenu de opcoes:\n";
        cout << "1 - Adicionar veiculo\n";
        cout << "2 - Listar veiculos\n";
        cout << "3 - Ver Veiculo (Saida)\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada

        switch (opcao)
        {
        case 1:
            cout << "Digite a placa do veiculo: ";
            getline(cin, placa);
            cout << "Digite a cor do veiculo: ";
            getline(cin, cor);
            cout << "Digite a hora de entrada do veiculo: [hh:mm] ";
            getline(cin, horaEntrada);

            garagem.push_back({placa, cor, horaEntrada});
            break;

        case 2:
            cout << "\nVeiculos na garagem:\n";
            if (garagem.empty()) {
                cout << "(Nenhum veiculo na garagem)\n";
            }
            for (int i = 0; i < garagem.size(); i++)
            {
                cout << "Placa: " << garagem[i].placa << ", Cor: " << garagem[i].cor << ", Hora de Entrada: " << garagem[i].horaEntrada << endl;
            }
            break;

        case 3:
        {
            string verPlaca;
            string saida_Vei;
            int tempo = 0;

            cout << "Digite a Placa: ";
            // REMOVIDO o cin.ignore daqui para não engolir a primeira letra da placa
            getline(cin, verPlaca);

            bool encontrado = false;

            for (int i = 0; i < garagem.size(); i++)
            {
                if (garagem[i].placa == verPlaca)
                {
                    encontrado = true;
                    cout << "Digite o horario de Saida de seu Veiculo (HH:MM): ";
                    getline(cin, saida_Vei);

                    int HEntrada = stoi(garagem[i].horaEntrada.substr(0, 2));
                    int MEntrada = stoi(garagem[i].horaEntrada.substr(3, 2));
                    int TotalMinEntrada = (HEntrada * 60) + MEntrada;

                    int HSaida = stoi(saida_Vei.substr(0, 2));
                    int MSaida = stoi(saida_Vei.substr(3, 2));
                    int TotalMinSaida = (HSaida * 60) + MSaida;

                    tempo = TotalMinSaida - TotalMinEntrada;

                    cout << "Horario de saida registrado com sucesso! O tempo de garagem do seu veiculo e " << tempo << " minutos.\n";

                    garagem.erase(garagem.begin() + i); // Apaga o elemento daquela posição
                    break;
                }
            }

            if (encontrado == false)
            {
                cout << "Veiculo nao encontrado na garagem!\n";
            }
            break; 
        } 

        case 0:
            cout << "Saindo do programa.\n";
            break;

        default:
            cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 1; 
}
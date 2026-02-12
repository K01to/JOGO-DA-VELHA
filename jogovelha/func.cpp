#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include "func.h"

// 1. Inicializa o tabuleiro com espaços vazios
void ArrumaJogo(std::vector<std::vector<char>>& matriz) {
    matriz.assign(3, std::vector<char>(3, ' '));
}

// 2. Exibe o tabuleiro formatado
void mostratabuleiro(std::vector<std::vector<char>> matriz) {
    std::cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << " " << matriz[i][j] << " ";
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << std::endl; 

        if (i < 2) {
            std::cout << "-----------" << std::endl;
        }
    }
    std::cout << "\n";
}

// 3. Captura a escolha da posição (1 a 9)
int escolha(char x) {
    int jogada;
    std::cout << "Jogador [" << x << "], escolha uma posicao (1-9): ";
    std::cin >> jogada;
    return jogada;
}

// 4. Verifica se houve ganhador
bool Ganha(std::vector<std::vector<char>> matriz) {
    int cx, co;

    // Verificação de Linhas
    for (int i = 0; i < 3; i++) {
        cx = 0; co = 0;
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == 'X') cx++;
            if (matriz[i][j] == 'O') co++;
        }
        if (cx == 3) { std::cout << "Ganhador e X!\n"; return true; }
        if (co == 3) { std::cout << "Ganhador e O!\n"; return true; }
    }

    // Verificação de Colunas
    for (int i = 0; i < 3; i++) {
        cx = 0; co = 0;
        for (int j = 0; j < 3; j++) {
            if (matriz[j][i] == 'X') cx++; 
            if (matriz[j][i] == 'O') co++;
        }
        if (cx == 3) { std::cout << "Ganhador e X!\n"; return true; }
        if (co == 3) { std::cout << "Ganhador e O!\n"; return true ; }
    }

    // Diagonal Primária
    if (matriz[0][0] != ' ' && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
        std::cout << "Ganhador e " << matriz[0][0] << "!\n";
        return true;
    }

    // Diagonal Secundária
    if (matriz[0][2] != ' ' && matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
        std::cout << "Ganhador e " << matriz[0][2] << "!\n";
        return true;
    }
    return false;
}

bool VerificaEmpate(std::vector<std::vector<char>> matriz){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == ' ') {
                return false; 
            }
        }
    }
   
    std::cout << "DEU VELHA! O tabuleiro esta cheio.\n";
    return true;
}

void play(std::vector<std::vector<char>>& matriz, char op) {
    int jogada;
    int linha, coluna;
    bool jogadaValida = false;

    while (!jogadaValida) {
        // 1. Obtém a escolha do jogador (1 a 9)
        jogada = escolha(op);

        // 2. Converte o número 1-9 
    
        linha = (jogada - 1) / 3;
        coluna = (jogada - 1) % 3;

        // 3. Validação: 
        if (jogada >= 1 && jogada <= 9 && matriz[linha][coluna] == ' ') {
            matriz[linha][coluna] = op;
            jogadaValida = true;
        } else {
            std::cout << "! Essa posicao e invalida ou ja esta ocupada. Tente de novo.\n";
        }
    }
}

void bot(std::vector<std::vector<char>>& matriz , char op) {

    char bot_op = (op == 'X') ? 'O' : 'X';


    int linha,coluna;

    while (true) {
        linha = rand() % 3;
        coluna = rand() % 3;

        if (matriz[linha][coluna] == ' ') {
            matriz[linha][coluna] = bot_op;
            break;
        }
    }
       
    



}
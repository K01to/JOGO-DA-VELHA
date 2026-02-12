#include <iostream>
#include <vector>
#include <ctime>
#include "func.h"


int main(){
    std::srand(time(0));
    char op;
    
    std::vector<std::vector<char>> matriz(3,std::vector<char>(3));


    std::cout << "*********************************\n";
    std::cout << "        JOGO DA VELHA\n\n";


    std::cout << "Escolha X ou O :";
    std::cin >> op;
    op = toupper(op);
    ArrumaJogo(matriz);
    mostratabuleiro(matriz);


    bool jogo = false;
    do {
        std::cout << "Sua vez!\n";
        play(matriz, op);
        mostratabuleiro(matriz);
        jogo = VerificaEmpate(matriz);
        jogo = Ganha(matriz);
        if(jogo) break;


        std::cout << "Vez do Bot!\n";
        bot(matriz, op);
        mostratabuleiro(matriz);
       jogo = Ganha(matriz);
       if(jogo) break;
        
        

    } while(!jogo);


    std::cout << "\n\nObrigado por jogar!\n";



    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// 1: pesquisar sobre a biblioteca time.h
// 2:como gerar um numero aleatorio atraves da stdlib.h
// 3: aprender a como passar uma função como parâmetro para outra função
int verifica_player(char player_choose[8]){
  
    if(strcmp(player_choose, "pedra") == 0){
        return 0;
    }
    else if(strcmp(player_choose, "papel") == 0){
        return 1;
    } else if(strcmp(player_choose, "tesoura") == 0){
        return 2;
    } else{
      printf("Digiite uma opção válida\n");
      return -1;
    }
}
void verifica_vencedor(int jogada_bot, int (*verifica_player)(char[])) {
    char jogada_player[8];
    printf("Digite sua jogada (pedra/papel/tesoura): ");
    scanf("%s", jogada_player);

    int jogada_player_val = verifica_player(jogada_player);

    if (jogada_player_val == -1) {
        return;
    }

    // Mostra as jogadas
    const char *jogadas[] = {"pedra", "papel", "tesoura"};
    printf("Jogada do bot: %s\n", jogadas[jogada_bot]);
    printf("Sua jogada: %s\n", jogadas[jogada_player_val]);

    // Verifica o vencedor
    if (jogada_bot == jogada_player_val) {
        printf("Empate!\n");
    } else if ((jogada_bot == 0 && jogada_player_val == 2) || 
               (jogada_bot == 1 && jogada_player_val == 0) || 
               (jogada_bot == 2 && jogada_player_val == 1)) {
        printf("Bot venceu!\n");
    } else {
        printf("Você venceu!\n");
    }
}
int main(void) {
  printf("Bem vindo ao jogo: Pedra, papel e tesoura.\n");
  while(1){
  srand(time(NULL));
  int jogada_bot = rand() % 3;

  verifica_vencedor(jogada_bot, verifica_player);
  }
  return 0;
}

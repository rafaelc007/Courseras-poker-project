#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

deck_t init_deck(){
  //initialize a default deck for test purposes
  card_t cardi[5];
  for(int i=0;i<5;i++){
    cardi[i] = card_from_num(i+12);
  }
  
  card_t * cards[] = {cardi, cardi+1, cardi+2, cardi+3, cardi+4};

  deck_t deck = {.cards = cards, .n_cards = 5};
  return deck;
}

int main(){
  deck_t hand = init_deck();
  
  float res1 = (float)rand()/RAND_MAX;
  float res2 = (float)rand()/RAND_MAX;
  printf("result 1: %.4f\n",res1);
  printf("result 2: %.4f", res2);
  printf("\n");
  
  return EXIT_SUCCESS;
}

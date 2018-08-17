#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

deck_t * init_deck(int start) {
  assert(start < 50);
  //initialize a default deck for test purposes
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = malloc(5*sizeof(*deck->cards));
  deck->n_cards = 5;
  
  for(int i=0;i<5;i++){
    deck->cards[i] = malloc(sizeof(*deck->cards[i]));
    card_t card = card_from_num(i+start);
    *(deck->cards[i]) = card;
  }

  return deck;
}

void release_deck(deck_t * deck) {
   for(int i=0;i<5;i++){
     free(deck->cards[i]);
   }
  free(deck->cards);
  free(deck);
}

int main(int argc, char ** argv){
  int start;
  if(argc == 1){
    start = 11;
  }
  else if (argc == 2){
    start = atoi(argv[1]);
  }
  else {
    printf("Usage: test-deck card_shift");
    return EXIT_FAILURE;
  }
  deck_t * hand = init_deck(start);
  
  print_hand(hand);
  printf("\n");

  release_deck(hand);
  
  return EXIT_SUCCESS;
}

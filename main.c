#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "eval.h"

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

void print_rank(hand_eval_t h_eval, int index) {
  const char * rank = ranking_to_string(h_eval.ranking);
  printf("ranking in hand %d is : %s.\n", index, rank);
}

int main(int argc, char ** argv){
  
  deck_t * hand1 = init_deck(7);
  deck_t * hand2 = init_deck(14);

  // shuffle cards
  shuffle(hand1);
  shuffle(hand2);

  // print cards
  printf("cards in hand 1: ");
  print_hand(hand1);
  printf("\n");
  printf("cards in hand 2: ");
  print_hand(hand2);
  printf("\n");

  hand_eval_t h1_eval = evaluate_hand(hand1);
  hand_eval_t h2_eval = evaluate_hand(hand2);

  print_rank(h1_eval,1);
  print_rank(h1_eval,2);  
  

  release_deck(hand);
  
  return EXIT_SUCCESS;
}

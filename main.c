#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** this will be an implementation of the random sort funcion **/
#define N 500

int rand_lim(int limit);
void fill_array(int random_array[N]);
void print_array(int random_array[N]);
void RandomSelect(int set_S[N], int k, int size_S);

int main(void){
  srand(time(NULL)); //Initiate random number generator
  int random_array[N]; //Array of length N for random numbers
  fill_array(random_array);
  print_array(random_array);
  int k = rand_lim(N - 2) + 1;
  printf("%d smallest integer...\n", k);
  RandomSelect(random_array, k, N);
  
  return 0;
}

int rand_lim(int limit) {
/* return a random number between 0 and limit inclusive.
 */

    int divisor = RAND_MAX/(limit+1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}


void fill_array(int random_array[N]){
  /** Fills the random_array with integers 
      from 1 to N, uniformly **/
  for(int i = 0; i < N; i++){
    random_array[i] = 0;
  }
  
  int random_int = 0;
  int new_int_flag = 0;
  for(int index = 0; index < N; index++){
    random_int = 0;
    new_int_flag = 0;
    while(!random_int || !new_int_flag){
      new_int_flag = 1;
      random_int = rand_lim(N);
      for(int i = 0; i < index; i++){
	if(random_array[i] == random_int){
	  new_int_flag = 0;
	}
      }
      random_array[index] = random_int;
    }
  }
}

void print_array(int random_array[N]){
  for(int i = 0; i < N; i++){
    printf("%d ", random_array[i]);
  }
  printf("\n");
}

void RandomSelect(int set_S[N], int k, int size_S){
  //Select a random element from S
  int random_index = rand_lim(size_S - 1);
  int p = set_S[random_index];
  printf("Index: %d  p: %d  Size: %d\n", random_index, p, size_S);
  int S_1[N] = {0};
  int S_2[N] = {0};
  int index_S_1 = 0;
  int index_S_2 = 0;
  for(int i = 0; i < N; i++){
    if(i != random_index){
      if((set_S[i] < p) && set_S[i]){
	S_1[index_S_1] = set_S[i];
	index_S_1++;
      }
      if((set_S[i] > p) && set_S[i]){
	S_2[index_S_2] = set_S[i];
	index_S_2++;
      }
    }
  }

  if(index_S_1 == (k - 1)){
    printf("... is %d\n", p);
  } else if(index_S_1 > (k - 1)){
    RandomSelect(S_1, k, index_S_1);
  } else if(index_S_1 < (k - 1)){
    RandomSelect(S_2, k - index_S_1 - 1, index_S_2);
  }
}

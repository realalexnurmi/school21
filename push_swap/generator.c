#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
 
int main(int argc, char** argv) 
{
  srand(time(NULL));
  size_t i, max;
  i = max = atoi(argv[1]);
  size_t j, count_gen;
  count_gen = 0;
  int new_number;
  int array[i];
  while (i--)
  {
      while (1)
      {
          new_number = rand()%(2 * max) - max;
          j = 0;
          if (count_gen)
          {
            while (j < count_gen )
            {
                if (array[j] == new_number)
                    break;
                j++;
            }
            if (j != count_gen)
                continue;
          }
          array[count_gen] = new_number;
          break;
      }
      printf("%d ", array[count_gen]);
      count_gen++;
  }
  return (0);
}
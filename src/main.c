#include <stdio.h>
#include "tools/dictionary.h"
#include "tools/frequencyMap.h"


int main() {
  int count[STR_LENGTH] = {0};
  int result = createFrequencyMap("./data/hosts.txt", count);
  if (result != 0) {
    printf("Cannot read file");
  }
  for (int i = 0; i < STR_LENGTH; i++) {
    printf("%c: %d\n", STR[i], count[i]);
  }
  return 0;
}

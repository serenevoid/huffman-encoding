#include <stdio.h>
#include "frequencyMap.h"

int createFrequencyMap(char hostFileName[], int count[]) {
  FILE* hostsFile = fopen(hostFileName, "r");
  if (hostsFile != NULL) {
    char domainString[256];
    while (fgets(domainString, sizeof(domainString), hostsFile)) {
      for (int i = 0; i < sizeof(domainString); i++) {
        if (domainString[i] == '\0') {
          break;
        }
        unsigned int index = _getIndex(domainString[i]);
        if (index == 0) {
          printf("Cannot identify character: %c", domainString[i]);
          return 1;
        }
        count[index - 1] += 1;
      }
    }
    return 0;
  }
  return 1;
}

unsigned int _getIndex(char x) {
  unsigned int index = 0;
  switch (x) {
    case '-':
      index = 37;
      break;
    case '.':
      index = 38;
      break;
    case '_':
      index = 39;
      break;
    case '\n':
      index = 40;
      break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      index = (int)x - (int)'0' + 27;
      break;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      index = (int)x - (int)'a' + 1;
      break;
  }
  return index;
}

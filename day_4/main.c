#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Returns true if the range [a1, b1] fully contains the range [a2, b2].
bool fully_contains(int a1, int b1, int a2, int b2) {
  return a2 >= a1 && b2 <= b1;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  // Open the input file for reading.
  char* filename = argv[1];
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Count the number of pairs where one range fully contains the other.
  int count = 0;
  while (!feof(file)) {
    // Read the two section ranges for this pair.
    int a1, b1, a2, b2;
    if (fscanf(file, "%d-%d,%d-%d\n", &a1, &b1, &a2, &b2) != 4) {
      if (feof(file)) {
        // End of file reached, exit the loop.
        break;
      } else {
        printf("Error reading ranges from file\n");
        exit(1);
      }
    }

    // Check if one of the ranges fully contains the other.
    if (fully_contains(a1, b1, a2, b2) || fully_contains(a2, b2, a1, b1)) {
      count++;
    }
  }

  // Print the result.
  printf("%d\n", count);

  return 0;
}

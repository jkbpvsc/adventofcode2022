#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Returns true if the range [a1, b1] overlaps with the range [a2, b2].
bool overlaps(int a1, int b1, int a2, int b2) {
  return (a1 <= b2 && b1 >= a2);
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

  // Count the number of pairs where the ranges overlap.
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

    // Check if the ranges overlap.
    if (overlaps(a1, b1, a2, b2)) {
      count++;
    }
  }

  // Print the result.
  printf("%d\n", count);

  return 0;
}

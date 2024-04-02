#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int cards[n];
  for (int i = 0; i < n; i++) {
    char c;
    scanf(" %c", &c);
    if (c >= '0' && c <= '9') {
      cards[i] = c - '0';
    } else {
      cards[i] = 10 + (c - 'J');
    }
  }

  int swaps = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (cards[i] > cards[j]) {
        swaps++;

        
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
      }
    }
  }

  printf("%d\n", swaps);

  return 0;
}
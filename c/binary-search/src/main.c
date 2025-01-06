#include "dbg.h"
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#define MAX_DATA 100

int binary_search(int haystack[], size_t haystack_size, int needle) {
  int low = 0;
  int high = haystack_size - 1;
  for (; low <= high;) {
    int middle = (high - low) / 2 + low;
    debug("%d %d %d", low, middle, high);
    if (needle > haystack[middle]) {
      low = middle + 1;
    } else if (needle < haystack[middle]) {
      high = middle - 1;
    } else {
      debug("returning %d", middle);
      return middle;
    }
  }
  debug("returning %d", -1);
  return -1;
}

int main(int argc, char *argv[]) {
  int haystack[] = {1,  5,  6,  9,   10,  11,  13,  14,  19,  33,
                    54, 92, 80, 101, 102, 103, 105, 607, 902, 1014};
  size_t haystack_size = sizeof(haystack) / sizeof(int);
  debug("sizeof haystack: %lu", haystack_size);
  assert(binary_search(haystack, haystack_size, 1) == 0);
  assert(binary_search(haystack, haystack_size, 5) == 1);
  assert(binary_search(haystack, haystack_size, 6) == 2);
  assert(binary_search(haystack, haystack_size, 9) == 3);
  assert(binary_search(haystack, haystack_size, 10) == 4);
  assert(binary_search(haystack, haystack_size, 11) == 5);
  assert(binary_search(haystack, haystack_size, 13) == 6);
  assert(binary_search(haystack, haystack_size, 7) == -1);
  assert(binary_search(haystack, haystack_size, 102) == 14);
  assert(binary_search(haystack, haystack_size, 607) == 17);
  assert(binary_search(haystack, haystack_size, 1014) == 19);
  binary_search(haystack, haystack_size, 1);
}

#include "dbg.h"
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#define MAX_DATA 100

void assert_numbers_array(int numbers_array[], size_t numbers_array_size,
                          int expected_array[]) {
  for (int i = 0; i < numbers_array_size; ++i) {
    assert(numbers_array[i] == expected_array[i]);
  }
}

void print_numbers_array(int numbers_array[], size_t numbers_array_size) {
  for (int i = 0; i < numbers_array_size; ++i) {
    printf("%d ", numbers_array[i]);
  }
  printf("\n");
}

int find_smallest_number_index(int numbers_array[], size_t numbers_array_size,
                               int start_index) {
  int smallest_number_index = start_index;
  int smallest_number = numbers_array[smallest_number_index];
  for (int i = start_index; i < numbers_array_size; ++i) {
    int current_number = numbers_array[i];
    if (current_number < smallest_number) {
      smallest_number = current_number;
      smallest_number_index = i;
    }
  }
  return smallest_number_index;
}

int selection_sort(int numbers_array[], size_t numbers_array_size) {
  for (int i = 0; i < numbers_array_size; ++i) {
    int smallest_number_index =
        find_smallest_number_index(numbers_array, numbers_array_size, i);
    int temporary_number = numbers_array[i];
    numbers_array[i] = numbers_array[smallest_number_index];
    numbers_array[smallest_number_index] = temporary_number;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int numbers_array[] = {8, 103, 42, 1, 50, 17, 23, 1009, 321};
  size_t numbers_array_size = sizeof(numbers_array) / sizeof(int);
  debug("sizeof numbers array: %lu", numbers_array_size);
  print_numbers_array(numbers_array, numbers_array_size);
  selection_sort(numbers_array, numbers_array_size);
  print_numbers_array(numbers_array, numbers_array_size);
  int expected_numbers_array[] = {1, 8, 17, 23, 42, 50, 103, 321, 1009};
  assert_numbers_array(numbers_array, numbers_array_size, expected_numbers_array);
}

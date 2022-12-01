#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>

void fill_array_random(int arr[], int n, int a, int b);
void selection_sort(int arr[], int n);
void quick_sort(int arr[], int lo, int hi);
int partition(int arr[], int lo, int hi);
int *swap(int arr[], int what, int with);

int main() {
  long long int help[] = {10,         100,          1000,
                          1000000, // dead point
                          1000000000, 1000000000000};

  for (int i = 0; i != 5; ++i) {

    auto n = help[i];

    int arr1[n], arr2[n];

    fill_array_random(arr1, n, 0, 10000);
    memcpy(arr2, arr1, n * sizeof(int));

    auto t1 = std::chrono::high_resolution_clock::now();
    selection_sort(arr1, n);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ss_ms = t2 - t1;

    t1 = std::chrono::high_resolution_clock::now();
    quick_sort(arr2, 0, n - 1);
    t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> qs_ms = t2 - t1;

    std::printf("%.0e: %.5f (ss), %.5f (qs)\n", static_cast<double>(n),
                ss_ms.count(), qs_ms.count());
  }
  return 0;
}

void fill_array_random(int arr[], int n, int a, int b) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(a, b);

  for (int i = 0; i < n; ++i) {
    arr[i] = dist(rng);
  }
}

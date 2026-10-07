#include "arraylib.h"

#include <algorithm>
#include <vector>
int arr_sum(const int* arr, std::size_t n) {
    int result = 0;
    for (std::size_t i = 0; i < n; ++i) {
        result += arr[i];
    }
    return result;
}

int arr_max(const int* arr, std::size_t n) {
    int result = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] > result) {
            result = arr[i];
        }
    }
    return result;
}

int arr_min(const int* arr, std::size_t n) {
    int result = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] < result) {
            result = arr[i];
        }
    }
    return result;
}

double arr_average(const int* arr, std::size_t n) {
    double result = 0.0;
    for (std::size_t i = 0; i < n; ++i) {
        result += arr[i];
    }
    return result / static_cast<double>(n);
}

int arr_count_positive(const int* arr, std::size_t n) {
    int count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            ++count;
        }
    }
    return count;
}

int arr_count_negative(const int* arr, std::size_t n) {
    int count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            ++count;
        }
    }
    return count;
}

int arr_count_zero(const int* arr, std::size_t n) {
    int count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            ++count;
        }
    }
    return count;
}

int arr_product(const int* arr, std::size_t n) {
    int result = 1;
    for (std::size_t i = 0; i < n; ++i) {
        result *= arr[i];
    }
    return result;
}

double arr_median(const int* arr, std::size_t n) {
    std::vector<int> copy(arr, arr + n);
    std::sort(copy.begin(), copy.end());

    if (n % 2 != 0) {
        return static_cast<double>(copy[n / 2]);
    }

    return (static_cast<double>(copy[n / 2 - 1])
          + static_cast<double>(copy[n / 2])) / 2.0;
}

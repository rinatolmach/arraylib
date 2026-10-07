#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>

static bool close(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

int main() {
    int data[] = {7, 3, 9, 1, 5, 8, 2, 6, 4};
    const std::size_t n = sizeof(data) / sizeof(data[0]);

    assert(arr_sum(data, n) == 45);
    assert(arr_max(data, n) == 9);

    double average = arr_average(data, n);

    assert(average >= static_cast<double>(arr_min(data, n)));
    assert(average <= static_cast<double>(arr_max(data, n)));

    assert(close(
        average * static_cast<double>(n),
        static_cast<double>(arr_sum(data, n))
    ));

    assert(
        arr_count_positive(data, n)
        + arr_count_negative(data, n)
        + arr_count_zero(data, n)
        == static_cast<int>(n)
    );

    int sorted[] = {1, 2, 3, 4, 5, 6, 7};
    assert(close(arr_median(sorted, 7), 4.0));

    std::cout << "[integration] All tests passed\n";
    return 0;
}
#include "cpp_starter/adev.hpp"

#include <cmath>
#include <vector>

namespace cpp_starter {

double allan_deviation(std::span<const double> y, std::size_t m) {
    if (m == 0 || y.size() < 2 * m) {
        return std::nan("");
    }

    std::vector<double> y_avg;
    y_avg.reserve(y.size() / m);
    for (std::size_t i = 0; i + m <= y.size(); i += m) {
        double sum = 0.0;
        for (std::size_t j = 0; j < m; ++j) {
            sum += y[i + j];
        }
        y_avg.push_back(sum / static_cast<double>(m));
    }

    if (y_avg.size() < 2) {
        return std::nan("");
    }

    double sum_sq_diff = 0.0;
    for (std::size_t i = 0; i + 1 < y_avg.size(); ++i) {
        const double diff = y_avg[i + 1] - y_avg[i];
        sum_sq_diff += diff * diff;
    }

    return std::sqrt(sum_sq_diff / (2.0 * static_cast<double>(y_avg.size() - 1)));
}

}  // namespace cpp_starter
int foo() {
    return 0;
}

#pragma once

#include <cstddef>
#include <span>

namespace cpp_starter {

/// Non-overlapping Allan deviation for fractional frequency data.
///
/// @param y  Fractional frequency samples y_i taken at uniform spacing tau0.
/// @param m  Averaging factor. ADEV is computed at tau = m * tau0.
/// @return   Allan deviation at the given tau, or NaN if input is invalid.
[[nodiscard]] double allan_deviation(std::span<const double> y, std::size_t m);

}  // namespace cpp_starter

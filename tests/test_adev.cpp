#include "cpp_starter/adev.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <random>
#include <vector>

TEST(AllanDeviation, ZeroForConstantInput) {
    const std::vector<double> y(100, 1.0);
    EXPECT_NEAR(cpp_starter::allan_deviation(y, 1), 0.0, 1e-12);
}

TEST(AllanDeviation, ReturnsNaNForEmptyInput) {
    const std::vector<double> y;
    EXPECT_TRUE(std::isnan(cpp_starter::allan_deviation(y, 1)));
}

TEST(AllanDeviation, ReturnsNaNForZeroAveragingFactor) {
    const std::vector<double> y(100, 1.0);
    EXPECT_TRUE(std::isnan(cpp_starter::allan_deviation(y, 0)));
}

TEST(AllanDeviation, WhiteFMNoiseFollowsTauMinusHalfSlope) {
    std::mt19937_64 rng(42);
    std::normal_distribution<double> dist(0.0, 1.0);

    std::vector<double> y(20000);
    for (auto& v : y) {
        v = dist(rng);
    }

    const double adev1 = cpp_starter::allan_deviation(y, 1);
    const double adev4 = cpp_starter::allan_deviation(y, 4);
    EXPECT_NEAR(adev1 / adev4, 2.0, 0.15);
}

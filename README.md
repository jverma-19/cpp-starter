
# cpp-starter

[![CI](https://github.com/jverma-19/cpp-starter/actions/workflows/ci.yml/badge.svg)](https://github.com/YOUR_USERNAME/cpp-starter/actions/workflows/ci.yml)

Minimal C++20 project template with CMake, GoogleTest, clang-format, clang-tidy, and GitHub Actions CI.

## Build & Test

```bash

cmake -B build

cmake --build build --parallel

ctest --test-dir build --output-on-failure

```

## Format

```bash

find include src tests -name '*.hpp' -o -name '*.cpp' | xargs clang-format -i

```


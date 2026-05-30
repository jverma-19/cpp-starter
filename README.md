# cpp-starter

Minimal C++20 project template with CMake, GoogleTest, clang-format, clang-tidy, and GitHub Actions CI.

## Build & Test

```bash
cmake -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Format & Lint

```bash
# Format all sources in place
find include src tests -name '*.hpp' -o -name '*.cpp' | xargs clang-format -i

# Lint
find include src tests -name '*.cpp' \
  | xargs clang-tidy -p build --header-filter='^(include|src|tests)/.*'
```

build:
    cmake --build build

fmt:
    find . -not -path './build/*' \( -name '*.c' -o -name '*.h' \) | xargs clang-format -i

check:
    find . -not -path './build/*' \( -name '*.c' -o -name '*.h' \) | xargs clang-format --dry-run --Werror

config:
    cmake -S . -B build -G Ninja

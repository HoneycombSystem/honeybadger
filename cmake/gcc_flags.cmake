set(GCC_FLAGS
    -Werror
    -Wall
    -Wduplicated-cond
    -Wformat=2
    -Weffc++
    -Wdouble-promotion
    -Wuseless-cast
    -Wnull-dereference
    -Wlogical-op
    -Wduplicated-branches
    -Wmisleading-indentation
    -Wsign-conversion
    -Wpedantic
    -Wconversion
    -Woverloaded-virtual
    -Wunused
    -Wextra
    -Wshadow
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wcast-align
    -Wundef
    -Wpointer-arith
    -Wstrict-overflow=2
    -Wswitch-default
    -Wunreachable-code)

set(GCC_FLAGS_DEBUG ${GCC_FLAGS} -g3 -O0)
set(GCC_FLAGS_RELEASE ${GCC_FLAGS} -DNDEBUG -O3)

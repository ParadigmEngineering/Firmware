px4_add_module(
    MODULE examples__inject_test
    MAIN inject_test
    STACK_MAIN 2000
    SRCS
        inject_test.cpp
    DEPENDS
)

set(NAME unit_tests)

add_executable(${NAME})

target_link_libraries(${NAME}
PUBLIC
    gtest 
    gtest_main

    dummy
    units
    
    Eigen3::Eigen
)

target_include_directories(${NAME}
PRIVATE 
    ${Boost_INCLUDE_DIRS}
    include/
)

target_sources(${NAME}
PRIVATE
    src/dummy_test.cpp
    src/eigen_boost_units_test.cpp
)

add_custom_target(${NAME}.run
    COMMAND ${CMAKE_CTEST_COMMAND}
    DEPENDS ${NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    USES_TERMINAL
)

gtest_discover_tests(${NAME})
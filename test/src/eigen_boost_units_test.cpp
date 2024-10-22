#include <iostream>
#include <Eigen/Dense>
#include <boost/units/io.hpp>
#include <boost/units/systems/si/force.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>
#include <gtest/gtest.h>

namespace

{
    using namespace boost::units;
    using namespace boost::units::si;

    // Test case to check matrix multiplication with Boost units
    TEST(EigenBoostUnitsTest, MatrixMultiplication)
    {
        // Define two 2x2 matrices of quantities with length (meters)
        Eigen::Matrix<quantity<length>, 2, 2> matA;
        Eigen::Matrix<quantity<length>, 2, 2> matB;

        matA << 2.0 * meters, 3.0 * meters, 4.0 * meters, 5.0 * meters;

        matB << 1.0 * meters, 2.0 * meters, 3.0 * meters, 4.0 * meters;

        // Perform matrix multiplication
        auto result = matA * matB;

        // Check that each element in the result matrix has the expected value in meters^2
        EXPECT_NEAR(result(0, 0).value(), 11.0, 1e-9);
        EXPECT_NEAR(result(0, 1).value(), 16.0, 1e-9);
        EXPECT_NEAR(result(1, 0).value(), 19.0, 1e-9);
        EXPECT_NEAR(result(1, 1).value(), 28.0, 1e-9);
    }
}
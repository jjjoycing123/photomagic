#include "LFSR.hpp"
#include <iostream>
#include <string>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/included/unit_test.hpp>
/* Note: originally, the line above was: "#include <boost/test/unit_test.hpp>" */
using boost::test_tools::output_test_stream;


BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);

}

//Testing Edge cases where the vector as at zero or 1.
BOOST_AUTO_TEST_CASE(Low_Edge_Test){

  //If LFSR is initialized to 1
  LFSR l1("0", 1);
  BOOST_REQUIRE(l1.step() == 0);
  BOOST_REQUIRE(l1.generate(7) == 0);


  LFSR l2("1", 1);
  BOOST_REQUIRE(l2.step() == 0);
  BOOST_REQUIRE(l2.generate(7) == 0);

  //If LFSR is initialized to 1
  LFSR l3("", 1);
  BOOST_REQUIRE(l3.step() == -1);
  BOOST_REQUIRE(l3.generate(7) == -1);

  output_test_stream output;
  output <<  l3;
  BOOST_REQUIRE(output.is_equal("Empty"));
}

BOOST_AUTO_TEST_CASE(High_Edge_Test){

  output_test_stream output;
  //LFSR with 32 bits--the max.
  LFSR l1("00000000000000000000000000000010", 1);
  BOOST_REQUIRE(l1.get_size_of_resgister() == 32);
  BOOST_REQUIRE(l1.step() == 1);
  output << l1;
  BOOST_REQUIRE(output.is_equal("00000000000000000000000000000101"));
  BOOST_REQUIRE(l1.generate(5) == 10);

  //LFSR greater than 32 bits
  LFSR l2("000000000000000000000000000000101",1);
  BOOST_REQUIRE(l2.get_size_of_resgister() == 33);
  output << l2;
  BOOST_REQUIRE(output.is_equal("Register too large"));
  BOOST_REQUIRE(l2.step() == -1);
  BOOST_REQUIRE(l2.generate(7) == -1);

}

BOOST_AUTO_TEST_CASE(Tap_Test){
  output_test_stream output;
  LFSR l1("01101000010", 20);
  BOOST_REQUIRE(l1.step() == -1);
  BOOST_REQUIRE(l1.generate(7) == -1);
  output << l1;
  BOOST_REQUIRE(output.is_equal("Tap is out of range"));

}

//Check to make sure that LFSR produces the same out as the PDF
BOOST_AUTO_TEST_CASE(PS1A_pdfOutputChek){
  LFSR l("01101000010", 8);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("01101000010", 8);
  BOOST_REQUIRE(l2.generate(5) == 25);
  BOOST_REQUIRE(l2.generate(5) == 4);
  BOOST_REQUIRE(l2.generate(5) == 30);
  BOOST_REQUIRE(l2.generate(5) == 27);
  BOOST_REQUIRE(l2.generate(5) == 18);
  BOOST_REQUIRE(l2.generate(5) == 26);
  BOOST_REQUIRE(l2.generate(5) == 28);
  BOOST_REQUIRE(l2.generate(5) == 24);
  BOOST_REQUIRE(l2.generate(5) == 23);
  BOOST_REQUIRE(l2.generate(5) == 29);

}

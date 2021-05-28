#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "BMS_Sender.h"


TEST_CASE("Case To Check the Input Data") {
  InputType Source= FileInput;
  REQUIRE(Read_Input_Data(Source) == Success);
}

TEST_CASE("Case to print to console") {
  InputType Source= FileInput;
  SuccessType ReadSucess= Read_Input_Data(Source);
  Targettype Target= ToConsole;
  REQUIRE(Read_Input_Data(Source) == Success);
  REQUIRE(OutputtoTarget(ToConsole) == Success);
}
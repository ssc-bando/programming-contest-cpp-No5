/*
 * if文使ってません
 */
#include <string>
#include <functional>

#include "fizzbuzz.h"

using namespace std;

namespace{
  const string FIZZ = "fizz";
  const string BUZZ = "buzz";
  const string FIZZBUZZ = FIZZ + BUZZ;
  string return_string;

  auto make_3_divided_result  = [&](int n){ return_string = FIZZ; };
  auto make_5_divided_result  = [&](int n){ return_string =  BUZZ; };
  auto make_15_divided_result = [&](int n){ return_string = FIZZBUZZ; };
  auto make_other_result      = [&](int n){ return_string = std::to_string(n); };
  std::function<void(int)>  func_list[] = {
    make_15_divided_result,
    make_other_result,
    make_other_result,
    make_3_divided_result,
    make_other_result,
    make_5_divided_result,
    make_3_divided_result,
    make_other_result,
    make_other_result,
    make_3_divided_result,
    make_5_divided_result,
    make_other_result,
    make_3_divided_result,
    make_other_result,
    make_other_result,
  };
};

const std::string& fizzbuzz(int n){
  func_list[n % 15](n);
  return return_string;
}


#include "gtest/gtest.h"
#include <Normalization.h>

class NormalizationTest : public ::testing::Test 
{
 protected:
  virtual void SetUp() {
  }
  virtual void TearDown() 
  {
  }
};

TEST_F(NormalizationTest,normalize)
{
    vector<vector<double>> data = {{63000},{55000},{74000},{28000}};
    vector<vector<double>> expected = {{0.760870},{0.586957},{1.00},{0.00}};
    Normalization n;

    n.Normalize(data);

    for (int i = 0; i < data.size(); i++)
    {
      for (int j = 0; j < data[i].size(); j++)
      {
        string str = to_string(data[i][j]);
        string str2 = to_string(expected[i][j]); 
        ASSERT_STREQ(str2.c_str(),str.c_str());
      }
    }
}



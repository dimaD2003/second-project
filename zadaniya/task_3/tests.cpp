#include "gtest/gtest.h"

#include "Functions/funct.h"
TEST(Encode, EncodeStr)
{
	std::string s ="DEV";
	 std::ostringstream out;
	encode(s,out);
	
	EXPECT_EQ(out.str(), "REVW");
}
TEST(DEcode, DEcodeStr)
{
        std::string s ="SQ==";
         std::ostringstream out;
        base64_decode(s,out);

        EXPECT_EQ(out.str(), "I");
}
TEST(Translate, CodeChar)
{
        
         std::ostringstream out;
       

        EXPECT_EQ(FullandString(111,8), "00000111");
}

/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
// TEST(GuesserTest, smoke_test)
// {
//	 Guesser object("Secret");
//	 ASSERT_EQ( 1+1, 2 );
// }

TEST(GuesserTest, one_typo_bool)
{
	Guesser object("Secret");
	bool actual = object.match("secret");
	ASSERT_EQ(false,actual);
}

TEST(GuesserTest, one_typo_int)
{
	Guesser object("Secret");
	// Dummy just checking
	bool actual = object.match("secret");
	int actualRemaining = object.remaining();
	ASSERT_EQ(2, actualRemaining);
}

TEST(GuesserTest, none_both)
{
	Guesser object("");
	bool actual = object.match("");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, insta_block_empty_secret)
{
	Guesser object("");
	bool actual = object.match("wwww");
	actual = object.match("");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, insta_block_empty_guess)
{
	Guesser object("2222");
	bool actual = object.match("");
	actual = object.match("");
	ASSERT_EQ(false, actual);
}

// After a successful guess,
// the remaining guesses should be 3.
TEST(GuesserTest, strike_three_remaining)
{
	Guesser object("letMeIn!");
	bool actual = object.match("letMeIN!");
	actual = object.match("letmeIn!");
	actual = object.match("letMeIn!");
	int actualRemaining = object.remaining();
	ASSERT_EQ(3, actualRemaining);
}

TEST(GuesserTest, secret_length_cutoff_check)
{
	Guesser object("ThisIsATextlongerThan32Characters!");
	bool actual = object.match("ThisIsATextlongerThan32Characters!");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, secret_length_cutoff_check2)
{
	Guesser object("ThisIsATextlongerThan32Characters!");
	bool actual = object.match("ThisIsATextlongerThan32Character");
	ASSERT_EQ(true, actual);
}

// TEST(GuesserTest, )
// {
// 	Guesser object()
// }
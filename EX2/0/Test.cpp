#include "Notebook.hpp"
#include "doctest.h"
using namespace ariel;


TEST_CASE("Good input write") 
{
    Notebook test;
	CHECK_NOTHROW(test.write(1, 1, 1, Direction::Horizontal, "abc"));
    CHECK_NOTHROW(test.write(8, 1, 98, Direction::Horizontal, "a"));
    CHECK_NOTHROW(test.write(0, 0, 0, Direction::Horizontal, "abc"));
}

TEST_CASE("Bad input write") 
{
    Notebook test;
    CHECK_THROWS(test.write(-1, 1, 1, Direction::Horizontal, "abc"));
    CHECK_THROWS(test.write(1, -1, 1, Direction::Horizontal,"abc"));
    CHECK_THROWS(test.write(1, 1, -1, Direction::Horizontal, "abc"));
    CHECK_THROWS(test.write(-1, -1, -1, Direction::Horizontal, "abc"));
    CHECK_THROWS(test.write(5, 5, 100, Direction::Horizontal, "abc"));

    CHECK_THROWS(test.write(5, 5, 100, Direction::Horizontal, "\t"));
    CHECK_THROWS(test.write(5, 5, 100, Direction::Horizontal, "\n"));
    CHECK_THROWS(test.write(5, 5, 100, Direction::Horizontal, "\r"));
    CHECK_THROWS(test.write(5, 5, 100, Direction::Horizontal, "~"));
    CHECK_THROWS(test.write(5, 5, 100, Direction::Horizontal, "_"));

}



TEST_CASE("Good input read") 
{
    Notebook test;
	CHECK_NOTHROW(test.read(0, 0, 0, Direction::Horizontal, 0));
    CHECK_NOTHROW(test.read(1, 1, 99, Direction::Horizontal, 0));
    CHECK_NOTHROW(test.read(1, 1, 1, Direction::Horizontal, 1));
}


TEST_CASE("Bad input read") 
{
    Notebook test;
    CHECK_THROWS(test.read(-1, 1, 1, Direction::Horizontal, 1));
    CHECK_THROWS(test.read(1, -1, 1, Direction::Horizontal,1));
    CHECK_THROWS(test.read(1, 1, -1, Direction::Horizontal, 1));
    CHECK_THROWS(test.read(-1, -1, -1, Direction::Horizontal, 1));
    CHECK_THROWS(test.read(5, 5, 100, Direction::Horizontal, 1));
    CHECK_THROWS(test.read(5, 5, 100, Direction::Horizontal, -1));

}


TEST_CASE("Good input erase") 
{
    Notebook test;
    CHECK_NOTHROW(test.erase(1, 1, 1, Direction::Horizontal, 1));
    CHECK_NOTHROW(test.erase(0, 0, 0, Direction::Horizontal, 0));
    CHECK_NOTHROW(test.erase(1, 1, 99, Direction::Horizontal, 0));
}


TEST_CASE("Bad input erase ") 
{
    Notebook test;
    CHECK_THROWS(test.erase(-1, 1, 1, Direction::Horizontal, 1));
    CHECK_THROWS(test.erase(1, -1, 1, Direction::Horizontal,1));
    CHECK_THROWS(test.erase(1, 1, -1, Direction::Horizontal, 1));
    CHECK_THROWS(test.erase(-1, -1, -1, Direction::Horizontal, 1));
    CHECK_THROWS(test.erase(5, 5, 100, Direction::Horizontal, 1));
    CHECK_THROWS(test.erase(5, 5, 100, Direction::Horizontal, -1));

}


TEST_CASE("Good input show") 
{
    Notebook test;
        CHECK_NOTHROW(test.show(0));
        CHECK_NOTHROW(test.show(1));

}

TEST_CASE("Bad input show ") 
{
    Notebook test;
    CHECK_THROWS(test.show(-1));

}





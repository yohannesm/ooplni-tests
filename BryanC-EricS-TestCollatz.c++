// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

    % g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lpthread -lgtest_main

    % valgrind TestCollatz > TestCollatz.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "Collatz.h"

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(Collatz, read) {
    std::istringstream r("1 10\n");
    int i;
    int j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(1, i);
    ASSERT_EQ(10, j);}

// ------------
// cycle length
// ------------

TEST(Collatz, cycle_1)
{
    const int v = collatz_cycle_length(1);
    ASSERT_EQ(1, v);
}

TEST(Collatz, cycle_2)
{
    const int v = collatz_cycle_length(2);
    ASSERT_EQ(2, v);
}

TEST(Collatz, cycle_3)
{
    const int v = collatz_cycle_length(3);
    ASSERT_EQ(8, v);
}

TEST(Collatz, cycle_4)
{
    const int v = collatz_cycle_length(4);
    ASSERT_EQ(3, v);
}

TEST(Collatz, cycle_5)
{
    const int v = collatz_cycle_length(5);
    ASSERT_EQ(6, v);
}

TEST(Collatz, cycle_6)
{
    const int v = collatz_cycle_length(6);
    ASSERT_EQ(9, v);
}

TEST(Collatz, cycle_7)
{
    const int v = collatz_cycle_length(7);
    ASSERT_EQ(17, v);
}

TEST(Collatz, cycle_8)
{
    const int v = collatz_cycle_length(8);
    ASSERT_EQ(4, v);
}

TEST(Collatz, cycle_9)
{
    const int v = collatz_cycle_length(9);
    ASSERT_EQ(20, v);
}

TEST(Collatz, cycle_10)
{
    const int v = collatz_cycle_length(10);
    ASSERT_EQ(7, v);
}

// ----
// eval
// ----

TEST(Collatz, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(Collatz, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(Collatz, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(Collatz, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(Collatz, eval_5)
{
    const int v = collatz_eval(10, 10);
    ASSERT_EQ(7, v);
}

// -----
// print
// -----

TEST(Collatz, print) {
    std::ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(Collatz, solve) {
    std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    std::ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

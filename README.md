# tbb_test
###->This is a simple test for Intel® Threading Building Blocks (Intel® TBB) library for task parallelism<-
####This test is provided by Dragorad Milovanovic and Dragoslav Jovanovic

Files:

tbb_hello_1.cpp - simple child process
tbb_hello_1.out - output from tbb_hello_1

tbb_hello_2.cpp - creating child processes recursively
tbb_hello_2.out - output from tbb_hello_2

tbb_hello_3.cpp - creating task group
tbb_hello_3.out - output from tbb_hello_3

Command line for compilation:

g++ tbb_hello_x.cpp -ltbb -ohello_x (where x = 1, 2, 3)

Command line for testing:

date > hello_x.out && ./hello >> hello_x.out (where x = 1, 2, 3)

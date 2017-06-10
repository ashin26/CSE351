#!/bin/bash
echo
echo "Provided Cache TESTS: "
echo
make cache-test TEST_CACHE=cache_1c_1a_1b.o
./cache-test
echo
make cache-test TEST_CACHE=cache_65536c_2a_16b.o
./cache-test
echo
make cache-test TEST_CACHE=cache_1048576c_256a_256b.o
./cache-test
echo
make cache-test TEST_CACHE=cache_16384c_4a_4b.o
./cache-test
echo
make cache-test TEST_CACHE=cache_32768c_8a_8b.o
./cache-test
echo
echo "Mystery 0:"
echo
make cache-test TEST_CACHE=mystery0.o
./cache-test
echo
echo "Mystery 1:"
echo
make cache-test TEST_CACHE=mystery1.o
./cache-test
echo
echo "Mystery 2: "
echo
make cache-test TEST_CACHE=mystery2.o
./cache-test
echo
echo "Mystery 3:"
echo
make cache-test TEST_CACHE=mystery3.o
./cache-test
echo
echo "Finished."
echo

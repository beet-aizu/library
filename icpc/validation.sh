#BEGIN CUT HERE
#/bin/bash

if [ $# -ne 3 ]; then
    echo "number of args must be 3"
    exit 1
fi

g++ $1 -o gen.out
g++ $2 -o sol.out
g++ $3 -o ans.out

for i in {1..100}; do
    ./gen.out > tmp.in
    ./sol.out < tmp.in > tmp.sol
    ./ans.out < tmp.in > tmp.ans
    if [ $? -gt 0 ]; then
        echo "runtime error"
        break
    fi
    if [ -n "$(diff tmp.sol tmp.ans)" ]; then
        diff tmp.sol tmp.ans
        break
    fi
done
#END CUT HERE

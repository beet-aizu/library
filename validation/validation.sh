#/bin/bash

g++ $1 -o gen.out
g++ $2 -o sol.out
g++ $3 -o ans.out

for i in {1..100}; do
    ./gen.out > tmp.in
    ./sol.out < tmp.in > tmp.sol
    ./ans.out < tmp.in > tmp.ans
    if [ -n "$(diff tmp.sol tmp.ans)" ]; then
        diff tmp.sol tmp.ans
        break
    fi
done

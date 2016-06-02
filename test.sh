#!/usr/bin/env bash

# build program
make > /dev/null

echo Testing with a plaintext small file
python gen.py 100 > a.file
./reverse a.file >  a.rev
./reverse a.rev  > a2.rev

if cmp -s a.file a2.rev
then
    echo correct
else
    echo wrong
fi

echo Testing with a binary small file
python gen.py 100 -b > a.file
./reverse a.file >  a.rev
./reverse a.rev  > a2.rev

if cmp -s a.file a2.rev
then
    echo correct
else
    echo wrong
fi

echo Testing with a plaintext file
python gen.py 1024 > a.file
./reverse a.file >  a.rev
./reverse a.rev  > a2.rev

if cmp -s a.file a2.rev
then
    echo correct
else
    echo wrong
fi

echo Testing with a binary file
python gen.py 1024 -b > a.file
./reverse a.file >  a.rev
./reverse a.rev  > a2.rev

if cmp -s a.file a2.rev
then
    echo correct
else
    echo wrong
fi

echo Testing with a plaintext large file
python gen.py 8128 > a.file
./reverse a.file >  a.rev
./reverse a.rev  > a2.rev

if cmp -s a.file a2.rev
then
    echo correct
else
    echo wrong
fi

echo Testing with a binary large file
python gen.py 8128 -b > a.file
./reverse a.file >  a.rev
./reverse a.rev  > a2.rev

if cmp -s a.file a2.rev
then
    echo correct
else
    echo wrong
fi

rm -rf a.file a.rev a2.rev
make clean > /dev/null
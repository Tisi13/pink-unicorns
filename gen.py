#!/bin/env python
import sys
import argparse

from random import choice
from collections import defaultdict

parser = argparse.ArgumentParser(description='Generate a random binary file')
parser.add_argument('bytecount', type=int,
                    help='determines amount of bytes')
parser.add_argument('--binary', '-b', action='store_true',
                    help='whether file is a binary')
parser.add_argument('--show-stats', '-s', action='store_true',
                    help='frequencies of characters are displayed')
args = parser.parse_args()

choices = xrange(256) if args.binary else xrange(33, 127)
stats = defaultdict(int)

for i in xrange(int(args.bytecount)):
    ordinal = choice(choices)
    stats[ordinal] += 1
    sys.stdout.write(chr(ordinal))

if args.show_stats:
    for ord, freq in stats.items():
        sys.stderr.write("0x%02X : %d\n" % (ord, freq))
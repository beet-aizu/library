#!/usr/bin/env python3
import sys
import re
from pathlib import Path

args=sys.argv

p = Path(args[1])
assert(p.exists())

d = p.parent.resolve()

def resolve(s):
    r = d.joinpath(s).resolve()
    assert(r.exists())
    with open(r) as f:
        print(f.read())

with open(p) as f:
    ss = f.readlines()
    regex = re.compile(r'^#include\s*"(.*)"')
    for s in ss:
        res = regex.search(s)
        if res:
            resolve(res[1])
        else:
            print(s, end='')

#!/usr/bin/env python3

import hashlib
import sys
import os

h = hashlib.md5()
h.update(sys.argv[1].encode('utf-8'))
s = 'test/timestamp/' + h.hexdigest()
print('remove ' + s)
os.remove('test/timestamp/' + h.hexdigest())

import glob
import hashlib
import json
import pathlib


def get_timestamp(source_path, compiler):
    timestamp_path = pathlib.Path('.verify-helper/timestamp') / hashlib.md5(compiler.encode() + b'/' + str(source_path).encode()).hexdigest()
    if not timestamp_path.exists():
        return None
    with open(str(timestamp_path), 'rb') as fh:
        return fh.read().decode()

import utils

paths = list(map(pathlib.Path, glob.glob('**/*.test.cpp', recursive=True)))

d = dict()
for p in paths:
    x = utils.get_last_commit_time_to_verify(p, compiler='g++')
    y = get_timestamp(p, compiler='g++')
    if y and x == y.strip():
        d[str(p)] = x

d['~'] = 'dummy'
print(json.dumps(d, sort_keys=True, indent=0))

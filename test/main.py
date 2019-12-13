import glob
import math
import os
import hashlib
import pathlib
import subprocess
import time
import resource
from typing import *

import utils

def main(paths: List[pathlib.Path], *, timeout: float = math.inf) -> None:
    compilers = []
    if 'CXX' in os.environ:
        compilers.append(os.environ.get('CXX'))
    else:
        compilers.append('g++')
        compilers.append('clang++')

    cxxflags = os.environ.get('CXXFLAGS', '-std=c++17 -O2 -Wall -g')

    start = time.time()
    for path in paths:
        verified = False

        for cxx in compilers:
            print(cxx)
            if utils.is_verified(path, compiler=cxx):
                continue

            macros = utils.list_defined_macros(path, compiler=cxx)
            print(macros)

            assert(url in macros)
            url = macros['PROBLEM']
            directory =  pathlib.Path('.verify-helper') / hashlib.md5(url.encode()).hexdigest()
            subprocess.check_call(['mkdir', '-p', str(directory)])

            print(url)
            if 'IGNORE' in macros:
                continue

            print("$ $CXX $CXXFLAGS -I . $file")
            subprocess.check_call([cxx, cxxflags, '-I', '.', directory + '/a.out', str(path)])
            subprocess.check_call(['sleep', '2'])
            subprocess.check_call(['oj', 'download', '--system', url, '-d', directory + '/test'])

            verified = True

        if verified:
            utils.mark_verified(path)

        # to prevent taking too long; we may fail to use the results of verification due to expired tokens
        if timeout is not None and time.time() - start > timeout:
            break

    utils.save_timestamps()

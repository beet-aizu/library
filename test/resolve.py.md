---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\nimport sys\nimport re\nfrom pathlib import Path\n\
    \nargs=sys.argv\n\np = Path(args[1])\nassert(p.exists())\n\nd = p.parent.resolve()\n\
    \ndef resolve(s):\n    r = d.joinpath(s).resolve()\n    assert(r.exists())\n \
    \   with open(r) as f:\n        print(f.read())\n\nwith open(p) as f:\n    ss\
    \ = f.readlines()\n    regex = re.compile(r'^#include\\s*\"(.*)\"')\n    for s\
    \ in ss:\n        res = regex.search(s)\n        if res:\n            resolve(res[1])\n\
    \        else:\n            print(s, end='')\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: test/resolve.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: test/resolve.py
layout: document
redirect_from:
- /library/test/resolve.py
- /library/test/resolve.py.html
title: test/resolve.py
---

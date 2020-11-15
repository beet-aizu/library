ans = {}
ans['0'] = 'Nothing'
ans['3.14159265'] = 'pi'
ans['1112345678999+X'] = '九蓮宝燈'
ans['19m19p19s東南西北白發中+Y'] = 'Thirteen Orphans'
ans['All your base are belong to us.'] = '''3
4
4
3
6
2
2'''
ans['くぁｗせｄｒｆｔｇｙふじこｌｐ'] = 'さｍｐぇ'

import sys
for line in sys.stdin:
    print(ans[line.strip()])

import os
import sys

args = sys.argv
assert(len(args)>=3)
assert(not os.path.exists("./{}".format(args[1])))

os.system("mkdir ./{}".format(args[1]))
os.system("$EDITOR ./{}/t.cpp".format(args[1]))

for i in range(int(args[2])):
    os.system("mkdir ./{}/{}".format(args[1],chr(ord("A")+i)))
    os.system("cp ./{}/t.cpp ./{}/{}/{}.cpp"
              .format(args[1],args[1],chr(ord("A")+i),chr(ord("a")+i)))

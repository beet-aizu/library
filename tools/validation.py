#!/usr/bin/env python3
import argparse
import subprocess

parser = argparse.ArgumentParser()

parser.add_argument('-generator', type=str, help='generator', required=True)
parser.add_argument('-naive', type=str, help='naive', required=True)
parser.add_argument('-solution', type=str, help='solution', required=True)

parser.add_argument('-time', type=int, default=1, help='number of iteration')
parser.add_argument('-offset', type=int, default=0, help='seed')
parser.add_argument('-replace', action='store_true', help='in-place')

args = parser.parse_args()

for i in range(args.time):
    t = i if not args.replace else 0
    infile = '{:03d}.in'.format(t)
    naive_out = '{:03d}.naive'.format(t)
    solution_out = '{:03d}.solution'.format(t)

    generate = '{} {} > {}'.format(args.generator, args.offset + i, infile)
    run_naive = '{} < {} > {}'.format(args.naive, infile, naive_out)
    run_solution = '{} < {} > {}'.format(args.solution, infile, solution_out)
    subprocess.run(generate, shell=True)
    subprocess.run(run_naive, shell=True)
    subprocess.run(run_solution, shell=True)

    subprocess.run('diff {} {}'.format(naive_out, solution_out), shell=True)
    proc = subprocess.run(
        ['diff', naive_out, solution_out], stdout=subprocess.PIPE)
    if len(proc.stdout.decode("utf8")) != 0:
        print('outputs differ in case {:03d}'.format(i))
        break

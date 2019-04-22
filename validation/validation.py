#!/usr/bin/env python3
import argparse
import subprocess

parser = argparse.ArgumentParser()

parser.add_argument('-generator', type=str, help='generator', required=True)
parser.add_argument('-naive', type=str, help='naive', required=True)
parser.add_argument('-solution', type=str, help='solution', required=True)

parser.add_argument('-time', type=int, default=1, help='number of iteration')

args = parser.parse_args()

for i in range(args.time):
    infile = '{:03d}.in'.format(i)
    naive_out = '{:03d}.naive'.format(i)
    solution_out = '{:03d}.solution'.format(i)

    subprocess.run('{} {} > {}'.format(args.generator, i, infile), shell=True)
    subprocess.run(
        '{} < {} > {}'.format(args.naive, infile, naive_out), shell=True)
    subprocess.run(
        '{} < {} > {}'.format(args.solution, infile, solution_out),
        shell=True)
    subprocess.run('diff {} {}'.format(naive_out, solution_out), shell=True)

#!/usr/bin/env python3
from sys import argv
import subprocess

folder_size = 100

def gen_path(num: int):
    if num <= 0:
        raise ValueError('Only positive num is supported')
    section_num = (num - 1) // folder_size
    return f'./{section_num * folder_size + 1}-{(section_num + 1) * folder_size}/{num}.cpp'

if __name__ == '__main__':
    try:
        num = int(argv[1])
        path = gen_path(num)
        subprocess.run(['rm', 'a.out'])
        subprocess.run(['g++', '-std=c++11', path])
        subprocess.run('./a.out')
    except (IndexError, ValueError):
        print('Usage: run num (num is positive)')
        exit(2)
    except (FileNotFoundError):
        print("Compilation failure")
        exit(1)
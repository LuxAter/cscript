#!/usr/bin/env python3

import sys
from pprint import pprint

def main():
    file_src = sys.argv[1]
    with open(file_src, 'r') as file:
        data = file.readlines()
    out = "digraph {} {{\n".format(file_src.rstrip('.bnf'))
    out += "  splines=ortho;\n"
    current_src = ""
    lines = []
    for line in data:
        if line.startswith('#'):
            continue
        if line.endswith('::=\n'):
            current_src = line.strip(" ::=\n")
        else:
            for ch in line.split():
                line = "  \"{}\" -> \"{}\";\n".format(current_src, ch)
                if line not in lines:
                    lines.append(line)
                    out += line
    out += "}"
    with open(file_src.rstrip('.bnf') + '.dot', 'w') as file:
        file.write(out)

if __name__ == "__main__":
    main()

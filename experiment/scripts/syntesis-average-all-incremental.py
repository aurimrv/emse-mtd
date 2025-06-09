#!/usr/bin/python3

#####################################################################################
#
# syntesis-average-all-incremental.py  <project_root_dir> <file_project_names> <oneop>
# 
#####################################################################################

import pandas as pd
import sys
import os

BEGIN_TS="BEGIN_TS"
END_TS="END_TS"

def extractData(line):
    data = line.split(";")
    sequence=data[1].strip() # get test case counter order (ctc)
    return int(sequence), line.strip()

def listAverageData(project,file_name,numTests):
    averageScoresOneOp={}
    averageLineMutantsOneOp={}
    averageScoresAll={}
    averageLineMutantsAll={}
    with open(file_name) as f:
        for line in f:
            if (project in line):
                sequence,data = extractData(line)

                if (sequence == numTests):
                    return line;
    return None

def count_lines_comprehension(file_path):
    with open(file_path, "r") as file:
        return sum(1 for line in file if line.strip().isdigit())

def main():
    # total arguments
    n = len(sys.argv)
    if (n < 4):
        print("Usage: syntesis-average-all-incremental.py <project_root_dir> <file_project_names> <oneop> <number_of_tests>")
        exit(1)
    else:
        rootdir = sys.argv[1]
        file_name = sys.argv[2]
        oneop = sys.argv[3].strip()
        oneop = oneop.upper()
        numTests = int(sys.argv[4])

        outputFile = open(os.path.join(rootdir, f"{numTests}-syntese-score-evolution-per-test-increment.csv"), "w")
        outputFile.write(f"PROG;NTC;ALIVE-OP;SCORE-OP;ALIVE-ALL;SCORE-ALL\n")

        with open(os.path.join(rootdir,file_name)) as f:

            for line in f:
                project = line.strip()

                maxGood = count_lines_comprehension(os.path.join(rootdir, project, f"good-{oneop}.txt"))

                # maxGood represents the maximum number of valid test cases for the specific project
                maxTest = numTests
                if(numTests > maxGood):
                    maxTest = maxGood

                data = listAverageData(project,f"{rootdir}/{project}/syntese-score-per-sequence.csv",maxTest)
                print(".",end="")
                if (data):
                    outputFile.write(f"{data}")
                else:
                    outputFile.write(f"{project};{numTests};-;-;-;-\n")
        print()

if (__name__ == "__main__"):
    main()
#!/usr/bin/python3

#####################################################################################
#
# syntesis-average-score-one-op.py  <project_root_dir> <file_project_names> <oneop>
# 
#####################################################################################

import pandas as pd
import sys
import os

BEGIN_TS="BEGIN_TS"
END_TS="END_TS"

def extractData(line):
    data = line.split(";")
    sequence=data[2].strip() # get test case counter order (ctc)
    return int(sequence), line.strip().split(";")

def listAverageData(project,file_name,iterations):
    averageScoresOneOp={}
    averageLineMutantsOneOp={}
    averageScoresAll={}
    averageLineMutantsAll={}
    with open(file_name) as f:
        for line in f:
            if (project in line):
                sequence,data = extractData(line)

                if (sequence in averageScoresOneOp.keys()):
                    averageLineMutantsOneOp[sequence] = averageLineMutantsOneOp[sequence] + int(data[5])
                    averageScoresOneOp[sequence] = averageScoresOneOp[sequence] + float(data[7])
                    averageLineMutantsAll[sequence] = averageLineMutantsAll[sequence] + int(data[9])
                    averageScoresAll[sequence] = averageScoresAll[sequence] + float(data[11])
                else:
                    averageLineMutantsOneOp[sequence] = int(data[5])
                    averageScoresOneOp[sequence] = float(data[7])
                    averageLineMutantsAll[sequence] = int(data[9])
                    averageScoresAll[sequence] = float(data[11])

    #Average calculation
    for sequence in range(0,len(averageLineMutantsOneOp)):
        averageLineMutantsOneOp[sequence] = averageLineMutantsOneOp[sequence] / iterations
        averageScoresOneOp[sequence] = averageScoresOneOp[sequence] / iterations
        averageLineMutantsAll[sequence] = averageLineMutantsAll[sequence] / iterations
        averageScoresAll[sequence] = averageScoresAll[sequence] / iterations

    return averageLineMutantsOneOp, averageScoresOneOp, averageLineMutantsAll, averageScoresAll

def main():
    # total arguments
    n = len(sys.argv)
    if (n < 4):
        print("Usage: syntesis-average-score-one-op.py <project_root_dir> <file_project_names> <oneop> <number_of_executions>")
        exit(1)
    else:
        rootdir = sys.argv[1]
        file_name = sys.argv[2]
        oneop = sys.argv[3].strip()
        oneop = oneop.upper()
        iterations = int(sys.argv[4])

        with open(os.path.join(rootdir,file_name)) as f:

            for line in f:
                project = line.strip()

                outputFile = open(os.path.join(rootdir, project, f"syntese-score-per-sequence.csv"), "w")
                outputFile.write(f"PROG;SEQ;ALIVE-OP;SCORE-OP;ALIVE-ALL;SCORE-ALL\n")

                averageLineMutantsOneOp, averageScoresOneOp, averageLineMutantsAll, averageScoresAll = listAverageData(project,f"{rootdir}/{project}/syntese-score-{oneop}.csv",iterations)

                for key in list(averageLineMutantsOneOp.keys()):
                    aliveOneOp = averageLineMutantsOneOp[key]
                    scoreOneOp = averageScoresOneOp[key]
                    aliveAll = averageLineMutantsAll[key]
                    scoreAll = averageScoresAll[key]
                   
                    outputFile.write(f"{project};{key};{round(aliveOneOp, 1):.1f};{round(scoreOneOp, 5):.5f};{round(aliveAll, 1):.1f};{round(scoreAll, 5):.5f}\n")

if (__name__ == "__main__"):
    main()
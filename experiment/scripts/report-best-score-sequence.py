#!/usr/bin/python3

##########################################################
#
# report-best-score-sequence.py <file_project_names>
# 
##########################################################

import pandas as pd
import sys
import os

BEGIN_TS="BEGIN_TS"
END_TS="END_TS"

def extractData(line):
    data = line.split(";")
    sequence=data[1].strip()
    return sequence, line.strip()

def listSequenceScores(project,file_name):
    scores={}
    sequenceTestCases={}
    with open(file_name) as f:
        for line in f:
            if (project in line):
                sequence,data = extractData(line)
                if (sequence in scores.keys()):
                    testsCases = sequenceTestCases[sequence]
                    sequenceTestCases[sequence] = sequenceTestCases[sequence] + 1
                else:
                    sequenceTestCases[sequence] = 1
                scores[sequence] = data

    return scores, sequenceTestCases

def main():
    # total arguments
    n = len(sys.argv)
    if (n < 3):
        print("Usage: report-best-score-sequence.py <project_root_dir> <file_project_names> <oneop>")
        exit(1)
    else:
        rootdir = sys.argv[1]
        file_name = sys.argv[2]
        oneop = sys.argv[3].strip()
        oneop = oneop.upper()

        with open(os.path.join(rootdir,file_name)) as f:

            for line in f:
                project = line.strip()

                outputFile = open(os.path.join(rootdir, project, f"syntese-score-per-sequence.csv"), "w")
                outputFile.write(f"PROG;SEQ;LAST_TEST;ACTIVE-OP;ALIVE-OP;EQUIVALENT-OP;SCORE-OP;ACTIVE-ALL;ALIVE-ALL;EQUIVALENT-ALL;SCORE-ALL;START-EXEC;END-EXEC;EXEC-TIME;#TC\n")

                sequenceScores,tests = listSequenceScores(project,f"{rootdir}/{project}/syntese-score-{oneop}.csv")

                for key in list(sequenceScores.keys()):
                    value=sequenceScores[key]
                    numTests=tests[key]
                    outputFile.write(f"{value};{numTests}\n")

if (__name__ == "__main__"):
    main()
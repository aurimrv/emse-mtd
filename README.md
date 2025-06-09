# Repository for EMSE submission

This repository contains a set of C programs, scrits and collected raw data illustrating the computation of Mutation Technical Debt.

Repository high level directory structure is below:

```
emse-mtd
├── experiment
│  ├── graphs
│  │  ├── 0-24-mtb-manual-all.csv
│  │  ├── 0-24-mtb-syntesis.csv
│  │  └── mtb_plots
│  ├── programs
│  │  ├── 0-24-mtd-syntesis.csv
│  │  ├── 0-24-mtd-syntesis.ods
│  │  ├── 0-mtd-auto.ods
│  │  ├── 0-mtd-manual.ods
│  │  ├── 0-syntese-score-evolution-per-test-increment.csv
│  │  ├── 10-mtd-manual.ods
│  │  ├── 10-syntese-score-evolution-per-test-increment.csv
│  │  ├── 11-syntese-score-evolution-per-test-increment.csv
│  │  ├── 12-syntese-score-evolution-per-test-increment.csv
│  │  ├── 13-syntese-score-evolution-per-test-increment.csv
│  │  ├── 14-syntese-score-evolution-per-test-increment.csv
│  │  ├── 15-syntese-score-evolution-per-test-increment.csv
│  │  ├── 16-syntese-score-evolution-per-test-increment.csv
│  │  ├── 17-syntese-score-evolution-per-test-increment.csv
│  │  ├── 18-syntese-score-evolution-per-test-increment.csv
│  │  ├── 19-syntese-score-evolution-per-test-increment.csv
│  │  ├── 1-mtd-auto.ods
│  │  ├── 1-mtd-manual.ods
│  │  ├── 1-syntese-score-evolution-per-test-increment.csv
│  │  ├── 20-syntese-score-evolution-per-test-increment.csv
│  │  ├── 21-syntese-score-evolution-per-test-increment.csv
│  │  ├── 22-syntese-score-evolution-per-test-increment.csv
│  │  ├── 23-syntese-score-evolution-per-test-increment.csv
│  │  ├── 24-mtd-manual.ods
│  │  ├── 24-syntese-score-evolution-per-test-increment.csv
│  │  ├── 2-mtd-auto.ods
│  │  ├── 2-mtd-manual.ods
│  │  ├── 2-syntese-score-evolution-per-test-increment.csv
│  │  ├── 3-mtd-auto.ods
│  │  ├── 3-mtd-manual.ods
│  │  ├── 3-syntese-score-evolution-per-test-increment.csv
│  │  ├── 4-mtd-manual.ods
│  │  ├── 4-syntese-score-evolution-per-test-increment.csv
│  │  ├── 5-mtd-manual.ods
│  │  ├── 5-syntese-score-evolution-per-test-increment.csv
│  │  ├── 6-mtd-manual.ods
│  │  ├── 6-syntese-score-evolution-per-test-increment.csv
│  │  ├── 7-mtd-manual.ods
│  │  ├── 7-syntese-score-evolution-per-test-increment.csv
│  │  ├── 8-mtd-manual.ods
│  │  ├── 8-syntese-score-evolution-per-test-increment.csv
│  │  ├── 9-mtd-manual.ods
│  │  ├── 9-syntese-score-evolution-per-test-increment.csv
│  │  ├── boundedQueue
│  │  ├── cal
│  │  ├── Calculation
│  │  ├── checkIt
│  │  ├── CheckPalindrome
│  │  ├── consolidated-mutants-per-operator.csv
│  │  ├── consolidated-mutants-per-operator.ods
│  │  ├── countPositive
│  │  ├── date-plus
│  │  ├── DigitReverser
│  │  ├── dtm-auto-eq-ssdl.ods
│  │  ├── files1.txt
│  │  ├── files-full.txt
│  │  ├── files.txt
│  │  ├── findLast
│  │  ├── findVal
│  │  ├── Gaussian
│  │  ├── Heap
│  │  ├── InversePermutation
│  │  ├── jday-jdate
│  │  ├── lastZero
│  │  ├── LRS
│  │  ├── MergeSort
│  │  ├── numZero
│  │  ├── oddOrPos
│  │  ├── pcal
│  │  ├── power
│  │  ├── printPrimes
│  │  ├── print_tokens
│  │  ├── print_tokens2
│  │  ├── program-metrics.csv
│  │  ├── program-metrics.ods
│  │  ├── Queue
│  │  ├── quicksort
│  │  ├── RecursiveSelectionSort
│  │  ├── replace
│  │  ├── schedule
│  │  ├── schedule2
│  │  ├── space
│  │  ├── Stack
│  │  ├── stats
│  │  ├── sum
│  │  ├── tcas
│  │  ├── testPad
│  │  ├── totinfo
│  │  ├── trashAndTakeOut
│  │  ├── twoPred
│  │  └── UnixCal
│  └── scripts
│      ├── check-equiv.sh
│      ├── consolidate_mutants.py
│      ├── import-new-tc.sh
│      ├── mtb-graphs-ssdl.py
│      ├── mtd-graphs-all.py
│      ├── program-metrics.sh
│      ├── PROTEUM.md
│      ├── quantity-mutant-per-opeator.sh
│      ├── README.md
│      ├── relatorios.txt
│      ├── report-best-score-sequence.py
│      ├── report-gpt-generation-time.py
│      ├── report-gpt-sequence-score-avg.py
│      ├── requirements.txt
│      ├── run-equiv.sh
│      ├── run-one-op-qty.sh
│      ├── run-one-op.sh
│      ├── run-research.sh
│      ├── shuffle.py
│      ├── syntesis-average-all-incremental.py
│      ├── syntesis-average-score-one-op.py
│      ├── syntesis-number-mutants-per-operator.sh
│      ├── syntesis-score-one-op.sh
│      ├── time-diff.py
│      └── unit-operators-list.txt
├── historical-data
│  ├── c
│  │  ├── proteum-operators-report.csv
│  │  └── proteum-operators-report.ods
│  └── python
│      ├── cosmicray-operators-report.csv
│      ├── cosmicray-operators-report.ods
│      ├── mutpy-operators-report.csv
│      └── mutpy-operators-report.ods
├── images
│  ├── sonarqube-01.png
│  ├── sonarqube-02.png
│  ├── sonarqube-03.png
│  └── sonarqube-04.png
└── README.md
```

Folder experiments contains the set of C programs, scripts, graphs, and a set of csv and ods files with incremental evolution of MTD both manual and auto.

Folder historical-data contains csv and ods files with mutation operators data from previous experiments.

Folder images contains some images used in the paper.
#!/bin/bash

#########################################################################################
# ./quantity-mutant-per-opeator.sh <session-name> <operator-list-numbers> <output-file-op-list> <output-file-op-qty>
# ./quantity-mutant-per-opeator.sh $HOME/temp/matheus-tcc/delamaro/mode-test input.txt output-op-list.txt output-op-qty.txt 
#########################################################################################


if [ "$#" -ne 4 ]
then
  echo "Usage: ./quantity-mutant-per-opeator.sh <session-name> <operator-list-numbers> <output-file-op-list> <output-file-op-qty>"
  exit 1
else
   SESSION=$1
   OPLIST=$2
   OUTPUTOPLIST=$3
   OUTPUTOPQTY=$4

   echo -n "" > $OUTPUTOPLIST
   for mut in $(cat $OPLIST)
   do
      operator=$(muta -l -x $mut $SESSION | grep "Operator:" | sed -n 's/.*(\([^)]*\)).*/\1/p')
      echo "$operator" >> $OUTPUTOPLIST
   done

   sorted_count=$(sort "$OUTPUTOPLIST" | uniq -c)

   if [[ -z "$sorted_count" || "$sorted_count" =~ ^$'\n'$ ]]; then
      touch "$OUTPUTOPQTY"
   else
     # Process the sorted and counted output to generate CSV
     awk '{
          name=$2;
          count=$1;
          printf "%s,%s\n", name, count;
        }' <<< "$sorted_count" >  "$OUTPUTOPQTY"
   fi
fi
#！/bin/bash
dir=$1
all=0
pass=0
for file in $dir/*; do
    all=`expr $all + 1`
    echo "testing " $file
    logfile=./log.txt
    ./compiler -S -o testcase.s $file > $logfile
    if (grep 'complete' $logfile > /dev/null) then
        echo "\033[1;32mPASS!\033[0m"
        pass=`expr $pass + 1`
    else
        cat $logfile
        echo "\033[1;31mFAIL!\033[0m"
    fi
done

echo "[all/pass]: $all/$pass"
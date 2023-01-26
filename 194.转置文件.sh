#
# @lc app=leetcode.cn id=194 lang=bash
#
# [194] 转置文件
#

# @lc code=start
# Read from the file file.txt and print its transposed content to stdout.
lines=`cat file.txt | wc -l`
total=`cat file.txt | wc -w`
cols=$(($total/$lines))

for i in `seq 1 $cols`
do
awk '{print $'''$i'''}' file.txt | xargs
done
# @lc code=end


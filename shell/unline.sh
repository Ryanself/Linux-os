#!/bin/bash
a=$2
cp $1 $a
cat $1 | grep include > ${1}a
#cat $1 | grep define >> ${1}a
cat $1 | grep INLINE > ${1}b
sed -i 's/$/&;/g' ${1}b
cat ${1}b >> ${1}a
mv ${1}a  ${1}
rm ${1}b
sed -i 's/__INLINE //g' $a

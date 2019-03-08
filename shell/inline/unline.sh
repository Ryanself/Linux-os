#!/bin/sh
cp $1 $2
cat $1 | grep INLINE > ${1}a
sed -i 's/$/&;/g' ${1}a
mv ${1}a  ${1}
sed -i 's/__INLINE //g' $2

#!/bin/sh

sup(){
	echo "sup>>>>>>>>>>>>"
	local a="$1"
	local b
	[ ${b:-0} -gt 0   ] && echo "b > 0>>>>"
	[ ${a:-1} -gt 0  ] && echo "a is not exit"

}


sup 1

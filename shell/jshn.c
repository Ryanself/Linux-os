#!/bin/sh
        __dest="zz"
        _tbl_cur="zzzzzzzzzzzzzzzzaaaaaaaaaa"
        __var="${_tbl_cur}"
       eval " \"$__dest=\${$__var}\"; [ -n \"\${$__var+x}\" ]"
       echo "\"$__dest=\${$__var}\"; [ -n \"\${$__var+x}\"  ]"

#!/bin/sh

sed_del_import="/import.*\"$1\"/d"
sed_del_name="s/Cmd[123456789]\.//g"
sed -e "$sed_del_import" -e "$sed_del_name" "$2" > ../.temp.pb.go
mv ../.temp.pb.go "$2"


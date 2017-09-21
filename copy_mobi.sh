#!/bin/bash
# This script takes every file that ends with .mobi and copies it to my documents folder
find "pwd" -name *.mobi | while read varname; do cp "$varname" ~/Documents/losmobis ; done

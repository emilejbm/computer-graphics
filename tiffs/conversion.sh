#!/bin/bash

for f in *.jpg
do  
    echo "Converting $f" 
    convert -resize 600X400 "$f" "$(basename "$f".jpg).tif" 
done

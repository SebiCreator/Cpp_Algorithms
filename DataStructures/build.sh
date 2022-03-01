#!/bin/zsh
for s in Arrays BinaryTree LinkedList Stack Queue ; do
  compile_command="g++ -std=d++20 -c -o $s.o $s.h"
  echo $compile_command
  eval $compile_command
  if [ $? -ne 0 ] ;  then
      echo build failed
      exit 1
  fi
done

link_command="g++ -shared -o datastructs.so Arrays.o BinaryTree.o LinkedList.o Queue.o Stack.o"
echo $link_command
eval $link_command
if [ $? -ne 0 ] ; then
  echo build failed
  exit 1
fi

echo build sucessful
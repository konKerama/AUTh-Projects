Command Line Interpreter

main:
  if I have argument go to batch
  else to interactive

interactive:
  do an infinite loop and print the command line name
  read the input
  Check if input is empty or too big
  Add null terminator at the end of the to know when it ends
  cut the string between the ";"
  for every "cutted" string delete trailing and leading spaces
  parse the arguments
  and then execute the command
  wait for all the Childs to finish and then ask for the next command

batch:
  same general algorithm

hasQuit:
  search the whole file if it has quit
  if it doesn't have don't execute the commands

deletewhitespaces:
  decrement the end pointer until you find the string
  when your find it add the null terminator in the next memory position

  increment the start pointer until you find the string

parse:
  convert the buffer to arguments

execute:
  Do fork
  execute the command with execvp
  if execvp doesn't execute the command print the command invalids

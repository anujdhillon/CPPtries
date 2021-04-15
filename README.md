This project supports serializing and deserializing of a trie.

The trie is formed in the file serializer.cpp and serialized within the same. The output is in the form of a .txt file.

Two arguments are to be supplied while execution, <file-containing-words-with-newline-delimiter> <serialized-output-name>

To run, type in command line ->
g++ serializer.cpp -o serializer
./serializer words.txt serial.txt

This trie can be deserialized in deserializer.cpp and queries can be entered in the form of a text file. The code will then print on the console if it is present.

Two arguments are to be supplied while execution, <file-containing-serialized-trie> <file-containing-queries>

Sample execution ->
g++ deserializer.cpp -o deserializer
./deserializer serial.txt Inputs.txt
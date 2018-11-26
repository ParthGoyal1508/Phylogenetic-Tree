# Phylogenic-Tree

## Description

There are two parts of the program : 
- 1 : This part parses the nucleotide sequences given in `Nucleotide.txt` and generates the phylogenic tree based on their sequence similarity.
  - a : Outputs a table `Ndistance.txt` which is a table denoting the distance between any two nucleotide strands, the distance given by the total number of mismatches by the total length of the nucleotide sequence.
  - b : Using the distance table `Ndistance.txt` created in part a, it generates a phylogenic tree, the innermost braces showing the maximum similarity.
- 2 : This part parses two files `Protein.txt`, containing protein sequences, and `BLOSUM62.txt` to generate phylogenic tree based to distances between encoded amino acids.
  - a : Outputs a table `Pdistance.txt` which is a table denoting the distance between two protein strands based on distance between amino acids.
  - b : Using the distance table `Pdistance.txt` created in part a, it generates a phylogenic tree, the innermost braces showing the maximum similarity.
  
## Running the Program

To run the program :
- 1a :
  - `gcc 1a.c`
  - `./a.out`
- 1b :
  - `gcc 1b.c`
  - `./a.out`
- 2a :
  - `gcc 2a.c`
  - `./a.out`
- 2b :
  - `gcc 2b.c`
  - `./a.out`

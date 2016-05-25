# Depth-First-Search
A C++ implementation ofDepth First search. CSC 325 - Algorithms
  
Write a program h6.cpp to implement the strongly-connected component (SCC) algorithm from section 22.5 of the textbook. The input is a digraph, which you must read from standard input. The digraph is represented as one or more lines, each of which consists of exactly two node names separated by whitespace. The line  

    foo bar  
    
means that there is an edge from node foo to node bar. Both node names may be the same, as in 

    green green  
    
which means that node green has a self-loop. Note that a node could be a sink (if it only appears as the second node on a line), or a source (if it only appears as the first node on a line), but since every line contains exactly two node names there is no way to represent a node with no edges at all.
The output is one line for each SCC in the input digraph, with the nodes in alphabetical order and separated by a single space. In addition, the lines containing the different SCC's must be sorted by their first node. Thus the output is unique. As always, the formatting must match exactly, byte-for-byte. Write your output to standard output.
For example, the digraph in Figure 22.9(a) on page 616 might be represented as follows:

    b f  
    c d  
    a b  
    h h  
    b c  
    c g  
    b e  
    g f  
    d h  
    d c  
    e f  
    e a  
    f g  
    g h  
        
and the output must contain exactly the following four lines, representing the four SCC's.  

    a b e  
    c d  
    f g  
    h  
        
Your program must run in time O(m + n), which means you must use an adjacency-list representation.

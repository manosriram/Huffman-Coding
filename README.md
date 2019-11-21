# **Huffman Compression.**

![Tree](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fi2.wp.com%2Fwww.techiedelight.com%2Fwp-content%2Fuploads%2F2016%2F11%2FHuffman-Coding-6.png%3Fresize%3D426%252C413%26ssl%3D1&f=1&nofb=1)

## Introduction.
      Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression.
      Huffman coding, an algorithm developed by David A. Huffman while he was a Sc.D. student at MIT, and published
      in the 1952 paper "A Method for the Construction of Minimum-Redundancy Codes".

      Huffman Algorithm is designed in such a way that each letter is given a code to access it. More frequent 
      letters are given smaller codes and less frequent letters are given bigger codes. It is because, with smaller
      codes, more frequent letters can be accessed many number of times quickly.
      
      Each Letter has a frequency. A Priority Queue is Constructed on these frequencies where Higher Priority is
      given to lower frequency.

## Construction of Huffman-Tree.
      A Node has a frequency count (Refer HuffStruct.hpp). First, insert all unique letter's frequencies into the
      queue. Then, do the following:
      - While, there is more than 1 element in the queue,
          - Remove Two Nodes from the queue's front (Nodes with least frequencies).
          - Create a new node which is not a leaf node and has the frequency of (Node1's + Node2's) frequency.
          - Push the newly created node into the queue.
      - The remaining element in the queue is the Root of the Tree.
      
## Encoding Text.
      As said, each letter has a frequency of its own. More frequent character tend to have smaller codes
      and vice-versa. To get the code for a character, 
      - Traverse the Tree.
          - If traversed right, append '1' to the resultant string.
          - If traversed left, append '0' to the resultant string.
          - If the Current node is a leaf node and it the target character, return.
      
      For Example, let st = "abbc".
![Tree](https://github.com/manosriram/Huffman-Coding/blob/master/Static/Tree.PNG)      

      Here the frequency of 'b' is 50%. Frequencies of 'a' and
      'b' are 25% each.
      
      So, to reach 'b' we traverse the path '0'. To reach 'a', we traverse the path '10'.
      Similarly, to reach 'c' we traverse the path '11'.
      
      Finally, the encoded text for "abbc" will be "100011". Most of the times, the encoded text will be
      longer than the original text. But that doesn't mean that the size of the file is bigger.
      
      It is because, the text consists of characters which for each character needs 8 bits or 1 byte.
      So, if a file is of length n, the space required will be (n * 8). But, if we encode it we can
      turn it into 0's and 1's which only takes 1 bit (per symbol). Hence, there is a drastic 
      reduction in the file's size.

## Decoding Text.
      To be Documented.

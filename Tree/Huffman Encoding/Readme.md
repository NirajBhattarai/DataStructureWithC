# Huffman Encoding vs. ASCII Encoding

## Objective

Represent a given dataset using the least number of bits without information loss.

## Dataset

### 1. ASCII Encoding

Each character in ASCII is represented using 8 bits. 

| **Character** | **ASCII Code (8 bits)** |
|:-------------:|:-----------------------:|
|       B       |       `01000010`        |
|       E       |       `01000101`        |
|       C       |       `01000011`        |
|       D       |       `01000100`        |

**Encoded String**:
01000010 01000101 01000101 01000010 01000101 01000011 01000101 01000100 01000101


**Total Bits**: 72

### 2. Huffman Encoding

Based on the dataset's character frequencies, characters are encoded with variable bit lengths.

| **Character** | **Frequency** | **Huffman Code** |
|:-------------:|:-------------:|:----------------:|
|       E       |       4       |       `0`        |
|       B       |       2       |       `10`       |
|       C       |       1       |       `110`      |
|       D       |       1       |       `111`      |

**Encoded String**:

**Total Bits**: 15


# Huffman Encoding for the String "BEEKEEPER"

## Dataset: "BEEKEEPER"

## Character Frequencies

| **Character** | **Frequency** |
|:-------------:|:-------------:|
|       E       |       5       |
|       B       |       1       |
|       K       |       1       |
|       R       |       1       |


### Tree Visualization:

                   8
                /    \
             0 /      \
              /        \ 
              3         \    
            /   \        \  
           2     \        \
          /  \    \        \
          B  E     K        R              






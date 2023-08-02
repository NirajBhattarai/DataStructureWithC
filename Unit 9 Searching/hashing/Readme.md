Hashing, Hash Functions, and Hash Tables
Hashing is a technique used for mapping data to a fixed-size value or key. This key helps in the quick retrieval of the data which becomes useful in database management and data retrieval systems like a cache.

A Hash Function is used to generate the hash code or hash value. A good hash function maps the input data over the output uniformly, thus reducing the chances of collision (where two different inputs produce the same output hash).

A Hash Table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.


```
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct DataItem {
   int data;   
   int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}

struct DataItem *search(int key) {
   int hashIndex = hashCode(key);  
	
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
      ++hashIndex;
		
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(int key,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   int hashIndex = hashCode(key);

   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      ++hashIndex;
		
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int key = item->key;

   int hashIndex = hashCode(key);

   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      ++hashIndex;
		
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {

      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 

   insert(1, 20);
   insert(2, 70);
   insert(42, 80);
   insert(4, 25);
   insert(12, 44);
   insert(14, 32);
   insert(17, 11);
   insert(13, 78);
   insert(37, 97);

   display();
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

   delete(item);
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }
}

```

```
import java.util.Arrays;

class DataItem {
   int data;
   int key;

   public DataItem(int key, int data) {
       this.key = key;
       this.data = data;
   }
}

public class HashTable {

   private static final int SIZE = 20;
   private DataItem[] hashArray;
   private DataItem dummyItem;
   private DataItem item;

   public HashTable() {
       hashArray = new DataItem[SIZE];
       dummyItem = new DataItem(-1, -1);
   }

   private int hashCode(int key) {
       return key % SIZE;
   }

   public DataItem search(int key) {
       int hashIndex = hashCode(key);

       while(hashArray[hashIndex] != null) {
           if(hashArray[hashIndex].key == key)
               return hashArray[hashIndex];

           ++hashIndex;
           hashIndex %= SIZE;
       }

       return null;
   }

   public void insert(int key, int data) {
       DataItem item = new DataItem(key, data);
       int hashIndex = hashCode(key);

       while(hashArray[hashIndex] != null && hashArray[hashIndex].key != -1) {
           ++hashIndex;
           hashIndex %= SIZE;
       }

       hashArray[hashIndex] = item;
   }

   public DataItem delete(DataItem item) {
       int key = item.key;
       int hashIndex = hashCode(key);

       while(hashArray[hashIndex] != null) {

           if(hashArray[hashIndex].key == key) {
               DataItem temp = hashArray[hashIndex];
               hashArray[hashIndex] = dummyItem;
               return temp;
           }

           ++hashIndex;
           hashIndex %= SIZE;
       }

       return null;
   }

   public void display() {
       Arrays.stream(hashArray).forEach(item -> {
           if(item != null)
               System.out.printf(" (%d,%d)",item.key,item.data);
           else
               System.out.printf(" ~~ ");
       });

       System.out.println();
   }

   public static void main(String[] args) {
       HashTable hashTable = new HashTable();

       hashTable.insert(1, 20);
       hashTable.insert(2, 70);
       hashTable.insert(42, 80);
       hashTable.insert(4, 25);
       hashTable.insert(12, 44);
       hashTable.insert(14, 32);
       hashTable.insert(17, 11);
       hashTable.insert(13, 78);
       hashTable.insert(37, 97);

       hashTable.display();
       DataItem item = hashTable.search(37);

       if(item != null) {
           System.out.println("Element found: " + item.data);
       } else {
           System.out.println("Element not found");
       }

       hashTable.delete(item);
       item = hashTable.search(37);

       if(item != null) {
           System.out.println("Element found: " + item.data);
       } else {
           System.out.println("Element not found");
       }
   }
}


```


#include "hashtable.h"

HashTable::HashTable()
{
  bucketNum = 17;
  table = new list<customer>[17];
}

HashTable::HashTable(int buckets)
{
  bucketNum = buckets;
  table = new list<customer>[buckets];
}

int HashTable::hash(customer& person)
{
  int index = person.id % bucketNum;
  return index;
}
HashTable::insert(customer& person)
{
  int index = hash(person);
  table[index]
}

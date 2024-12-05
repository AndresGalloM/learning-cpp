#include <iostream>

struct HashNode {
  int key;
  const char* value;
  HashNode *next = nullptr;

  HashNode(int key, const char* value) : key(key), value(value), next(nullptr) {}
};

struct LinkedList {
  HashNode *head = nullptr;

  void insert(int key, const char* value) {
    HashNode *node = new HashNode(key, value);
    node->next = head;
    head = node;
  }
};



class HashTable {
  public:
    LinkedList *tableHash;
    int size = 0;

    HashTable(int size) : size(size) {
      tableHash = new LinkedList[size];
    }

    int hashFunction(int key) {
      return key % size;
    }

    void insert(int key, const char* value) {
      int index = hashFunction(key);
      tableHash[index].insert(key, value);
    }

    void print() {
      for (int i = 0; i < size; i++) {
        HashNode *temp = tableHash[i].head;

        if (temp == nullptr) continue;

        std::cout << "Index[" << i << "]: " << std::endl;

        while (temp != nullptr) {
          std::cout << "\t" << "[" << temp->key << "]: " << temp->value << std::endl;
          temp = temp->next;
        }
      }
    }

    ~HashTable() {
      delete[] tableHash;
    }
};

int main() {
  HashTable table(10);

  table.insert(5, "John");
  table.insert(1, "Tom");
  table.insert(10, "James");
  table.insert(26, "Tina");
  table.insert(99, "Sana");
  table.insert(105, "Mary");

  table.print();

  return 0;
}
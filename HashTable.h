#include <utility>
#include <vector>

template <typename T>
class HashTable {
public:
    struct Link {
        T data;
        Link* next;
    };


    HashTable(std::size_t tableSize) {
        this->data = new Link*[tableSize];
        for (std::size_t i = 0; i < tableSize; i++) {
            this->data[i] = nullptr;
        }
        this->size = tableSize;
    }


    HashTable(T* array, std::size_t size) : HashTable(size) {
        for (std::size_t i = 0; i < size; i++) {
            this->Insert(array[i]);
        }
    }


    ~HashTable<T>() {
        delete[] data;
    };

    void Insert(T val) {
        auto index = Hash(val) % size;

        if (data[index] == nullptr) {
            data[index] = new Link;
            data[index]->data = val;
            data[index]->next = nullptr;
        } else {
            Link* l = data[index];
            while (l->next != nullptr) {
                l = l->next;
            }
            l->next = new Link;
            l->next->data = val;
            l->next->next = nullptr;
        }
    }

    bool Contains(const T& val) {
        auto index = Hash(val) % size;
        Link* entry = data[index];

        while (entry != nullptr) {
            if (entry->data == val) {
                return true;
            }
            entry = entry->next;
        }

        return false;
    }

    std::size_t Hash(const T& val) {
       const unsigned int fnv_prime = 0x811C9DC5;
       std::size_t hash = 0;

       for(auto iter = val.cbegin(); iter != val.cend(); iter++) {
          hash *= fnv_prime;
          hash ^= *iter;
       }

       return hash;
    }

    std::vector<T> GetElements() {
        std::vector<T> elements;

        for (std::size_t index; index < size; index++) {
            Link* entry = data[index];

            while (entry != nullptr) {
                elements.push_back(entry->data);
                entry = entry->next;
            }
        }

        return elements;

    }

private:
    Link** data;
    std::size_t size;

};

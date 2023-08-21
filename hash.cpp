#include "hash.h"
#include "hashfunctions.h"

// LOOK FOR THE COMMENTS IN THE .H 
// TO UNDERSTAND WHAT EACH FUNCTION MUST DO

Hash::Hash(int tablesize, int (*hf) (std::string) ) {

    _hash_func = hf;
    _table.resize(tablesize);
}

int Hash::add(std::string str, int &collisions) {

    int valor = hash(str);
    
    if (contains(str, collisions) == 1)
    {
        return 0;
    }

    else
    {
        _table.at(valor).push_front (str);
        return 1;
    }
}

int Hash::remove(std::string str, int &collisions) {

    int valor = hash(str);

    if (contains(str, collisions) == 0)
    {
        return 0;
    }

    else
    {
        _table.at(valor).remove (str);
        return 1;
    }
}


int Hash::hash(std::string str) { 
    
   return _hash_func(str);
    
}
    
int Hash::contains(std::string str, int &collisions) { 

    collisions = 0;
    int valor = hash(str);
    for (std:: string c : _table[valor])
    {
        collisions = collisions + 1;
        if (c == str)
        {
            return 1;
        }
    }
    return 0;
}


int Hash::worst_case() {

    int comprimento = _table.size();
    int lenght_list = 0;
    for (int i=0; i<comprimento; i++)
    {
        if (lenght_list < distance(_table[i].begin(), _table[i].end()))
        {
            lenght_list = distance(_table[i].begin(), _table[i].end());
        }
    }
    return lenght_list;
}

int Hash::size() {

    int comprimento = _table.size();
    int total_str = 0;
    for (int i=0; i<comprimento; i++)
    {
        total_str = distance(_table[i].begin(), _table[i].end()) + total_str;
    }
    return total_str;
}



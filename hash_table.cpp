

#define CAPACITY 50000 // Size of the HashTable.
//!this fun genreat the index in the hash table 
// where the value associated with the input string will be stored.
//unsigned long = data type mean positive long integer 
unsigned long hash_function(char* str) 
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)//Iterate over each character in the input string str.
        i += str[j]; // Add the ASCII value of the current character to the hash value i.
    //i will be the sum of ASCII values of all characters in the input string.
    return i % CAPACITY; 
    //ensures that the resulting hash value is within the range of the hash table's capacity
}

//! Defines the HashTable item.

//typedef == used to create a new name for an existing data type
typedef struct Ht_item
{
    char* key; // is a pointer to a character,intended to store the key associated with the item in the hash table.
    char* value; 
} Ht_item;

//! Defines the HashTable.
typedef struct HashTable
{
    // Contains an array of pointers to items.
    Ht_item** items; //This is a pointer to a pointer Ht_item ( double-pointer).
    LinkedList** overflow_buckets;
    int size;
    int count;
} HashTable;

Ht_item* create_item(char* key, char* value)
{
    // Creates a pointer to a new HashTable item.
    // The cast (Ht_item*) is used to explicitly cast the malloc return value to the type Ht_item*.
    // malloc allocates memory on the heap and returns a pointer to the allocated memory.
    // sizeof(Ht_item) returns the size (in bytes) needed to store an Ht_item.
    Ht_item* item = (Ht_item*) malloc(sizeof(Ht_item));
    //strlen(key) returns the length of the input key string.
    //+ 1 is added to allocate memory for the null-terminator character at the end of the string.
    item->key = (char*) malloc(strlen(key) + 1);
    item->value = (char*) malloc(strlen(value) + 1);
    //This line copies the contents of the key string into the allocated memory for the key field of the Ht_item structure.
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}

HashTable* create_table(int size)
{
    // Creates a new HashTable.
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**) calloc(table->size, sizeof(Ht_item*));

    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;
    table->overflow_buckets = create_overflow_buckets(table);

    return table;
}

void free_item(Ht_item* item)
{
    // Frees an item.
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(HashTable* table)
{
    // Frees the table.
    for (int i = 0; i < table->size; i++)
    {
        Ht_item* item = table->items[i];

        if (item != NULL)
            free_item(item);
    }
    free_overflow_buckets(table);
    free(table->items);
    free(table);
}

void print_table(HashTable* table)
{
    printf("\nHash Table\n-------------------\n");

    for (int i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i] -> key, table->items[i]->value);
        }
    }

    printf("-------------------\n\n");
}

void ht_insert(HashTable* table, char* key, char* value)
{
    create_item(key, value)
    int index = hash_function(key);
    Ht_item* current_item = table->items[index];

    if (current_item == NULL)
    {
        // Key does not exist.
        if (table->count == table->size)
        {
            // HashTable is full.
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return;
        }

        // Insert directly.
        table->items[index] = item;
        table->count++;
    }
    else {
        // Scenario 1: Update the value.
        if (strcmp(current_item->key, key) == 0)
        {
            strcpy(table->items[index] -> value, value);
            return;
        }
        else {
                // Scenario 2: Handle the collision.
                handle_collision(table,index,item);
                return;
            }
    }

}

char* ht_search(HashTable* table, char* key)
{
    // Searches for the key in the HashTable.
    // Returns NULL if it doesn't exist.
    int index = hash_function(key);
    Ht_item* item = table->items[index];
    LinkedList* head = table->overflow_buckets[index];

    // Provide only non-NULL values.
    if (item != NULL)
    {
        if (strcmp(item->key, key) == 0)
            return item->value;
        if (head == NULL)
            return NULL;

        item = head->item;
        head = head->next;
    }

    return NULL;
}

//! Defines the LinkedList.
typedef struct LinkedList {
    Ht_item* item;
    struct LinkedList* next;
} LinkedList;;

LinkedList* allocate_list()
{
    // Allocates memory for a LinkedList pointer.
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    return list;
}

LinkedList* linkedlist_insert(LinkedList* list, Ht_item* item)
{
    // Inserts the item onto the LinkedList.
    if (!list) // if empty add the first item (head)
    {
        LinkedList* head = allocate_list();
        head->item = item;
        head->next = NULL;
        list = head;
        return list;
    }
    else if (list->next == NULL) // if there is just one element
    {
        LinkedList* node = allocate_list();
        node->item = item;
        node->next = NULL;
        list->next = node;
        return list;
    }

    LinkedList* temp = list; //used to traverse the linked list and find the last node.

    while (temp->next->next)
    {
        temp = temp->next;
    }

    LinkedList* node = allocate_list();
    node->item = item;
    node->next = NULL;
    temp->next = node;
    return list;
}

//! there are mistakes
Ht_item* linkedlist_remove(LinkedList* list)
{
    // Removes the head from the LinkedList.
    // Returns the item of the popped element.
    if (!list)
        return NULL;

    if (!list->next)
        return NULL;

    LinkedList* node = list->next;
    LinkedList* temp = list;
    temp->next = NULL;
    list = node;
    Ht_item* it = NULL;
    memcpy(temp->item, it, sizeof(Ht_item));
    free(temp->item->key);
    free(temp->item->value);
    free(temp->item);
    free(temp);
    return it;
}

void free_linkedlist(LinkedList* list)
{
    LinkedList* temp = list;
//while loop that continues as long as the list pointer is not NULL. 
//This indicates that there are still elements in the linked list that need to be freed.
    while (list)
    {
        temp = list;
        list = list->next;
        free(temp->item->key);
        free(temp->item->value);
        free(temp->item);
        free(temp);
    }
}

LinkedList** create_overflow_buckets(HashTable* table)
{
    // Create the overflow buckets; an array of LinkedLists.
    LinkedList** buckets = (LinkedList**) calloc(table->size, sizeof(LinkedList*));

    for (int i = 0; i < table->size; i++)
        buckets[i] = NULL;

    return buckets;
}

void free_overflow_buckets(HashTable* table)
{
    // Free all the overflow bucket lists.
    LinkedList** buckets = table->overflow_buckets;

    for (int i = 0; i < table->size; i++)
        free_linkedlist(buckets[i]);

    free(buckets);
}

void handle_collision(HashTable* table, unsigned long index, Ht_item* item)
{
    LinkedList* head = table->overflow_buckets[index];

    if (head == NULL)
    {
        // Creates the list.
        head = allocate_list();
        head->item = item;
        table->overflow_buckets[index] = head;
        return;
    }
    else {
        // Insert to the list.
        table->overflow_buckets[index] = linkedlist_insert(head, item);
        return;
    }
}

void ht_delete(HashTable* table, char* key)
{
    // Deletes an item from the table.
    int index = hash_function(key);
    Ht_item* item = table->items[index];
    LinkedList* head = table->overflow_buckets[index];

    if (item == NULL)
    {
        // Does not exist.
        return;
    }
    else {
        if (head == NULL && strcmp(item->key, key) == 0)
        {
            // Collision chain does not exist.
            // Remove the item.
            // Set table index to NULL.
            table->items[index] = NULL;
            free_item(item);
            table->count--;
            return;
        }
        else if (head != NULL)
        {
            // Collision chain exists.
            if (strcmp(item->key, key) == 0)
            {
                // Remove this item.
                // Set the head of the list as the new item.
                free_item(item);
                LinkedList* node = head;
                head = head->next;
                node->next = NULL;
                table->items[index] = create_item(node->item->key, node->item->value);
                free_linkedlist(node);
                table->overflow_buckets[index] = head;
                return;
            }

            LinkedList* curr = head;
            LinkedList* prev = NULL;

            while (curr)
            {
                if (strcmp(curr->item->key, key) == 0)
                {
                    if (prev == NULL)
                    {
                        // First element of the chain.
                        // Remove the chain.
                        free_linkedlist(head);
                        table->overflow_buckets[index] = NULL;
                        return;
                    }
                    else
                    {
                        // This is somewhere in the chain.
                        prev->next = curr->next;
                        curr->next = NULL;
                        free_linkedlist(curr);
                        table->overflow_buckets[index] = head;
                        return;
                    }
                }

                curr = curr->next;
                prev = curr;
            }
        }
    }
}


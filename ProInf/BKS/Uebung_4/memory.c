struct Block {
    int a;
}

void memory_init(){};

void *memory_allocate(size_t byte_count){};

void memory_free(void *pointer){};void memory_print(){};

void *memory_by_index(size_t index){};
#include <stdio.h>
#include <stdlib.h>

#if 1

typedef struct cell cell;

struct cell {
	void* value;
	cell* next;
};

typedef struct controller controller;

struct controller {
	cell* head;
};

controller* controller_empty();

int is_empty_controller(controller* p);

int add_cell_head(controller* dest, void* value);

void memory_nightmare(void);

#define SIZE 10000000

int main() {
	void* x = 0;
	controller* p = controller_empty();
	if (p == nullptr) {
		return EXIT_FAILURE;
	}
	while (1) {
		add_cell_head(p, x);
	}
	return EXIT_SUCCESS;
}


controller* controller_empty() {
	controller* p = malloc(sizeof(*p));
	if (p == nullptr) {
		return nullptr;
	}
	p->head = nullptr;
	return p;
}

int is_empty_controller(controller* p) {
	return p->head == nullptr;
}

int add_cell_head(controller* dest, void* value){
	cell* c = malloc(sizeof(*c));
	if (c == nullptr) {
		return -1;
	}
	c->value = value;
	c->next = dest->head;
	dest->head = c;
	return 0;
}

#endif

#if 0

int main() {
	while (1) { void *p = malloc(16711568); }
}

#endif
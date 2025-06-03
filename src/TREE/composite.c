#include "component.h"
#include <stdlib.h>
#include <stdbool.h>

// Actual struct definitions (private to this file)
struct component {
    component_operation_fn operation;
    // Other private members...
    bool is_composite;
    char name[32];
};

struct composite {
    struct component base;  // Inheritance simulation
    component_t *children[10];
    size_t child_count;
};

// Private helper functions
static void default_operation(component_t *self) {
    // Implementation...
}

// Public interface implementation
component_t* component_create(void) {
    component_t *c = malloc(sizeof(*c));
    if (c) {
        c->operation = default_operation;
        c->is_composite = false;
        c->name[0] = '\0';
    }
    return c;
}

void component_destroy(component_t *self) {
    free(self);
}

void component_operate(component_t *self) {
    if (self && self->operation) {
        self->operation(self);
    }
}

// Composite implementation
composite_t* composite_create(void) {
    composite_t *comp = malloc(sizeof(*comp));
    if (comp) {
        comp->base.operation = default_operation;
        comp->base.is_composite = true;
        comp->child_count = 0;
    }
    return comp;
}

void composite_add(composite_t *comp, component_t *child) {
    if (comp && child && comp->child_count < 10) {
        comp->children[comp->child_count++] = child;
    }
}


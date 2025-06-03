#ifndef COMPOSITE_H
#define COMPOSITE_H

//The GoF (Gang of Four) Composite Design Pattern 

// Forward declare opaque pointer types
typedef struct component component_t;
typedef struct composite composite_t;

// Function pointer types for public interface
typedef void (*component_operation_fn)(component_t *self);
typedef void (*component_add_fn)(component_t *self, component_t *child);

// Public interface functions
component_t* component_create(void);

void component_destroy(component_t *self);

void component_operate(component_t *self);

// Composite-specific interface
composite_t* composite_create(void);

void composite_add(composite_t *comp, component_t *child);

#endif

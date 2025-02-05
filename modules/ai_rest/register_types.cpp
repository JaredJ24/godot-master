#include "register_types.h"
#include "core/class_db.h"
#include "ai_rest.h"

void initialize_ai_rest_module() {
     // Register your AIRest class so it becomes available in GDScript.
     ClassDB::register_class<AIRest>();
}

void uninitialize_ai_rest_module() {
    // Cleanup if necessary.
}
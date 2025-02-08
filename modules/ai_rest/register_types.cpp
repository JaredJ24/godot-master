#include "register_types.h"

#include "core/object/class_db.h"
#include "ai_rest.h"

void initialize_ai_rest_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
    ClassDB::register_class<AIRest>();
}

void uninitialize_ai_rest_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}
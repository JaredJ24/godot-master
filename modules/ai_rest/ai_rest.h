#ifndef AI_REST_H
#define AI_REST_H

#include "core/object/ref_counted.h"

class AIRest : public RefCounted {
    GDCLASS(AIRest, RefCounted);

protected:
    static void _bind_methods();

public:
    String request_api(const String &url, const Dictionary &headers, const uint8_t *body, const int body_size);
    String request_chatgpt(const String &api_key, const Array &messages);
    String request_stable_diffusion(const String &api_key, const String &prompt);
    String request_elevenlabs(const String &api_key, const String &text, const String &voice_id);
    
    AIRest();
};

#endif // AI_REST_H

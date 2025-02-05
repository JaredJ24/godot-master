#ifndef AI_REST_H
#define AI_REST_H

#include "core/referenc.h"
#include "core/array.h"

class AIRest : public Reference {
    GDCLASS(AIRest, Reference);

protected:
    static void _bind_methods();

public:
    // Constructor.
    AIRest();

    // Example method: perform a REST request (synchronously for now)
    String request_api(const String &url, const Dictionary &headers, const String &body);

    // You might add more methods for each API, e.g.:
    // String request_chatgpt(const String &json_payload);
    // String request_stable_diffusion(const String &json_payload);
    // String request_elevenlabs(const String &json_payload);
};

#endif // AI_REST_H

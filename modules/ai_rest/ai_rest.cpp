#include "ai_rest.h"
#include "core/io/http_client.h"
#include "core/io/json.h"

String AIRest::request_api(const String &url, const Dictionary &headers, const uint8_t *body, const int body_size) {
    /*Error err = Error::OK;
    Ref<HTTPClient> http;
    http = HTTPClient::create();

    err = http->connect_to_host("api.example.com", 80);
    if (err != Error::OK) return "Connection error";

    while (http->get_status() == HTTPClient::STATUS_CONNECTING || 
           http->get_status() == HTTPClient::STATUS_RESOLVING) {
        http->poll();
        OS::get_singleton()->delay_usec(1000);
    }

    if (http->get_status() != HTTPClient::STATUS_CONNECTED) {
        return "Connection failed";
    }

    Vector<String> header_list;
    for (const Variant *key = headers.next(nullptr); key; key = headers.next(key)) {
        header_list.push_back(String(*key) + ": " + String(headers[*key]));
    }
   
    // Make request
    err = http->request(HTTPClient::METHOD_POST, url, header_list, body, body_size);
    if (err != Error::OK) return "Request failed";

    // Wait for response
    while (http->get_status() == HTTPClient::STATUS_REQUESTING) {
        http->poll();
        OS::get_singleton()->delay_usec(1000);
    }

    // Read response
    String response;
    if (http->has_response()) {
        Vector<uint8_t> body_buffer;
        while (http->get_status() == HTTPClient::STATUS_BODY) {
            http->poll();
            Vector<uint8_t> chunk = http->read_response_body_chunk();
            if (chunk.size() == 0) {
                OS::get_singleton()->delay_usec(1000);
            } else {
                body_buffer.append_array(chunk);
            }
        }
        response.parse_utf8((const char *)body_buffer.ptr(), body_buffer.size());
    }*/

    String response = "Hi";
    return response;
}

String AIRest::request_chatgpt(const String &api_key, const Array &messages) {
    Dictionary headers;
    headers["Authorization"] = "Bearer " + api_key;
    headers["Content-Type"] = "application/json";

    Dictionary data;
    data["model"] = "gpt-4o-mini";
    data["messages"] = messages;

    String json_body = JSON::stringify(data);
    auto utf8_data = json_body.utf8();
    int body_size = json_body.utf8().size();
    const uint8_t *p_body = reinterpret_cast<const uint8_t*>(utf8_data.ptr());
    return request_api("https://api.openai.com/v1/chat/completions", headers, p_body, body_size);
}

/*String AIRest::request_stable_diffusion(const String &api_key, const String &prompt) {
    Dictionary headers;
    headers["Authorization"] = "Bearer " + api_key;
    headers["Content-Type"] = "application/json";

    Dictionary data;
    data["prompt"] = prompt;
    data["n"] = 1;
    data["size"] = "1024x1024";

    String json_body = JSON::stringify(data);
    int body_size = json_body.utf8().size();
    return request_api("https://api.stability.ai/v1/generation/stable-diffusion-xl-1024-v1-0/text-to-image", headers, json_body, body_size);
}

String AIRest::request_elevenlabs(const String &api_key, const String &text, const String &voice_id) {
    Dictionary headers;
    headers["xi-api-key"] = api_key;
    headers["Content-Type"] = "application/json";

    Dictionary data;
    data["text"] = text;
    data["model_id"] = "eleven_monolingual_v1";
    data["voice_settings"] = Dictionary();

    String json_body = JSON::stringify(data);
    int body_size = json_body.utf8().size();
    return request_api("https://api.elevenlabs.io/v1/text-to-speech/" + voice_id, headers, json_body, body_size);
}*/

AIRest::AIRest() {
    // Constructor implementation
}

void AIRest::_bind_methods() {
    ClassDB::bind_method(D_METHOD("request_api", "url", "headers", "body"), &AIRest::request_api);
    ClassDB::bind_method(D_METHOD("request_chatgpt", "api_key", "messages"), &AIRest::request_chatgpt);
    ClassDB::bind_method(D_METHOD("request_stable_diffusion", "api_key", "prompt"), &AIRest::request_stable_diffusion);
    ClassDB::bind_method(D_METHOD("request_elevenlabs", "api_key", "text", "voice_id"), &AIRest::request_elevenlabs);
}
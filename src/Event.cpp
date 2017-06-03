
#include <BwString.h>
#include <Event.h>
#include <BWAPI/Event.h>

BwString* Event_getText(Event* self) {
    const std::string* text = reinterpret_cast<std::string*>(self->text);
    return BwString_new(text->c_str(), static_cast<int>(text->length()));
}

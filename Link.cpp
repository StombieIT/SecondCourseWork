#include "Link.h"

Link::Link(xml_node node) : TextNode(node.child_value()) {
}

bool Link::operator==(const Link& link) const {
    return textContent == link.textContent;
}

Link::Link() : TextNode("") {
}
#include "Link.h"

Link::Link(xml_node node) : TextNode(node.child_value()) {
}

Link::Link() : TextNode("") {
}
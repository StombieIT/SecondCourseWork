#include "Description.h"

Description::Description(xml_node node) : TextNode::TextNode(node.child_value()) {
}

Description::Description() : TextNode::TextNode("") {
}
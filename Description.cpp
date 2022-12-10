#include "Description.h"



Description::Description(xml_node node) : TextNode::TextNode(node.child_value()) {
}

bool Description::operator==(const Description& description) const {
	return textContent == description.textContent;
}

Description::Description() : TextNode::TextNode("") {
}
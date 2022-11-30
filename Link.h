#pragma once
#include "TextNode.h"

class Link : public TextNode {
public:
	Link();
	Link(xml_node node);
	bool operator==(const Link& link) const;
};
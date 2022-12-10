#pragma once
#include "TextNode.h"

using pugi::xml_node;

class Link : public TextNode {
public:
	Link();
	Link(xml_node node);
	bool operator==(const Link& link) const;
};
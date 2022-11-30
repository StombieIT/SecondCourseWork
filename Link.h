#pragma once
#include "TextNode.h"

class Link : public TextNode {
public:
	Link();
	Link(xml_node node);
};